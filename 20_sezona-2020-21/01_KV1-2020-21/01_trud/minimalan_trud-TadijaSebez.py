B, C = map(int, input().split())
if B+C>=256:
	print(0)
else:
	print(256-max(B,C))