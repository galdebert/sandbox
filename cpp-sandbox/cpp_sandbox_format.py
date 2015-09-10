import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'run-clang-format'))
import run_clang_format

def cpp_sandbox_format(style):
	run_clang_format.run(
		[r"C:\Users\galde_000\Dev\sandbox\cpp-sandbox\src",
		"--style", style])
	raw_input("Press Enter to continue")

