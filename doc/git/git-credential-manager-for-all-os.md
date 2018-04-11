
https://stackoverflow.com/questions/5343068/is-there-a-way-to-skip-password-typing-when-using-https-on-github

store passwords in plain **plain text**, very bad !
```
git config --global credential.helper store
```

store passwords in memory for some time
```
git config --global credential.helper cache
```

**For git 2.11+ on OSX and linux**, use git's built in credential store:
```
git config --global credential.helper libsecret
```

**On Windows**, store passwords using the windows native system
```
git config --global credential.helper manager
```

**Before git 2.11, on OSX and linux**:

OSX, store passwords using the OSX native system
```
git config --global credential.helper osxkeychain
```

linux<br>
install gnome-keyring<br>
```
git config --global credential.helper gnome-keyring ??????????
```