

You can configure an individual repo to use a specific user / email address which overrides the global configuration. From the root of the repo, run
git config user.name "Your Name Here"
git config user.email your@email.com


to verify what user a given repos uses:
git config --get user.email


Make Git-Credential-Manager-for-Windows use credentials per repo
git config --global credential.httpusepath true

Make Git-Credential-Manager-for-Windows output logs
git config --global credential.writelog true


https://github.com/Microsoft/Git-Credential-Manager-for-Windows#notice-experiencing-github-pushfetch-problems



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
