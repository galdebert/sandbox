#!/usr/bin/env python3

import time

i = 0
while i < 10:
    time.sleep(1)
    print(f'produced {i}')
    i += 1
