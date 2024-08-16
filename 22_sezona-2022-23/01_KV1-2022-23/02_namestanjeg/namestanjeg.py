import bisect

def custom_binary_search(arr, x):
    if arr[len(arr)//2] == x:
        return len(arr)//2
    if arr[len(arr)//2] < x:
        return bisect.bisect_left(arr, x)
    else:
        return bisect.bisect_right(arr, x) - 1

def custom_linear_search(arr, x):
    if arr[0] > x:
        return -1
    if arr[-1] < x:
        return len(arr)
    i = len(arr)//2
    if arr[i] == x:
        return i
    if arr[i] > x:
        while arr[i] > x:
            i -= 1
        return i
    if arr[i] < x:
        while arr[i] < x:
            i += 1
        return i

N, Q = map(int, input().split())
A = sorted(list(map(int, input().split())))
B = list(map(int, input().split()))

for X in B:
    i = custom_binary_search(A, X) # for O(Nlog(N))
    #i = custom_linear_search(A, X) # for O(N^2)
    mx = max(i, N-i)
    mn = min(i+1, N-i)
    print(mx - mn)
