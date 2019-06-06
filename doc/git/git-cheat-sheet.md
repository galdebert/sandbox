# git commit all

including untracked files
```
git add -A && git commit -m mymessage
```


# Normalize EOL to what git clone gives you

MAKE SURE ALL YOUR WIP IS COMMIT, and then:
```
git rm --cached -r .
git reset --hard
```

# smartgit: check diff of 2 previous versions of a file

- use Log in smartgit
- select 2 commits using CTRL
- select a file on the right
=> will show the diff of the file versions at those 2 commits 

# smartgit: chen merging a file, check the each side difference with the common base

TODO

# Create a patch for a list a commits

https://stackoverflow.com/questions/2217452/in-git-how-do-i-create-a-single-patch-for-the-last-2-revisions

## Produce 2 patch files:
`git format-patch HEAD~2..HEAD`

## Produce 1 patch files without the format-patch's per-commit metadata:
`git diff HEAD~2..HEAD > my-patch.diff`

## Produce 1 patch files with the format-patch's per-commit metadata, but applying the patch will create 2 commits.
`git format-patch HEAD~2..HEAD --stdout > moveonnavmeshfix.patch`

## it's often easier to use merge --squash
```
git checkout my-destination-branch
git merge --squash my-branch-with-tons-of-little-commits
git commit
```
or
```
git merge --squash my-commit-id
```
