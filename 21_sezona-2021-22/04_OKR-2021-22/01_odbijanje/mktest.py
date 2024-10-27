#! /usr/bin/env python3
import argparse
import random
import sys


def randunique(n, x):
    res = []
    seen = set()

    for _ in range(n):
        curr = random.randrange(1, x + 1)
        while curr in seen:
            if x > 2*n:
                curr = random.randrange(1, x + 1)
            else:
                curr += 1
                if curr > x:
                    curr = 1

        seen.add(curr)
        res.append(curr)

    return res


def splittotal(total, n, x):
    assert n*x >= total

    tries = 0

    while True:
        cuts = [random.randrange(total + n - 1) for i in range(n-1)]
        cuts = [0] + cuts + [total + n]
        res = [b - a - 1 for a, b in zip(cuts[:-1], cuts[1:])]
        assert sum(res) == total
        if min(res) > 0 and max(res) <= x:
            return res
        
        tries += 1
        if tries > 100:
            break

    # fallback
    print('Falling back to simpler splittotal', file=sys.stderr)
    res = [random.randrange(1, x+1) for _ in range(n)]
    while sum(res) > total:
        i = random.randrange(n)
        d = min(sum(res) - total, res[i] - 2)
        if d <= 0: continue
        res[i] -= random.randrange(d//2, d + 1)
    while sum(res) < total:
        i = random.randrange(n)
        d = min(total - sum(res), x - res[i])
        if d <= 0: continue
        res[i] += random.randrange(d//2, d + 1)
    return res


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    parser.add_argument('subtask', type=int)
    parser.add_argument('l', type=int)
    parser.add_argument('r', type=int)
    parser.add_argument('x', type=int)
    parser.add_argument('s', type=int)
    parser.add_argument('hpL', type=int)
    parser.add_argument('hpR', type=int)
    args = parser.parse_args()

    random.seed(args.seed)
    subtask = args.subtask
    assert subtask in [1, 2, 3, 4]
    L, R, X, S = args.l, args.r, args.x, args.s
    N = L + R

    constraints = {
        1: {'N': 100, 'S': 100, 'X': 100},
        2: {'N': 1000, 'S': 1000, 'X': 10**9},
        3: {'N': 5000, 'S': 10**9, 'X': 10**9},
        4: {'N': 5 * 10**5, 'S': 10**9, 'X': 10**9}
    }
    assert N <= constraints[subtask]['N']
    assert S <= constraints[subtask]['S']
    assert X <= constraints[subtask]['X']

    walls = []

    for hp, pos in zip(splittotal(args.hpL, L, S), randunique(L, X)):
        walls.append((-pos, hp))
    for hp, pos in zip(splittotal(args.hpR, R, S), randunique(R, X)):
        walls.append((pos, hp))
    random.shuffle(walls)

    print(N)
    for x, hp in walls:
        print(x, hp)

if __name__ == '__main__':
    main()
