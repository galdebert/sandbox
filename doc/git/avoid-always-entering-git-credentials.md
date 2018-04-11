
# How to avoid always entering git credentials

https://git-scm.com/docs/gitcredentials


# store passwords in plain **plain text**, very bad !
```
git config --global credential.helper store
```

# store passwords in memory for some time
```
git config --global credential.helper cache
```

# Store passwords using the system

## Windows
```
git config --global credential.helper manager
```

## OSX
```
git config --global credential.helper osxkeychain
```
or
```
git config --global credential.helper libsecret
```


## Linux

Not a credential manager, 
```
git config --global --unset credential.helper
git config --global core.askpass /usr/bin/ksshaskpass
git config --global credential.username galdebert
```


Note: `gnome-keyring` and `libsecret` did not work


# WHEN YOU HAVE DIFFERENT USERS FOR DIFFERENT REPOS

You can configure an individual repo to use a specific user / email address which overrides the global configuration. From the root of the repo, run
```
git config user.name "Your Name Here"
git config user.email your@email.com
```

to verify what user a given repos use:
```
git config --get user.email
```

## With the Git-Credential-Manager-for-Windows

Make Git-Credential-Manager-for-Windows use credentials per repo
```
git config --global credential.httpusepath true
```

Make Git-Credential-Manager-for-Windows output logs
```
git config --global credential.writelog true
```

https://github.com/Microsoft/Git-Credential-Manager-for-Windows#notice-experiencing-github-pushfetch-problems



