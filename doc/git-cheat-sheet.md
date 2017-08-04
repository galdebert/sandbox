
## Create a patch for a list a commits

https://stackoverflow.com/questions/2217452/in-git-how-do-i-create-a-single-patch-for-the-last-2-revisions

#### Produce 2 patch files:
```git format-patch HEAD~2..HEAD```

#### Produce 1 patch files without the format-patch's per-commit metadata:
```git diff HEAD~2..HEAD > my-patch.diff```

#### Produce 1 patch files with the format-patch's per-commit metadata, but applying the patch will create 2 commits.
```git format-patch HEAD~2..HEAD --stdout > moveonnavmeshfix.patch```

#### it's often easier to use merge --squash
```
git checkout my-destination-branch
git merge --squash my-branch-with-tons-of-little-commits
git commit
```
