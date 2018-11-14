# npm-yarn-cheat-sheet

# yarn add and the caret on windows

on windows:
```
yarn add react-dnd@^3.0.2
```
results in "react-dnd": "3.0.2" in the package.json

use instead:
```
yarn add "react-dnd@^3.0.2"
```
results in "react-dnd": "^3.0.2" in the package.json

# yarn check dependencies

```
yarn check
```

# yarn check available updates, install them 

```
yarn outdated
```

`yarn upgrade` changes your `yarn-lock.json`, but does NOT change your `package.json`

```
yarn upgrade
yarn upgrade --latest
```


# npm list top level dependencies

```
npm list --depth 0
```

# npm get help on a command (ex: list)
```
npm help list
```

# npm view dependencies of a package

```
npm info mypackage@X.Y.Z dependencies
```

# npm view available versions online

This is one seems to actually list all versions
```
npm info mypackage versions
```

# npm check available updates, install them 

```
npm outdated
```
gives you `current`, `wanted`, and `latest` versions.

To install the `wanted` version:
```
npm update yourpackage
```

To install the `latest` version:
```
npm install yourpackage
```


