n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
z = list(map(int, input().split()))

count = 0
for i in range(n):
    for j in range(n):
        if x[i] == y[z[j] - 1]:
            count += 1
print(count)
