import math
import random

N = 2
print(N)

for k in range(N):
    x = random.random() * 2
    y = random.random() * 2
    r = random.random() * 2 * math.pi
    print(x, y, r)
