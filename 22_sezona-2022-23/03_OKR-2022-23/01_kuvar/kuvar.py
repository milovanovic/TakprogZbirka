n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
z = list(map(int, input().split()))

count = {}
for j in range(n):
    count[y[z[j]-1]] = count.get(y[z[j]-1], 0) + 1

result = 0
for i in range(n):
    result += count.get(x[i], 0)

print(result)
