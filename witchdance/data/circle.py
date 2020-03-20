import math
import random

N = 200000
print(N)

for k in range(N):
    x = math.cos(2 * math.pi / N * k) * 66666
    y = math.sin(2 * math.pi / N * k) * 66666
    r = random.random() * 2 * math.pi
    print(x, y, r)
