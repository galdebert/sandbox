#!/usr/bin/env python3

import os
import sys
import subprocess
from typing import List
import importlib.util
import argparse
from utils import utils


def packages_iter(root_absdir: str) -> List[str]:
    for p in utils.glob_abs(f'{root_absdir}/**/__init__.py'):
        yield utils.norm_path(os.path.dirname(p))

def modules_iter(root_absdir: str, modules: List[str]) -> List[str]:
    for p in utils.glob_abs(f'{root_absdir}/**/*.py'):
        if not any((p.startswith(m) for m in modules)): # if not already in a module dir
            yield p

def print_list(title: str, lst: List[str]):
    print(f'{title}:')
    for p in lst:
        print(f'  {p}')

def packages_and_modules(root_absdir: str, verbose: bool):
    packages = [p for p in packages_iter(root_absdir)]
    if verbose:
        print_list('packages', packages)
    modules = [p for p in modules_iter(root_absdir, packages)]
    if verbose:
        print_list('modules', modules)
    return packages, modules

def lint(root_absdir: str, args):
    if importlib.util.find_spec('pylint') is None: # test that autopep8 module is installed
        print(f'`pylint` not found. Try to run `{sys.executable} -m pip install -r {root_absdir}/requirements.txt`')
        return -1

    packages, modules = packages_and_modules(root_absdir, verbose=args.verbose)

    cmd = [sys.executable, '-m', 'pylint', f'--rcfile=python-format', '--score=n']
    cmd.extend(packages)
    cmd.extend(modules)
    rc = subprocess.run(cmd).returncode

    if rc == 0:
        print('pylint detected no error')
    else:
        print('pylint detected some errors')
    return rc

def fmt(root_absdir: str, args):
    if importlib.util.find_spec('autopep8') is None: # test that autopep8 module is installed
        print(f'`autopep8` not found. Try to run `{sys.executable} -m pip install -r {root_absdir}/requirements.txt`')
        return -1

    packages, modules = packages_and_modules(root_absdir, verbose=args.verbose)

    cmd = [sys.executable, '-m', 'autopep8', '--global-config', 'python-format', '--recursive', '--in-place']
    cmd.extend(packages)
    cmd.extend(modules)
    rc = subprocess.run(cmd).returncode
    return rc


desc = '''
src.py lint     lint packages, modules in src.py dir and subdirs
src.py format   format packages, modules in src.py dir and subdirs
'''

def help_str(choices: List[str], default: str=None) -> str:
    default_str = f' default={default}' if default is not None else ''
    return f'[{", ".join(choices)}]{default_str}'


if __name__ == '__main__':
    root_absdir = utils.norm_path(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(root_absdir)

    main_parser = argparse.ArgumentParser(add_help=True, formatter_class=argparse.RawDescriptionHelpFormatter, description=desc)
    command_choices = ['lint', 'fmt']
    main_parser.add_argument('command', nargs='?', choices=command_choices, help=help_str(command_choices), metavar='<command>') # metavar makes help compact
    main_parser.add_argument('--verbose', '-v', action='store_true', help='')

    argv = sys.argv[1:]
    #args, command_argv = main_parser.parse_known_args(argv) # use when other parsers are used in each command
    args = main_parser.parse_args(argv)

    rc = 0
    if args.command == 'fmt':
        rc = fmt(root_absdir, args)
    if args.command == 'lint':
        rc = lint(root_absdir, args)

    sys.exit(rc)
