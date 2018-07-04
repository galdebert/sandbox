# vscode, typescript and node


# Configure Build & Test

with typescript, the `package.json` has these scripts:

```
{
  ...
  "scripts": {
    "build": "tsc",
    "start": "tsc && node out/main.js",
    "test": "tsc && node out/main.js",
  },
  ...
}
```

vscode automatically read the `package.json` and populate the `Run Tasks` vscode command:

    >Tasks: Run Task

will show:

    tsc: build - tsconfig
    tsc: watch - tsconfig
    npm: build
    npm: test
    npm: start
    npm: install


running the vscode commands:

    >Tasks: Configure Default Build Task
        tsc: build

    >Tasks: Configure Default Test Task
        npm: test

creates the following `tasks.json`:

```json
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  // for the documentation about the tasks.json format
  "version": "2.0.0",
  "tasks": [
    {
      "type": "typescript",
      "tsconfig": "tsconfig.json",
      "problemMatcher": [
        "$tsc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    },
    {
      "type": "npm",
      "script": "test",
      "group": {
        "kind": "test",
        "isDefault": true
      }
    }
  ]
}
```

# Configure Debug

The first time debug is ran, it will create this `launch.json` file:

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "type": "node",
      "request": "launch",
      "name": "Launch Program",
      "program": "${workspaceFolder}\\out\\main.js",
      "outFiles": [
        "${workspaceFolder}/**/*.js"
      ]
    }
  ]
}
```


# Execute Build, Test, Debug


## Using npm, on the command line

- build: `npm run build`
- test: `npm test` or `npm run test`
- start: `npm start` or `npm run start`


## From vscode

### Build

    >Tasks: Run Build Task

or the shortcut `Ctrl+Shift+B`

### Test

    >Tasks: Run Test Task

There is no shortcut for the test task.

### Debug

- `F5`: run the current launch configuration with debugging
- `Ctrl+F5`: run the current launch configuration without debugging

`launch.json` + `debug panel` (`F5` or `Ctrl+F5`) is a much better way to run programs than `tasks.json`

