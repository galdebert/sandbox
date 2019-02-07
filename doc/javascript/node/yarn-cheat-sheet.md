# npm-yarn-cheat-sheet

- `yarn outdated`: list available updates, install them 
- `yarn why mypackage`: tells what package has mypackage as a dependency
- `yarn upgrade` changes your `yarn-lock.json`, but does NOT change your `package.json`
- `yarn upgrade --latest`
- `yarn check`: check dependencies
- `yarn info mypackage versions` view mypackage available versions online
- `yarn info mypackage version` view mypackage latest version online
- `yarn list --depth=0` list packages installed locally
- `yarn global list --depth=0` list packages installed globally


### mind the ^ on windows

- on windows: `yarn add react-dnd@^3.0.2` results in "react-dnd": "3.0.2" in the package.json
- use instead: `yarn add "react-dnd@^3.0.2"` results in "react-dnd": "^3.0.2" in the package.json

### yarn install, NODE_ENV, devDependencies

- `yarn install` if NODE_ENV = production, yarn will NOT install devDependencies
- `yarn install --production=true` ignore NODE_ENV, yarn will NOT install devDependencies
- `yarn install --production=false` ignore NODE_ENV, yarn WILL install devDependencies

### yarn run

- `yarn run env` list environment variables available to the scripts at runtime
- `yarn run [script] [<arg>]` pass additional argumentsarguments
- [script] can also be any locally installed executable that is inside `node_modules/.bin/`

```json
"scripts": {
  "server": "node server.js"
}
```
`yarn run server --port=1337` runs `server.js --port=1337`