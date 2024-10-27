B, C = map(int, input().split())
if B+C<256:
    print(256-max(B,C))
else:
    print(0)
