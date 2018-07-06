
# How to avoid always entering git credentials

https://git-scm.com/docs/gitcredentials

On Linux, let's use `git config --global credential.helper cache`

It's the only solution taht works cross clients on Linux

app       |core.askpass|github token|credential.helper cache|
----------|------------|------------|-----------------------|
cmdline   |    yes     |    no      |    yes                |
vscode    |    no      |    no      |    yes                |
smartgit  |    no      |    yes     |    yes                |

On windows, `git config --global credential.helper manager` is an option.

# store passwords in plain **plain text**, very bad !
```
git config --global credential.helper store
```

# store passwords in memory for some time

```
git config --global credential.helper cache
```

# Store passwords using an external password manager

## Windows
```
git config --global credential.helper manager
```

## OSX
```
git config --global credential.helper osxkeychain
or
git config --global credential.helper libsecret
```

# askpass on kubuntu

Not using a credential manager but the askpass mechanism instead
```
git config --global --unset credential.helper
git config --global core.askpass /usr/bin/ksshaskpass
git config --global credential.username galdebert
```

Note: `gnome-keyring` and `libsecret` linux "credential managers" did not work for me.


# WHEN YOU HAVE DIFFERENT USERS FOR DIFFERENT REPOS

You can configure an individual repo to use a specific user / email address which overrides the global configuration. From the root of the repo, run
```
git config user.name "Your Name Here"
git config user.email your@email.com
git config credential.username your_github_username
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


