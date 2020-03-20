#!/usr/bin/env python3

import sys

n = int(sys.stdin.readline())
print(n)
    
def fix(s):
    if 'e' in s:
        f = float(s)
        return '{:0.20f}'.format(float(s)).rstrip('0')
    return s

for _ in range(n):
    a, b, c = sys.stdin.readline().split()
    print(fix(a), fix(b), fix(c))
