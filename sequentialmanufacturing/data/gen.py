import random

N = random.randint(1, 1000)
P = random.randint(1, 10**9)

L = [random.randint(1, 10**9) for _ in range(N)]
M = [random.randint(1, 10**9) for _ in range(N-1)]
print(N, P)
print(*L)
print(*M)
