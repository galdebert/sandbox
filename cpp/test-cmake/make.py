#!/usr/bin/env python3

import galdebert.make as ga_make
import galdebert.utils as ga_utils

if __name__ == '__main__':
    root_absdir = ga_utils.containing_dir(__file__)
    ga_make.make(root_absdir)
