import random

R = random.randint(1, 500) * 2
C = random.randint(1, 500) * 2

N = R * C
a, b = sorted(random.sample(range(N), 2))
print(R, C)
print(a, b - a, N - b)
