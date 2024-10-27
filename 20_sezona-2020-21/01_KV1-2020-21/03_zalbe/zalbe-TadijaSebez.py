def nzd(x, y):
	if x==0:
		return y
	return nzd(y%x,x)

t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	g = 0
	for i in range(1,n):
		g = nzd(g, a[i]-a[0])
	ok = True
	for i in b:
		if i%g == a[0]%g:
			ok = False
	if ok:
		print(1)
	else:
		print(0)