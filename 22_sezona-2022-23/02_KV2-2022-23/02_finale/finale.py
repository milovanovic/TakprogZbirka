m, n = map(int, input().split())

if m == 1 or n == 1:
    print(max(m,n))
else:
    print(2*(m+n-2) + (m-2)*(n-2)//2)
