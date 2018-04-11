
https://stackoverflow.com/questions/5343068/is-there-a-way-to-skip-password-typing-when-using-https-on-github

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

##  Linux
install gnome-keyring
```
git config --global credential.helper /usr/share/doc/git/contrib/credential/gnome-keyring/git-credential-gnome-keyring
```

# libsecret ??
you may try:<br>
**For git 2.11+ on OSX and linux**, use git's built in credential store:
```
git config --global credential.helper libsecret
```
but this gave me `git: 'credential-libsecret' is not a git command.`


