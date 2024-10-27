#! /usr/bin/env python3
import sys
import random

L = int(input())
s = input()
n = int(sys.argv[1])
if len(sys.argv) > 2:
    random.seed(int(sys.argv[2]))
all_chars = '--all' in sys.argv

prepend = '--prepend-all' in sys.argv
if prepend:
    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' + s
    n -= 26
    assert(n > 0)

idx = []
for i in range(n):
    if prepend:
        idx.append(random.randrange(L+i-26)+26)
    else:
        idx.append(random.randrange(L + i))
idx.append(n + L)  # fake end insertion to avoid special cases

curr = 0
res = ""
pool = set()
for i in sorted(idx):
    while len(res) < i:
        res += s[curr]
        pool.add(s[curr])
        curr += 1
    if all_chars:
        res += random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    else:
        res += random.choice([*pool]) if pool else "A"

res = res[:-1]  # remove fake
print(L + n)
print(res)
