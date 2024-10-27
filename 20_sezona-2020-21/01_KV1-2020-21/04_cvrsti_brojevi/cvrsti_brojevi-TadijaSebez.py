s = input()
dp = [[0 for _ in range(10)] for _ in range(1024)]
best = [0 for _ in range(1024)]
for c in s:
	o = ord(c)-ord('0')
	for mask in range(1024):
		if ((mask>>o)&1) == 1:
			dp[mask][o] = max(dp[mask][o], best[mask^(1<<o)])+1
			best[mask] = max(best[mask], dp[mask][o])
ans = 0
for i in best:
	ans = max(ans, i)
print(len(s)-ans)