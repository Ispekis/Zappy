#!/usr/bin/env python3

import sys

# Include relative path of the source files from the root
sys.path.append('src/ai/src')

from myparser import parse_data
import usage
from zappy_ai import run_ai
from myexeption import CustomException

def main(argv):
    if len(argv) == 2 and argv[1] == "-help":
        usage.show_usage(sys.stdout)
        return 0
    try:
        port, name, machine = parse_data(argv)
    except CustomException as e:
        print(e, file=sys.stderr)

    run_ai()

    print("Ai here !")
    return 0

if __name__ == "__main__":
    exit(main(sys.argv))
