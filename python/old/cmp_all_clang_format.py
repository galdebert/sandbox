#!/usr/bin/env python3

import sys
import os
import subprocess

paths = [r'C:\Dev\stingray\runtime\plugins\gwnav_plugin\_clang-format',
         r'C:\Dev\stingray\runtime\_clang-format',
         r'C:\Dev\stingray-navigation-samples\nav_test_plugin\src\_clang-format',
         r'C:\Dev\navigation\_clang-format']

araxis_compare = r'C:\Program Files\Araxis\Araxis Merge\Compare.exe'

try:
    src = sys.argv[1]
except IndexError:
    exit('cmd_all_clang_format.py requires 1 argument: the absolute path to the src file')

for p in paths:
    if p == src or not os.path.isfile(p):
        continue
    cmd = [araxis_compare, '/closeIfNoChanges', '/2', src, p]
    print(' '.join(cmd))
    subprocess.run(cmd)
