#! /usr/bin/env python3
import argparse
import random


def randsplit(s, n):
    assert s >= n
    res = [1 for _ in range(n)]
    for i in range(s - n):
        res[random.randrange(n)] += 1
    return res


def mkpatients(group, n, s):
    return [(group, k) for k in randsplit(s, n)]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    parser.add_argument('n', type=int)
    parser.add_argument('o', type=int)
    parser.add_argument('a', type=int)
    parser.add_argument('b', type=int)
    parser.add_argument('ab', type=int)
    parser.add_argument('--extra', action='store_true')
    parser.add_argument('--improve', action='store_true')
    parser.add_argument('--smallimprove', action='store_true')
    parser.add_argument('--impossible', action='store_true')
    args = parser.parse_args()

    random.seed(args.seed)
    n, o, a, b, ab = args.n, args.o, args.a, args.b, args.ab
    total = o + a + b + ab
    assert total <= 1000000

    no = int(n * o / total)
    na = int(n * a / total)
    nb = int(n * b / total)
    nab = int(n * ab / total)
    assert no + na + nb + nab <= n
    # stupid round-up thing
    while no + na + nb + nab < n:
        if random.random() < 0.5 and a > 0:
            na += 1
        elif random.random() < 0.5 and b > 0:
            nb += 1
        else:
            no += 1
    
    patients = mkpatients('O', no, o) + mkpatients('A', na, a) + mkpatients('B', nb, b) + mkpatients('AB', nab, ab)
    assert len(patients) == n

    if args.extra:
        no += random.randrange(3)
        na += random.randrange(3)
        nb += random.randrange(3)
        nab += random.randrange(3)

    if args.improve:
        for _ in range((o + a + b + ab) // (3 if not args.smallimprove else 20)):
            if random.random() < 0.15 and ab > 0:
                ab -= 1
                a += 1
            if random.random() < 0.15 and ab > 0:
                ab -= 1
                b += 1
            if random.random() < 0.3 and a > 0:
                a -= 1
                o += 1
            if random.random() < 0.3 and b > 0:
                b -= 1
                o += 1

    if args.impossible:
        x = random.randrange(4)
        if x == 3:
            if ab > 0: ab -= 1
            else: x -= 1
        if x == 2:
            if b > 0: b -= 1
            else: x -= 1
        if x == 1:
            if a > 0: a -= 1
            else: x -= 1
        if x == 0:
            assert o > 0
            o -= 1

    print(n)
    print(o, a, b, ab)
    random.shuffle(patients)
    for group, num in patients:
        print(group, num)

if __name__ == '__main__':
    main()
