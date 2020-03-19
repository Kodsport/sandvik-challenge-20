import random

N = 100
M = [(a, a+1) for a in range(N-1)]

print(N, len(M))
for _ in range(N):
    S = random.randint(1, 2000)
    T = random.randint(S + 1, 2000)
    print(S, T)

for a, b in M:
    print(a, b)
