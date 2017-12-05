#!/usr/bin/env python3

import os
import subprocess

compare_exe = r'C:\Program Files\Araxis\Araxis Merge\Compare.exe'

def compare(a, b):
    cmd = [compare_exe, '/closeIfNoChanges', '/2', a, b]
    print(' '.join(cmd))
    subprocess.run(cmd)

def compare1toN(src, dests):
    for p in dests:
        if p == src or not os.path.isfile(p):
            continue
        compare(src, p)
