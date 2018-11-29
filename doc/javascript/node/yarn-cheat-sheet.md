# npm-yarn-cheat-sheet

- `yarn outdated`: list available updates, install them 
- `yarn upgrade` changes your `yarn-lock.json`, but does NOT change your `package.json`
- `yarn upgrade --latest`
- `yarn check`: check dependencies

### mind the ^ on windows
- on windows: `yarn add react-dnd@^3.0.2` results in "react-dnd": "3.0.2" in the package.json
- use instead: `yarn add "react-dnd@^3.0.2"` results in "react-dnd": "^3.0.2" in the package.json

### yarn install, NODE_ENV, devDependencies
- `yarn install` if NODE_ENV = production, yarn will NOT install devDependencies
- `yarn install --production=true` ignore NODE_ENV, yarn will NOT install devDependencies
- `yarn install --production=false` ignore NODE_ENV, yarn WILL install devDependencies

### yarn run

- `yarn run env`

- yarn run [script] [<arg>]
  - You can pass additional arguments to your script by passing them after the script name, ex `yarn run test -o --watch`
  - [script] can also be any locally installed executable that is inside node_modules/.bin/.

