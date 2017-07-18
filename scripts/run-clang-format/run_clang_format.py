import sys, argparse, os, fnmatch, subprocess

def run(args):
    parser = argparse.ArgumentParser()
    parser.add_argument("rootdir", nargs="*")
    parser.add_argument("--style", nargs="?", default="Google")
    parser.add_argument("--verbose", action="store_true")
    parsed_args = parser.parse_args(args)

    def find_files(directory, pattern):
        for root, dirs, files in os.walk(directory):
            for basename in files:
                if fnmatch.fnmatch(basename, pattern):
                    filename = os.path.join(root, basename)
                    yield filename

    call_args = ["clang-format.exe", "-i", "--style={}".format(parsed_args.style)]

    for rootdir in parsed_args.rootdir:
        for filename in find_files(rootdir, "*.cpp"):
            call_args.append(filename)

    if parsed_args.verbose:
        print(call_args)

    subprocess.call(call_args)

if __name__ == "__main__":
    run(sys.argv)