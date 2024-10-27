#! /usr/bin/env python
import random
from PIL import Image

def block(p):
    return sum(p[:3]) < 255


def write_test(fn, blocks, N=None, M=None):
    n = max(i for i,j in blocks) + 1
    m = max(j for i,j in blocks) + 1
    k = len(blocks)

    if N is not None: n = max(n,N)
    if M is not None: m = max(m,M)

    assert n <= 1e9 and m <= 1e9 and k <= 1e5

    print(f'Writing test {fn} with N, M = {n}, {m} and K = {k}')
    with open(fn, 'w') as f:
        print(f'{n} {m} {k}', file=f)
        print('\n'.join(f'{i+1} {j+1}' for i,j in blocks), file=f)


def remove_duplicates(blocks):
    b = set()
    for x in blocks: b.add(x)
    return [*b]


def test_from_img(outname, name, K, N=None, M=None, noise=False, line=False, offset=(0,0)):
    img = Image.open(name)
    n, m = img.height, img.width
    
    blocks = []
    for i in range(n):
        for j in range(m):
            if block(img.getpixel((i, j))):
                blocks.append((i + offset[0], j + offset[1]))

    print(f'got {len(blocks)} pixels')

    if N is not None: n = N
    if M is not None: m = M

    if len(blocks) > K:
        print(f'Too many blocks in {name}: {len(blocks)} > {K}!')

    if any(i < 0 or j < 0 or i >= n or j >= m for i,j in blocks):
        print('Block out of bounds!')

    if noise:
        for _ in range(K - len(blocks) if not line else (K-len(blocks))//2):
            blocks.append((random.randrange(n), random.randrange(m)))

    if line:
        for i in range((K - len(blocks)) // 2):
            if i > min(n,m) - 4: break
            blocks.append((i,i))
            blocks.append((i,i+2))

    blocks = remove_duplicates(blocks)
    random.shuffle(blocks)
    
    assert len(blocks) <= K
    assert all(0 <= i < n and 0 <= j < m for i, j in blocks)

    write_test(outname, blocks, N, M)

def test_rand(fn, K, N, M, offset):
    di, dj = offset
    blocks = []
    k = K
    for s in range(0,K,2):
        for i in range(s):
            blocks.append((i+di, s-i+dj))
            
            k -= 1
            if k <= 0: break
        if k <= 0: break

    blocks = remove_duplicates(blocks)
    random.shuffle(blocks)
    
    assert len(blocks) <= K
    assert all(0 <= i < N and 0 <= j < M for i, j in blocks)

    write_test(fn, blocks)

    
random.seed(12346530427432)

write_test('testcases/01.in', [(0,0), (1,1), (2,2), (3,3), (0,2)])
write_test('testcases/02.in', [(1,1), (1,3)])

test_from_img('testcases/03.in', 'testimgs/03.png', 100, N=10, M=10)
test_from_img('testcases/04.in', 'testimgs/04.png', 100, N=10, M=10)

test_from_img('testcases/05.in', 'testimgs/05.png', 100000)
test_from_img('testcases/06.in', 'testimgs/06.png', 100000)

test_from_img('testcases/07.in', 'testimgs/07.png', 3000, N=123456,
              M=98654321, noise=True, line=True, offset=(10010, 93354323))
test_from_img('testcases/08.in', 'testimgs/08.png', 3000, N=84924738,
              M=11991922, noise=True, offset=(24924738, 10891922))

test_from_img('testcases/09.in', 'testimgs/09.png', 100000, N=1000000000, M=1000000000,
              noise=True, line=True, offset=(12312312, 32132132))
test_from_img('testcases/10.in', 'testimgs/10.png', 100000,
              noise=True, N=1000000000, M=1000000000, offset=(900000000, 8765432))
test_from_img('testcases/11.in', 'testimgs/11.png', 100000, N=900000000, M=900000000,
              noise=True, line=True, offset=(300000200, 880000000))
test_rand('testcases/12.in', 100000, N=1000000000, M=1000000000,
          offset=(12312312,488232))
