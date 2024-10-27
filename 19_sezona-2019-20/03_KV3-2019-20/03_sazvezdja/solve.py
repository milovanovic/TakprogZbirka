import os

s = 'testcases/'
for i in range(1, 29):
	print('solving {}'.format(i))
	os.system("time ./sazvezdja < {}{:02}.in > {}{:02}.out".format(
		s, i, s, i))