import math
import random

N = 200000
print(N)

D = 2 * (1.0 + 1e-6 + 1e-7)
theta = 2 * math.pi / N
# D = 2R sin(theta/2)
# D / sin(theta/2) = 2R
# D / 2sin(theta/2) = R
R = D / (2 * math.sin(theta / 2))

for k in range(N):
    x = math.cos(2 * math.pi / N * k) * R
    y = math.sin(2 * math.pi / N * k) * R

    ox = math.cos(2 * math.pi / N * (k + (-1 if k%2 else 1))) * R
    oy = math.sin(2 * math.pi / N * (k + (-1 if k%2 else 1))) * R
    
    dx = ox - x
    dy = oy - y
    ang = 2*math.pi-math.atan2(dy, dx)

    print(x, y, math.fmod(ang+2*math.pi, 2*math.pi))
