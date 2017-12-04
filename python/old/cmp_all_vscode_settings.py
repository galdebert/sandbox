#!/usr/bin/env python3.6

import sys
import araxis_cmp

paths = [r'C:\Dev\navigation\.vscode\settings.json',
         r'C:\Dev\stingray-navigation-samples\.vscode\settings.json']

araxis_compare = r'C:\Program Files\Araxis\Araxis Merge\Compare.exe'

if len(paths) == 2:
    araxis_cmp.compare(paths[0], paths[1])
    exit()

try:
    src = sys.argv[1]
except IndexError:
    exit('cmd_all_vscode_settings.py requires 1 argument: the absolute path to the src file')

araxis_cmp.compare1toN(src, paths)
