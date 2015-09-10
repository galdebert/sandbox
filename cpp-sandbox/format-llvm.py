import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'run-clang-format'))
import run_clang_format

run_clang_format.run(
	[r"C:\Users\galde_000\Dev\sandbox\cpp-sandbox\src",
	"--style", "LLVM"])

raw_input("Press Enter to continue")
