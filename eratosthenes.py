import sys, math
sys.stdin = open("00/INPUT")

for line in sys.stdin:
    n = int(line)
prime_count = 0

if n % 2 == 1:
    primes = [True for _ in range(n // 2 + 1)]
else:
    primes = [True for _ in range(n // 2)]
p = 3
while p * p <= n:
    if primes[p // 2] == True:
        for j in range(3 * p, n + 1, 2 * p):
            primes[j // 2] = False
    p += 2

if n >= 2:
    prime_count += 1
for x in primes[1:]:
    if x == True:
        prime_count += 1

print(prime_count)