#to test if directory is run_clang_format
#from ..run-clang-format import run_clang_format
import sys, os
sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'run-clang-format'))
import run_clang_format

run_clang_format.run(
	[r"C:\Users\galde_000\Dev\sandbox\cpp-sandbox\src",
	"--style", "Google"])

input("Press key to continue")