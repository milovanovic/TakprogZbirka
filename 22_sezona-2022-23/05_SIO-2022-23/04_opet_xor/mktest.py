#! /usr/bin/env python3
import argparse
import random


def rand_smallish(n):
    res = n
    for _ in range(3):
        res = min(res, random.randrange(1, n))
    return res

def rand_query_width(L):
    if L < 20:
        return random.randrange(1, L+1)
    if random.random() < 0.3:
        return rand_smallish(min(30**2//2, L))
    elif random.random() < 0.5:
        return random.randrange(L//2, L+1)
    elif random.random() < 0.6:
        return random.randrange(L//6, min(L, 2*L//3))
    else:
        return random.randrange(1, L//2)


def random_int(A):
#    return random.randrange(A)
    nb = A.bit_length()  # assumes A is a power of 2
    x = 0
    for b in range(nb-1):
        if random.random() < 0.5:
            x |= 1 << b
        if random.random() < 0.1:
            break

    return x


def random_solvable(n, A):
    target = None
    while True:
        target = [random.randrange(A) for _ in range(n)]
        target.sort()
        if all(a != b for a, b in zip(target, target[1:])):
            break

    res = []
    curr = 0
    for x in target:
        curr = curr ^ x
        res.append(curr)

    return res


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    parser.add_argument('subtask', type=int)
    parser.add_argument('n', type=int)
    parser.add_argument('q', type=int)
    parser.add_argument('--mostly_q', action='store_true')
    args = parser.parse_args()

    random.seed(args.seed)
    subtask = args.subtask
    assert subtask in [1, 2, 3, 4, 5, 6]
    N, Q = args.n, args.q
    mostly_queries = args.mostly_q

    constraints = {
        1: {'N': 300000, 'Q': 10, 'A': 2**30, 'L': 10},
        2: {'N': 200, 'Q': 200, 'A': 2**30},
        3: {'N': 5000, 'Q': 5000, 'A': 2**30},
        4: {'N': 300000, 'Q': 300000, 'A': 2**30, 'noUpdate': True},
        5: {'N': 300000, 'Q': 300000, 'A': 64},
        6: {'N': 300000, 'Q': 300000, 'A': 2**30}
    }
    assert 1 <= N <= constraints[subtask]['N']
    assert 1 <= Q <= constraints[subtask]['Q']
    maxA = constraints[subtask]['A']
    maxL = constraints[subtask].get('L', N)
    noUpdate = constraints[subtask].get('noUpdate', False)

    a = [random_int(maxA) for _ in range(N)]

    if maxA > 2**10:
        for _ in range(10):
            st = random.randrange(len(a))
            num = random.randrange(min(2**14, len(a) - st))
            a[st:st+num] = random_solvable(num, maxA)

    queries = []
    interesting = []

    for _ in range(Q):
        t = 2 if noUpdate else random.choice([1, 2, 2, 2] if mostly_queries else [1, 2])
        i, x = None, None
        if t == 1:
            i = random.randrange(1, N+1)
            x = random_int(maxA)
            if len(interesting) < 100:
                interesting.append(i)
        else:
            if len(interesting) > 0 and random.random() < 0.8:
                i = random.choice(interesting)
                if not mostly_queries:
                    interesting.remove(i)
                elif random.random() < 0.5:
                    interesting.remove(i)
                
                x = rand_query_width(maxL)
                i += random.randrange(-x//2, x//2)
                i = min(max(i, 1), N)
                x = min(x, N-i+1)
            else:
                x = rand_query_width(maxL)
                i = random.randrange(1, N+1-(x-1))

        queries.append((t, i, x))

    assert maxA <= 2**30
    assert all(0 <= ai < maxA for ai in a)

    assert all(1 <= i <= N for t, i, x in queries)
    assert all(0 <= x < maxA for t, i, x in queries if t == 1)
    assert all(1 <= x <= maxL for t, i, x in queries if t == 2)
    assert all(i+x-1 <= N for t, i, x in queries if t == 2)
    assert all(t == 2 for t, i, x in queries if noUpdate)

    print(N, Q)
    print(*a)
    for q in queries:
        print(*q)


if __name__ == '__main__':
    main()
