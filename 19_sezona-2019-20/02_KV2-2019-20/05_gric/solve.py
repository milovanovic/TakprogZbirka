import os

s = 'testcases/'
for i in range(1, 22):
	print('solving {}'.format(i))
	os.system("time ./gric < {}{:02}.in > {}{:02}.out".format(
		s, i, s, i))