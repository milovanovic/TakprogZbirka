import sympy.ntheory.generate as nt
from sympy.ntheory.factor_ import divisors
import numpy as np

MID = 10**13
HI = 2**62
TLO = 10
TMID = 500
THI = 10000

cfg = [
	[ 2, MID, TLO, 0.1, 0.1, 0.8, 0],
	[ 3, MID, TLO, 0.1, 0.8, 0.1, 0],
	[ 4, MID, TLO, 0.8, 0.1, 0.1, 0],
	[ 5, MID, TLO, 0.333, 0.333, 0.334, 0],
	[ 6, HI, TMID, 0.1, 0.1, 0.8, 0],
	[ 7, HI, TMID, 0.1, 0.8, 0.1, 0],
	[ 8, HI, TMID, 0.8, 0.1, 0.1, 0],
	[ 9, HI, TMID, 0.333, 0.333, 0.334, 0],
	[10, HI, THI, 0.5, 0.2, 0.3, 0],
	[11, HI, THI, 0.5, 0.3, 0.2, 0],
	[12, HI, THI, 0.2, 0.3, 0.5, 0],
	[13, HI, THI, 0.02, 0.05, 0.03, 0.9],
	[14, HI, THI, 0.03, 0.02, 0.05, 0.9],
	[15, HI, THI, 0.03, 0.05, 0.02, 0.9],
#	[16, HI, THI, 0.99, 0.005, 0.005, 0.0],
	[17, HI, THI, 0.005, 0.99, 0.005, 0.0],
	[18, HI, THI, 0.005, 0.005, 0.99, 0.0],
	[19, HI, THI, 0.49, 0.49, 0.02, 0.0],
	[20, HI, THI, 0.02, 0.49, 0.49, 0.0],
	[21, HI, THI, 0.49, 0.02, 0.49, 0.0],
]

def print_testcase(id, hi, tc, podd, pprime, pspoiled, plaza):
	f = open('testcases/{:02}.in'.format(id), 'w')
	f.write('{}\n'.format(tc))
	hir = int(np.sqrt(hi)-2)
	for i in range(tc):
		t = np.random.choice([0, 1, 2, 3], p=[podd, pprime, pspoiled, plaza])
		spoil = 0
		if t == 0:
			ab = np.random.randint(hi // 2, hi)
			a = int(np.exp(np.log(ab) * np.random.rand()) - 2)
			if a < 1:
				a = 1
			a -= (a+1) % 2
			b = ab // a
			b -= (b+1) % 2
		elif t == 1:
			a = np.random.randint(hir // 3, hir)
			b = np.random.randint(hir // 3, hir)
			a = nt.prevprime(a)
			b = nt.prevprime(b)
		elif t == 2:
			a = np.random.randint(hir // 3, hir)
			b = np.random.randint(hir // 3, hir)
			a -= (a+1) % 2
			b -= (b+1) % 2
			spoil = np.random.randint(hir // 3, hir)
		elif t == 3:
			a = 1 + np.random.randint(0, 2**15-1) * 0x10000
			b = 0x100000002 - a
		
		if a*b >= hi:
			print(t)
			raise Exception('Too big')
		if (a*b) % 2 == 0:
			print(t)
			print(a)
			raise Exception('Not odd')

		f.write('{} {}\n'.format(a*b, a^b^spoil))
	f.close()

def print16():
	f = open('testcases/16.in'.format(id), 'w')
	tc = 10000
	ab = 964232161391874375
	divs = divisors(ab)
	np.random.shuffle(divs)
	f.write('{}\n'.format(tc))
	for i in range(tc):
		f.write('{} {}\n'.format(ab, divs[i]))
	f.close()

for tc in cfg:
	print_testcase(*tc)	
print16()