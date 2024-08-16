#! /usr/bin/env python3
import argparse
import random


def generate(n, hard, gen, veryhard):
    res = []
    while len(res) < hard:
        k = min(random.randrange(1, hard - len(res) + 1) for _ in range(2 if hard < 40 else 3))
        if veryhard:
            k = max(random.randrange(1, hard - len(res) + 1) for _ in range(2 if hard < 40 else 3))
        val = gen()
        res += [val] * k
    while len(res) < n:
        res.append(gen())
    return res


def countmap(a):
    res = {}
    for x in a:
        res[x] = res.get(x, 0) + 1
    return res


def limit(a):
    res = []
    cm = countmap(a)
    for x in cm:
        res += [x] * min(3, cm[x])
    return res    


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    parser.add_argument('subtask', type=int)
    parser.add_argument('n', type=int)
    parser.add_argument('--frachard', type=int, default=0)
    parser.add_argument('--veryhard', action='store_true')
    args = parser.parse_args()

    random.seed(args.seed)
    subtask = args.subtask
    assert subtask in [1, 2, 3, 4, 5]
    N, M, K, X = args.n, args.n, args.n, args.n
    hardN = int(args.frachard * N / 100)
    hardM = int(args.frachard * M / 100)
    hardK = int(args.frachard * K / 100)
    veryhard = args.veryhard

    constraints = {
        1: {'N': 1000},
        2: {'N': 1000},
        3: {'N': 100000},
        4: {'N': 100000},
        5: {'N': 100000}
    }
    assert N <= constraints[subtask]['N']
    assert M <= constraints[subtask]['N']
    assert K <= constraints[subtask]['N']
    assert X <= 10**9

    x, y, z = [], [], []

    all_equal = subtask == 3
    z_identity = subtask in [1, 4]

    x = generate(N, hardN, lambda: random.randrange(1, X + 1), veryhard)
    lx = limit(x)
    y = generate(M, hardM, lambda: random.choice(x if veryhard else lx) if random.randrange(10) < 9 else random.randrange(1, X + 1), veryhard)
    if all_equal:
        val = random.randrange(1, M + 1)
        z = [val] * K
    elif z_identity:
        z = [*range(1, K + 1)]
    else:    
        z = generate(K, hardK//2, lambda: random.randrange(1, M + 1), veryhard)

    random.shuffle(x)
    random.shuffle(y)
    if not z_identity:
        random.shuffle(z)

    assert len(x) == N and len(y) == M and len(z) == K
    if subtask in [1, 4]:
        assert all(zi == i + 1 for i, zi in enumerate(z))
    if subtask == 3:
        assert all(zi == z[0] for zi in z)

    assert all(1 <= xi <= X for xi in x)
    assert all(1 <= yi <= X for yi in y)
    assert all(1 <= zi <= M for zi in z)
            
    print(N)
    print(*x)
    print(*y)
    print(*z)


if __name__ == '__main__':
    main()
