#!/usr/bin/env python3

from pathlib import Path
from distutils.file_util import copy_file

def copy_headers(src_dir, dst_dir):
    for src in Path(src_dir).glob('**/*.h'):
        dst = Path(dst_dir).joinpath(src.relative_to(src_dir))
        dst.parent.mkdir(parents=True, exist_ok=True)
        copy_file(src, dst)
