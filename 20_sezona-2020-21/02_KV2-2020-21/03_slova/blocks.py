#! /usr/bin/env python3
import sys
import random

n = int(sys.argv[1])
if len(sys.argv) > 2:
    random.seed(int(sys.argv[2]))

assert(n >= 26)

chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ks = [random.random() for c in chars]
ks = [k / sum(ks) for k in ks]
ks = [1 + int(k*(n-26)) for k in ks]

# fix rounding errors
assert(sum(ks) <= n)
while sum(ks) < n:
    ks[random.randrange(26)] += 1

print(n)
print(''.join(c*k for c,k in zip(chars, ks)))

