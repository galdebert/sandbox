# How to upgrade the version of git used in cmder

in cmder, check where is where is git:
```
which git
/c/Dev/cmder/vendor/git-for-windows/bin/git
```

download the portable version of git
```
https://git-scm.com/download/win
```

double-click on `PortableGit-<versionstring>.7z.exe`, and set the desired target directory to `C:/Dev/cmder/vendor/git-for-windows`

*NOTE*: if you decide to unpack the archive using 7-Zip manually, you must
run the `post-install.bat` script. Git will not run correctly
otherwise.
