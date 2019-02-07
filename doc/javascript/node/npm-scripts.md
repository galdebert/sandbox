# npm scripts

https://medium.com/@jonjam/writing-npm-scripts-using-typescript-a09b8712dc6b

package.json
```
{
  "scripts": {
    "build": "tsc",
    "start": "tsc && node out/main.js",
    "test": "tsc && node out/main.js",
  },
```

on the command line, use
- to build: `npm run build`
- to test: `npm test` or `npm run test`
- to start: `npm start` or `npm run start`


https://docs.npmjs.com/cli/run-script


# to pass parameters to npm script

- `npm run <command> [-- <args>]`
ex:

```json
"scripts": {
  "server": "node server.js"
}
```

`npm run server -- --port=1337`

runs:

`node server.js --port=1337`

# with vscode

vscode automatically detect package.json scripts and can run them with

    >Tasks: Run Task

will show:

    tsc: build - tsconfig
    tsc: watch - tsconfig
    npm: build
    npm: test
    npm: start
    npm: install

