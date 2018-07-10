# vscode, typescript and node


# Configure Build, Test, Debug

## Configure npm scripts

When using typescript, we can modify `package.json` with:

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

## Configure vscode tasks

vscode automatically read the `package.json` and populate the `Run Tasks` vscode command:

    >Tasks: Run Task

will show:

    tsc: build - tsconfig.json
    tsc: watch - tsconfig.json
    npm: build
    npm: test
    npm: start
    npm: install


running the vscode commands:

    >Tasks: Configure Default Build Task
        tsc: build

    >Tasks: Configure Default Test Task
        npm: test

    >Tasks: Configure Task
        tsc: build

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
    },
    {
      "type": "typescript",
      "tsconfig": "tsconfig.json",
      "option": "watch",
      "problemMatcher": [
        "$tsc-watch"
      ]
    }
  ]
}
```

# Configure vscode Debug 

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



# Run Build, Test, Debug

## From the command line, using npm

- build: `npm run build`
- test: `npm test` or `npm run test`
- start: `npm start` or `npm run start`

## From vscode - Build

    >Tasks: Run Build Task

or the shortcut `Ctrl+Shift+B`

## From vscode - Test

    >Tasks: Run Test Task

There is no shortcut for the test task.

## From vscode - Debug

- `F5`: run the current launch configuration with debugging
- `Ctrl+F5`: run the current launch configuration without debugging

`launch.json` + `debug panel` (`F5` or `Ctrl+F5`) is a much better way to run programs than `tasks.json`

Be careful, by default `F5` and `Ctrl+F5` don't build the app using tsc !

The solution is to use `"preLaunchTask": "tsc: build - tsconfig.json"`

`tsc: build - tsconfig.json` is the default label of the task:
```json
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
    }
```

You can add `"label" : "build"` in the task and then use `"preLaunchTask": "build"` instead.