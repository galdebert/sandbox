# npm-yarn-cheat-sheet

- `yarn outdated`: lists available updates, install them 
- `yarn why mypackage`: tells what package has mypackage as a dependency
- `yarn upgrade`: changes your `yarn-lock.json`, but does NOT change your `package.json`
- `yarn upgrade --latest`: same as the upgrade command, but ignores the version range specified in package.json. Instead, the version specified by the latest tag will be used (potentially upgrading the packages across major versions).
The package.json file will be updated to reflect the latest version range.
- `yarn check`: checks dependencies
- `yarn info mypackage versions`: views mypackage available versions online
- `yarn info mypackage version`: views mypackage latest version online
- `yarn list mypackage`: views mypackage version installed locally
- `yarn list --depth=0`: lists packages installed locally
- `yarn global list --depth=0`: lists packages installed globally

### Where does yarn store global packages

https://github.com/yarnpkg/yarn/issues/2049
- `%LOCALAPPDATA%/Yarn/config/global` on Windows
- `~/.config/yarn/global` on OSX and non-root Linux
- `/usr/local/share/.config/yarn/global` on Linux if logged in as root


### mind the ^ on windows

- on windows: `yarn add react-dnd@^3.0.2` results in "react-dnd": "3.0.2" in the package.json
- use instead: `yarn add "react-dnd@^3.0.2"` results in "react-dnd": "^3.0.2" in the package.json

### yarn install, NODE_ENV, devDependencies

- `yarn install` if NODE_ENV = production, yarn will NOT install devDependencies
- `yarn install --production=true` ignore NODE_ENV, yarn will NOT install devDependencies
- `yarn install --production=false` ignore NODE_ENV, yarn WILL install devDependencies

### yarn run

- `yarn run env`: lists environment variables available to the scripts at runtime
- `yarn run [script] [<arg>]`: passes additional argumentsarguments
- [script] can also be any locally installed executable that is inside `node_modules/.bin/`

```json
"scripts": {
  "server": "node server.js"
}
```
`yarn run server --port=1337` runs `server.js --port=1337`

### where to find the what has been yarn linked

- linux: ~/.config/yarn/link
- windows: C:\Users\<userName>\AppData\Local\Yarn\Data\link


