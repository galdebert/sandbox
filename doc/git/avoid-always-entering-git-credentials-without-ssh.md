# How to avoid always entering git credentials without ssh

https://git-scm.com/docs/gitcredentials

On Linux, let's use `git config --global credential.helper cache`

It's the only solution that works cross clients on Linux

app       |core.askpass|github token|credential.helper cache|
----------|------------|------------|-----------------------|
cmdline   |    yes     |    no      | yes, but not windows  |
vscode    |    no      |    no      | yes, but not windows  |
smartgit  |    no      |    yes     | yes, but not windows  |

On windows, `git config --global credential.helper manager` is a very good option.
Except when github is very slow to authenticate, then it's mess:
- tons of authentication popups
- tons of github personal token created


# To avoid typing the username

```
[credential "https://example.com"]
    username = galdebert
```


# `store`: store passwords in plain **plain text**, very bad !

```
git config --global credential.helper store
```
on windows the file is 


# `cache`: store passwords in memory for some time

`credential.helper cache` does not work on windows !!!!
```
git config --global credential.helper cache
```

# `.netrc`

on windows it's located at `%HOME%\_netrc`

it's a text file witht he following content:
```
machine git.heroku.com
  login galdebert@gmail.com
  password xxxxxxxxxxxxxxxxx
```

A common trap with with netrc support on Windows is that git will bypass using it if an origin https url specifies a user name.

For example, if your .git/config file contains:
```
[remote "origin"]
  fetch = +refs/heads/*:refs/remotes/origin/*
  url = https://bob@code.google.com/p/my-project/
```

Git will not resolve your credentials via _netrc, to fix this remove your username, like so:
```
[remote "origin"]
  fetch = +refs/heads/*:refs/remotes/origin/*
  url = https://code.google.com/p/my-project/
```



# `manager` Store passwords using an external password manager

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

You can configure a repo to use a specific
- user.name
- user.email
- credential.username
which overrides the global configuration

**From the root of the repo**, run:

```
git config user.name "Your Name Here"
git config user.email your@email.com
git config credential.username your_github_username
```

to verify what user a given repo uses:
```
git config --get user.email
```

## With the Git-Credential-Manager-for-Windows

Make Git-Credential-Manager-for-Windows use credentials per repo
```
git config --global credential.httpusepath true
```

other Git-Credential-Manager-for-Windows configuration:

https://github.com/Microsoft/Git-Credential-Manager-for-Windows/blob/master/Docs/Configuration.md

https://github.com/Microsoft/Git-Credential-Manager-for-Windows#notice-experiencing-github-pushfetch-problems



