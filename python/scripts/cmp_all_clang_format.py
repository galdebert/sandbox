#!/usr/bin/env python3

import sys

from . import araxis_cmp # py scripts/cmp_all_clang_format.py
# does when there is no __init__.py in the dir
# py scripts/cmp_all_clang_format.py     KO
# py cmp_all_clang_format.py             KO

#import araxis_cmp
# does work when there is no __init__.py in the dir
# py scripts/cmp_all_clang_format.py

paths = [r'C:\Dev\stingray\runtime\plugins\gwnav_plugin\_clang-format',
         r'C:\Dev\stingray\runtime\_clang-format',
         r'C:\Dev\stingray-navigation-samples\nav_test_plugin\src\_clang-format',
         r'C:\Dev\navigation\_clang-format']

try:
    src = sys.argv[1]
except IndexError:
    exit('cmd_all_clang_format.py requires 1 argument: the absolute path to the src file')

araxis_cmp.compare1toN(src, paths)
