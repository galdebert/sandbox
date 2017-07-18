#!/usr/bin/env python3

import os
import subprocess

root_dir = os.path.dirname(os.path.abspath(__file__))

cmake_output_dir = os.path.join(root_dir, 'cmake.output')
if not os.path.exists(cmake_output_dir):
    os.makedirs(cmake_output_dir)

print(cmake_output_dir)

cmd = ['cmake', '-B{}'.format(cmake_output_dir), '-H{}'.format(root_dir)]
subprocess.run(cmd)
