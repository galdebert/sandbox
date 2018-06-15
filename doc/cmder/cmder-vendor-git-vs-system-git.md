# cmder should use your "system" git 

https://github.com/cmderdev/cmder

Cmder is by default shipped with a vendored Git installation. On each instance of launching Cmder, an attempt is made to locate any other user provided Git binaries. Upon finding a git.exe binary, Cmder further compares its version against the vendored one by executing it. The vendored git.exe binary is only used when it is more recent than the user-installed one.

You may use your favorite version of Git by including its path in the %PATH% enviroment variable. Moreover, the Mini edition of Cmder (found on the downloads page) excludes any vendored Git binaries.

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

