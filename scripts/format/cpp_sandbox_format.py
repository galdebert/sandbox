import sys
import os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', '..', 'run-clang-format'))
import run_clang_format

verbose = 0

def cpp_sandbox_format(style):
    args = ["../src", "--style", style]
    if verbose:
        args.append("--verbose")
    run_clang_format.run(args)

