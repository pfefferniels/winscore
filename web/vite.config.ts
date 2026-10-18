import { defineConfig } from 'vite';
import { aiProxy } from './ai-proxy.ts';

export default defineConfig({
  base: './',
  build: { target: 'es2022' },
  server: { port: 5173 },
  preview: { port: 4173 },
  plugins: [aiProxy()],
});
