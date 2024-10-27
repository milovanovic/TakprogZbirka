#! /usr/bin/env python
import random
import argparse
import math

def centre(n, m):
    n0 = min(n-1, n//3+1)
    m0 = min(m-1, 3*m//7)
    return n0, m0


def to_tile(x):
    if x < 20: return x
    else:
        res = 20 + (x-20)**3//7 + (x-20)**2 + 13*(x-20) + min(900000000, 6**(x//20))
        assert(res > 0 and res <= 1000000000)
        return res


def gen_board(n, m, offset):
    board = [[0 for _ in range(m)] for _ in range(n)]
    n0, m0 = centre(n,m)
    
    for i in range(n):
        for j in range(m):
            d = max(abs(n0-i), abs(m0-j))
            noise = random.randrange(10) if random.random() < 0.7 else 0
            board[i][j] = to_tile(d) + noise + (offset if offset else 0)

    return board


def gen_board_lim(n, m, L):
    board = [[0 for _ in range(m)] for _ in range(n)]
    n0, m0 = centre(n, m)
    for i in range(n):
        for j in range(m):
            d = max(abs(n0-i), abs(m0-j))
            ml = max(n0,m0)
            mx = min(L, 1 + 10*d//9 // (ml//L))
            board[i][j] = random.randrange(mx, L+1) - 1
            assert(board[i][j] >= 0 and board[i][j] < L)
    return board
            

def gen_query(n, m, small=False):
    n0, m0 = centre(n,m)
    while True:
        if random.random() < 0.2:
            i = random.randrange(n)
            j = random.randrange(m)
            ii = random.randrange(n)
            jj = random.randrange(m)
        else:
            i = n0 - random.randrange(n0+1)
            j = m0 - random.randrange(m0+1)
            ii = n0 + random.randrange(n-n0)
            jj = m0 + random.randrange(m-m0)

        if ii < i: i, ii = ii, i
        if jj < j: j, jj = jj, j

        if small:
            if random.random() < 0.5:
                ii = i + random.randrange(10)
            else:
                i = ii - random.randrange(10)
            if random.random() < 0.5:
                jj = j + random.randrange(10)
            else:
                j = jj - random.randrange(10)
                
        if i == 0 and j == 0 and ii == n-1 and jj == m-1:
            continue  # do not cover everything
        if i < 0 or j < 0 or i >= n or j >= m:
            continue
        return (i+1, j+1, ii-i+1, jj-j+1)


parser = argparse.ArgumentParser()
parser.add_argument('seed', type=int)
parser.add_argument('n', type=int)
parser.add_argument('m', type=int)
parser.add_argument('q', type=int)
parser.add_argument('--max', type=int)
parser.add_argument('--offset', type=int)
parser.add_argument('--small', action='store_true')
args = parser.parse_args()

random.seed(args.seed)

board = None
if args.max is not None:
    board = gen_board_lim(args.n, args.m, args.max+1)
else:
    board = gen_board(args.n, args.m, offset=args.offset)
queries = [gen_query(args.n, args.m, args.small) for _ in range(args.q)]
print(args.n, args.m, args.q)
print('\n'.join(' '.join(str(x) for x in row) for row in board))
print('\n'.join(' '.join(str(a) for a in q) for q in queries))
