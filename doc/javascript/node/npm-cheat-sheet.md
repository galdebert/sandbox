# npm-cheat-sheet

## list only top level dependencies
```
npm list -g --depth 0
npm list --depth 0
```

## get help on a command, ex list
```
npm help list
```

## list global modules installed on my machine
```
npm ls -g --depth 0
```
There is a `--local-only`, but does not seem necessary

## view available versions online

```
npm view create-react-app versions

npm show redux-orm@* version
```

## check available updates, install them (here globally)

```
npm outdated -g
```
gives you `current`, `wanted`, and `latest` versions.

To install the `wanted` version:
```
npm update -g yourpackage
```

To install the `latest` version:
```
npm install -g yourpackage
```

