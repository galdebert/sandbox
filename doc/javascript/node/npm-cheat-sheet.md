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

This is one seems to actually list all versions
```
npm view mypackage versions
```

This is one misses all '4.0.0-rc.X'
```
npm show mypackage@* version
```

actually, `info`, `show`, `view`, `v` are the same command


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

