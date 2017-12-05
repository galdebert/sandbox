#!/usr/bin/env python3

import glob
import re
import os

for src in glob.glob("./*_lua_api*"):
    dst = re.sub(r'(.*)_lua_api(\..*)', r'\1_lua\2', src)
    print(f'src={src}')
    print(f'dst={dst}')
    os.rename(src, dst)
