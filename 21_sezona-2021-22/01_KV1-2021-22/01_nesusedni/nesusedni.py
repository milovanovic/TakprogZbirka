ss = input()
a1, a2 = map(int, input().split())

if a1 == a2:
    print(ss * a1)
elif a1 - a2 == 1:
    print(ss * a2 + ss[0])
elif a2 - a1 == 1:
    print(ss[1] + ss * a1)
elif abs(a1 - a2) > 1:
    print("nemoguce")
