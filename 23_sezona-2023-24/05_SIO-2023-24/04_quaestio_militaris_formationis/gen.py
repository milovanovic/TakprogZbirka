import random
import os

test_nr = 0
def gen(N, requires_combination):
    global test_nr
    test_nr = test_nr + 1
    p, q = [a for a in range(1, N + 1)], [a for a in range(1, N + 1)]
    random.shuffle(p)
    random.shuffle(q)
    while(p == q):
        random.shuffle(q)
    
    filename = '04_quaestio_militaris_formationis/testcases/' + str(test_nr) + '.in'
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, 'w') as f:
        f.write(str(N) + '\n')
        f.write(' '.join(map(str, p)) + '\n')
        f.write(' '.join(map(str, q)) + '\n')

    filename = '04_quaestio_militaris_formationis/testcases/' + str(test_nr) + '.out'
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, 'w') as f:
        f.write(str(requires_combination) + '\n')

# Subtask 1
gen(5, 1)
gen(7, 1)
gen(8, 1)
gen(9, 1)
gen(10, 1)

# Subtask 2
gen(12, 1)
gen(13, 1)
gen(14, 1)
gen(15, 1)
gen(16, 1)

# Subtask 3
gen(1000, 0)
gen(2000, 0)
gen(2500, 0)
gen(2750, 0)
gen(3000, 0)

# Subtask 3
gen(200000, 0)
gen(300000, 0)
gen(400000, 0)
gen(450000, 0)
gen(500000, 0)

# Subtask 4
gen(1000, 1)
gen(2000, 1)
gen(2500, 1)
gen(2750, 1)
gen(3000, 1)

# Subtask 5
gen(200000, 1)
gen(300000, 1)
gen(400000, 1)
gen(450000, 1)
gen(500000, 1)