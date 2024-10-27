n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
ans = 0
for _ in range(m):
	u, v = map(int, input().split())
	ans += abs(a[u-1]+a[v-1])
print(ans)