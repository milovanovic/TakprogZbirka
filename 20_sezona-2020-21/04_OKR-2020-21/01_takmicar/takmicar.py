N = int(input())
S = sum(map(int, input().split()))
cntQ2 = 0
for _ in range(int(input())):
    Q = tuple(map(int, input().split()))
    if Q[0] == 1 and Q[3] > 0:
        S += Q[3]*(Q[2]-Q[1]+1)
    elif Q[0] == 2:
        cntQ2 += 1

print(S*cntQ2)
