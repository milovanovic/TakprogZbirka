brojevi = tuple(sorted(map(int,input().split())))
x,y = brojevi[0:2]
z = brojevi[-1]-x-y
print(x,y,z)
