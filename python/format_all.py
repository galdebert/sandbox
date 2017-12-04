#!/usr/bin/env python3

import os
import sys
import subprocess
from typing import List
import utils

# if importlib.util.find_spec("pylint") is None: # test that pylint module is installed
#     pie_print(f'lint python: `pylint` not found. Try to run `{sys.executable} -m pip install -r {pie_root}/requirements.txt`')
#     return -1

def packages_iter(root_absdir: str) -> List[str]:
    for p in utils.glob_abs(f'{root_absdir}/**/__init__.py'):
        yield utils.norm_path(os.path.dirname(p))

def modules_iter(root_absdir: str, modules: List[str]) -> List[str]:
    for p in utils.glob_abs(f'{root_absdir}/**/*.py'):
        if not any((p.startswith(m) for m in modules)): # if not already in a module dir
            yield p

def format_all(root_absdir: str):
    packages = [p for p in packages_iter(root_absdir)]
    modules = [p for p in modules_iter(root_absdir, packages)]

    cmd = [sys.executable, '-m', 'pylint', f'--rcfile=python-format', '--score=n']
    cmd.extend(packages)
    cmd.extend(modules)

    print(' '.join(cmd))
    rc = subprocess.run(cmd).returncode
    rc = 0
    return rc


if __name__ == '__main__':
    root_absdir = utils.norm_path(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(root_absdir)
    rc = format_all(root_absdir)
    sys.exit(rc)
