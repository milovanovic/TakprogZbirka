def dejn(n, t):
    if sum(int(copysign(1, x)) for x in t) != 0:
        return -1
    ans = 0
    for i in range(n):
        assert isinstance(t[i], int) and t[i] != 0
        if (i%2 == 0 and t[i] < 0) or (i%2 == 1 and t[i] > 0):
            if abs(t[i]) == abs(t[i+1]):
                t[i], t[i+1] = -t[i], -t[i+1]
            else:
                return -1
        if i%2 == 1:
            ans -= t[i] + t[i-1]
    return ans

from math import copysign

T = int(input())
for _ in range(T):
    n, t = int(input()), sorted(map(int, input().split()), key=abs)
    assert len(t) == n
    print(dejn(n, t))
