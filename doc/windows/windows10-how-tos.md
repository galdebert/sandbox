# how to pin a shortcut to a file in the taskbar

- right-click -> new -> shortcut
- shortcut tab -> Target: `myexe.exe myparams`
- for vscode, Target: `C:\Windows\explorer.exe vscode://file/D:/dev/galdebert/sandbox`
- shortcut tab -> Change Icon... -> Look for icons in this file: `%systemroot%\system32\imageres.dll` or in your own .ico files, ex: http://www.iconarchive.com/show/soft-scraps-icons-by-hopstarter.3.html
- right-click on the shortcut -> Pin to taskbar
- Later you can edit the taskbar shortcuts by opening C:\Users\galde\AppData\Roaming\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar
