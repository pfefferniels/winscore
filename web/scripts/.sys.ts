import { readFileSync } from 'node:fs';
import { codeName, editWords, initSync } from '../src/wasm/score_web.js';
import { systemPromptFor } from '../src/ai-models';
initSync({ module: readFileSync(process.env.SCORE_WASM!) });
const text = systemPromptFor({ codes: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 17, 18].map((code) => ({ code, name: codeName(code) ?? '' })), words: JSON.parse(editWords()) });
const at = text.indexOf('# Settings by code');
console.log(text.slice(at, text.indexOf('# Edit words')).split('\n').filter((l) => /^Code (4|8|5|17),|^Code/.test(l) || l.length).slice(0, 400).join('\n'));
console.log('LENGTH', text.length);
