import math
import random

N = 200000
print(N)

for k in range(N):
    x = k * (1.0 + 1e-6 - 1e-7)
    y = 0
    r = math.fmod(k * 0.1, 2 * math.pi)
    print(x, y, r)
