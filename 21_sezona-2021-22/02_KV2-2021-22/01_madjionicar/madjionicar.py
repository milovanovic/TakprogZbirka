n, k = map(int, input().split())
s = list(map(int, input().split()))
print(s[(s.index(k)+1)%n])
