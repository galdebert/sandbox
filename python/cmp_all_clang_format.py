#!/usr/bin/env python3.6

import sys
import os
import subprocess

paths = [r'C:\Dev\stingray\runtime\plugins\gwnav_plugin\_clang-format',
         r'C:\Dev\stingray\runtime\_clang-format',
         r'C:\Dev\stingray-navigation-samples\gwnavtest_plugin\gwnavtest\_clang-format',
         r'C:\Dev\navigation\_clang-format',
         r'C:\Dev\hello-pie-workspace\_clang-format']

araxis_compare = r'C:\Program Files\Araxis\Araxis Merge\Compare.exe'

src = sys.argv[1] if len(sys.argv) >= 2 else paths[0]

for p in paths:
    if p == src or not os.path.isfile(p):
        continue
    cmd = [araxis_compare, '/closeIfNoChanges', '/2', src, p]
    print(' '.join(cmd))
    subprocess.run(cmd)
