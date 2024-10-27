n = int(input())
E = [[] for _ in range(n)]
for _ in range(n-1):
	u, v, w = input().split()
	u = int(u)
	v = int(v)
	E[u-1].append((v-1, w))
	E[v-1].append((u-1, w))

sz = [0 for _ in range(n)]
was = [False for _ in range(n)]
def DFS(u, p):
	sz[u] = 1
	for (v, _) in E[u]:
		if v!=p and not was[v]:
			DFS(v, u)
			sz[u] += sz[v]
def Find(u, p, n):
	for (v, _) in E[u]:
		if v!=p and (not was[v]) and sz[v]*2>n:
			return Find(v,u,n)
	return u
def FindCen(u):
	DFS(u,u)
	return Find(u,u,sz[u])
push = []
def Solve(u, p, P):
	push.append(P)
	for (v, w) in E[u]:
		if v!=p and not was[v]:
			if w=='S':
				Solve(v, u, (P[0]+1, P[1]+1))
			elif w=='I':
				Solve(v, u, (P[0]-1, P[1]))
			else:
				Solve(v, u, (P[0], P[1]-1))
def Decompose(u):
	u = FindCen(u)
	was[u] = True
	cnt = {
		(0, 0): 1,
	}
	ans = 0
	for (v, w) in E[u]:
		if not was[v]:
			if w=='S':
				Solve(v, u, (1, 1))
			elif w=='I':
				Solve(v, u, (-1, 0))
			else:
				Solve(v, u, (0, -1))
			for P in push:
				if (-P[0], -P[1]) in cnt:
					ans += cnt[(-P[0], -P[1])]
			for P in push:
				if P in cnt:
					cnt[P] += 1
				else:
					cnt[P] = 1
			while push:
				push.pop()
	for (v, _) in E[u]:
		if not was[v]:
			ans += Decompose(v)
	return ans

ans = Decompose(0)
print(ans)