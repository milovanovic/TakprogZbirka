import os

s = 'testcases/'
for i in range(1, 22):
	print('running {}'.format(i))
	os.system("time ./gric-autor-test < {}{:02}.in > /dev/null".format(
		s, i, s, i))