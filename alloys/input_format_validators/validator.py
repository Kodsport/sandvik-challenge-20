import sys
import re

line = sys.stdin.readline()
assert re.match("^[0-1]\\.[0-9]{1,6}$", line)

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
