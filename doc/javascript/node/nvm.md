#nvm for windows

https://github.com/coreybutler/nvm-windows

DO NOT USE! The installation of npm 6.1 (node >= 10.0) just does not work.

# install nvm for linux

```
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | bash
```

check installation
```
command -v nvm
```

# Install node versions

```
nvm install node             latest version 9.11.1
nvm install --lts            latest lts 8.11.1
nvm install --lts=boron      boron lts 6.14.1
nvm install X.Y              install version X.Y
```
install also make the installed version active.


# Use node versions

Use means that in the current shell, `node` will be this version.
```
nvm use node             use latest version 9.11.1
nvm use --lts            use latest lts 8.11.1
nvm use --lts=boron      use boron lts 6.14.1
nvm use X.Y              use install version X.Y
nvm use system           use the system version of node
```

# To change the default node version (used in any new shell)

To set a default Node version to be used in any new shell, use the alias 'default':
```
nvm alias default node    
nvm alias default lts/*
```

# List installed versions

to list the versions installed:
```
guillaume@linux:~$ nvm ls
->      v8.11.1
        v9.11.1
         system
default -> node (-> v9.11.1)
node -> stable (-> v9.11.1) (default)
stable -> 9.11 (-> v9.11.1) (default)
iojs -> N/A (default)
lts/* -> lts/carbon (-> v8.11.1)
lts/argon -> v4.9.1 (-> N/A)
lts/boron -> v6.14.1 (-> N/A)
lts/carbon -> v8.11.1
```

# Run and Exec version of node whatever the version 'in use'

Run a specific version of node
```
nvm run node
nvm run system
nvm run --lts
nvm run X.Y
```

Run any arbitrary command in a subshell with a specific version of node temporarily in use
```
nvm exec 4.2 mayapp.js
```

You can also get the path to the executable to where it was installed:
```
nvm which 5.0
```

# Other commands

### To restore your PATH, you can deactivate nvm:
```
nvm deactivate
```

### uninstall
```
nvm uninstall --lts
```

### If you want to install a new version of Node.js and migrate npm packages from a previous version:
```
nvm install 6 --reinstall-packages-from=5
```

### List available versions online
```
nvm ls-remote
nvm ls-remote --lts
nvm ls-remote --lts=boron
```

### Output the latest version available online
```
nvm version-remote
```
