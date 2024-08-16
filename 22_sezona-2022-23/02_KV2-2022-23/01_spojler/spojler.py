a, b = map(int, input().split())
x, y = map(int, input().split())

if x == a and y == b:
    print('nijedan')
if x < a and y < b:
    print('?')
if x < a and y == b:
    print('prvi')
if x == a and y < b:
    print('drugi')
