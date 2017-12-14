#!/usr/bin/env python3

import sys
import subprocess
import galdebert.utils as utils

root_absdir = utils.containing_dir(__file__)

fmt_cmd = [sys.executable, '-m', 'galdebert.pysrc', 'fmt', root_absdir]
print(' '.join(fmt_cmd))
subprocess.run(fmt_cmd)

lint_cmd = [sys.executable, '-m', 'galdebert.pysrc', 'lint', root_absdir]
print(' '.join(lint_cmd))
subprocess.run(lint_cmd)
