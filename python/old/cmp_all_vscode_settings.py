#!/usr/bin/env python3.6

import sys
import os
import subprocess

paths = [r'C:\Dev\navigation\.vscode\settings.json',
         r'C:\Dev\stingray-navigation-samples\.vscode\settings.json']

araxis_compare = r'C:\Program Files\Araxis\Araxis Merge\Compare.exe'

if len(paths) == 2:
    cmd = [araxis_compare, '/closeIfNoChanges', '/2', paths[0], paths[1]]
    print(' '.join(cmd))
    subprocess.run(cmd)
    exit()

try:
    src = sys.argv[1]
except IndexError:
    exit('cmd_all_vscode_settings.py requires 1 argument: the absolute path to the src file')

for p in paths:
    if p == src or not os.path.isfile(p):
        continue
    cmd = [araxis_compare, '/closeIfNoChanges', '/2', src, p]
    print(' '.join(cmd))
    subprocess.run(cmd)
