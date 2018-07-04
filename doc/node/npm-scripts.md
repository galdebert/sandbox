# npm scripts

https://medium.com/@jonjam/writing-npm-scripts-using-typescript-a09b8712dc6b

If you are using gulp or grunt, you should check out this blog post about the reasons why to move to npm scripts: https://medium.freecodecamp.org/why-i-left-gulp-and-grunt-for-npm-scripts-3d6853dd22b8


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


vscode automatically detect package.json scripts and can run them with

    >Tasks: Run Task

will show:

    tsc: build - tsconfig
    tsc: watch - tsconfig
    npm: build
    npm: test
    npm: start
    npm: install

