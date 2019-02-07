# npm-cheat-sheet

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


