# npm-cheat-sheet

## yarn

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

## check dependencies

```
yarn check
```

## list top level dependencies

```
npm list --depth 0
```

## get help on a command (ex: list)
```
npm help list
```

## view dependencies of a package

```
npm info mypackage@X.Y.Z dependencies
```

## view available versions online

This is one seems to actually list all versions
```
npm info mypackage versions
```

## check available updates, install them 

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


