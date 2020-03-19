import math
import random

N = 100
eds = set()
M = []
C = 0.1
for _ in range(random.randint(1, N * (N - 1) / 2)):
    f = random.randint(0, N - 2)
    t = f + 1 + int(math.pow(random.random(), C) * (N - 1 - f - 1) + 1e-6)
    assert f < t < N
    if (f, t) in eds: continue
    eds.add((f, t))
    M.append((f, t))
    M.append((t, f))

print(N, len(M))
for _ in range(N):
    S = random.randint(1, 5)
    T = random.randint(S + 1, 2000)
    print(S, T)

for a, b in M:
    print(a, b)
