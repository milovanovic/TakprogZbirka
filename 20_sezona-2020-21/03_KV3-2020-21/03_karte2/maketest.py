#! /usr/bin/env python3
import sys
from collections import namedtuple
import random

RAND = 0
ALL = 1
EQUAL = 2
WIN = 3
LOSE = 4

Params = namedtuple("Params", "seed T N allsame maxA tests")
params = {
    # subtask 1: N <= 1000
    "03": Params(3, 20, 1000, False, 10000, [WIN, WIN, LOSE, LOSE]),
    "04": Params(4, 20, 1000, False, 1000000000, [WIN, LOSE, ALL]*2),
    "05": Params(5, 20, 1000, False, 1000000000, [WIN, LOSE, ALL]*2),
    
    # subtask 2: N <= 1e5, all equal
    "06": Params(60, 20, 100000, True, 1000, []),
    "07": Params(7, 20, 99999, True, 1000000000, []),
    "08": Params(8, 20, 99998, True, 1000000000, []),

    # subtask 3: N <= 1e5
    "09": Params(9, 20, 100000, False, 1000, [WIN, WIN, LOSE, LOSE]),
    "10": Params(10, 20, 99999, False, 1000000000, [WIN, LOSE, ALL]),
    "11": Params(11, 20, 99998, False, 1000000000, [WIN, LOSE, ALL]),
    "12": Params(12, 20, 99998, False, 100000000, [WIN, LOSE, ALL])
}[sys.argv[1]]

def gen_same(t):
    n = params.N
    a = random.randrange(params.maxA) + 1
    k = 1 + (random.randrange(params.maxA) if random.random() < 0.3
             else a + random.randrange(params.maxA) if random.random()
             < 0.6 else random.randrange(1000000000))
    k = min(k, 1000000000)
    return n, k, [a for _ in range(n)]

def gen_test(t):
    if params.allsame:
        return gen_same(t)

    n = params.N
    a = []

    if t == RAND:
        a = [random.randrange(params.maxA) + 1 for _ in range(n)]
        k = random.randrange(n*params.maxA//2)
        if k > 1000000000: k = 1000000000 - random.randrange(1000000)
    elif t == ALL:
        a = [random.random() for _ in range(n - 2)]
        a += [sum(a)+1, 2*sum(a)+3]
        k = 1000000000 - random.randrange(1000000)
        S = k - random.randrange(100) - 1 - 4*n
        sx = sum(a)
        a = [int(x*S/sx) + i for i,x in enumerate(a)]
    else:
        # lazy fallback
        n, k, a = gen_test(RAND)

    assert(1 <= k <= 1e9)
    assert(all(1 <= x <= 1e9 for x in a))
    if params.allsame:
        assert(all(x == a[0] for x in a))
    return n, k, a

random.seed(params.seed)

print(params.T)

tests = params.tests
tests += [RAND for _ in range(params.T - len(tests))]
for t in tests:
    n, k, a = gen_test(t)
    print(f'{n} {k}')
    print(' '.join([str(x) for x in a]))
