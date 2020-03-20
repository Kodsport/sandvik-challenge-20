import math
import random

N = 200000
print(N)

for k in range(N):
    x = (random.random() - 0.5) * 2 * 10**9
    y = (random.random() - 0.5) * 2 * 10**9
    r = random.random() * 2 * math.pi
    print(x, y, r)
