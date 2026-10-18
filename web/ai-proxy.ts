// The AI command's models through the dev and preview servers, with the keys
// from the environment (or web/.env.local) so they never reach the page:
//
//   GET  /ai/status           which keys there are: { jev, claude }
//   POST /ai/jev              TypeSafe's System One endpoint (Jev), TYPESAFE_API_KEY
//   *    /ai/anthropic/…      the Claude API, ANTHROPIC_API_KEY
//
// TypeSafe's API refuses requests from web pages of other sites (CORS), so
// the page reaches Jev through here, or through a gateway that allows it.
import { Readable } from 'node:stream';
import type { IncomingMessage, ServerResponse } from 'node:http';
import { loadEnv, type Connect, type Plugin } from 'vite';

const JEV = 'https://api.typesafe.ai/v1/systemone';
const ANTHROPIC = 'https://api.anthropic.com';

/** Request headers passed on to Anthropic; the key is the server's. */
const ANTHROPIC_HEADERS = ['content-type', 'anthropic-version', 'anthropic-beta', 'accept'];

async function body(req: IncomingMessage): Promise<Buffer> {
  const chunks: Buffer[] = [];
  for await (const chunk of req) chunks.push(chunk as Buffer);
  return Buffer.concat(chunks);
}

async function forward(res: ServerResponse, response: Response) {
  res.statusCode = response.status;
  for (const name of ['content-type', 'request-id', 'x-typesafe-request-id', 'retry-after']) {
    const value = response.headers.get(name);
    if (value) res.setHeader(name, value);
  }
  if (!response.body) return res.end();
  Readable.fromWeb(response.body as import('node:stream/web').ReadableStream).pipe(res);
}

function middleware(keys: { jev?: string; claude?: string }): Connect.NextHandleFunction {
  return (req, res, next) => {
    const url = req.url ?? '';
    if (!url.startsWith('/ai/')) return next();
    const fail = (status: number, message: string) => {
      res.statusCode = status;
      res.setHeader('content-type', 'application/json');
      res.end(JSON.stringify({ error: { message } }));
    };
    void (async () => {
      try {
        if (url === '/ai/status') {
          res.setHeader('content-type', 'application/json');
          res.end(JSON.stringify({ jev: Boolean(keys.jev), claude: Boolean(keys.claude) }));
        } else if (url === '/ai/jev' && req.method === 'POST') {
          if (!keys.jev) return fail(401, 'TYPESAFE_API_KEY is not set for the dev server');
          const response = await fetch(JEV, {
            method: 'POST',
            headers: { authorization: `Bearer ${keys.jev}`, 'content-type': 'application/json' },
            body: await body(req),
          });
          await forward(res, response);
        } else if (url.startsWith('/ai/anthropic/')) {
          if (!keys.claude) return fail(401, 'ANTHROPIC_API_KEY is not set for the dev server');
          const headers: Record<string, string> = { 'x-api-key': keys.claude };
          for (const name of ANTHROPIC_HEADERS) {
            const value = req.headers[name];
            if (typeof value === 'string') headers[name] = value;
          }
          const response = await fetch(`${ANTHROPIC}${url.slice('/ai/anthropic'.length)}`, {
            method: req.method,
            headers,
            body: req.method === 'GET' || req.method === 'HEAD' ? undefined : await body(req),
          });
          await forward(res, response);
        } else next();
      } catch (err) {
        fail(502, err instanceof Error ? err.message : String(err));
      }
    })();
  };
}

export function aiProxy(): Plugin {
  let keys: { jev?: string; claude?: string } = {};
  return {
    name: 'winscore-ai-proxy',
    configResolved(config) {
      const env = { ...loadEnv(config.mode, config.envDir || config.root, ''), ...process.env };
      keys = { jev: env.TYPESAFE_API_KEY || undefined, claude: env.ANTHROPIC_API_KEY || undefined };
    },
    configureServer(server) {
      server.middlewares.use(middleware(keys));
    },
    configurePreviewServer(server) {
      server.middlewares.use(middleware(keys));
    },
  };
}
