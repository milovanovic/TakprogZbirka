x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

if x1 == x2 or y1 == y2:
    print(2)
elif abs(x1-x2) == abs(y1-y2):
    print(1)
else:
    print(0)
