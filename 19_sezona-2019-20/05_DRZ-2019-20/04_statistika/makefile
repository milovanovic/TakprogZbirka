statistika: statistika.cpp
	g++ $< --std=c++14 -O2 -o $@

INDEXES := $(shell seq -w 1 16)
NAMES := $(addprefix testcases/,${INDEXES})
INPUTS := $(addsuffix .in,${NAMES})
OUTPUTS := $(addsuffix .out,${NAMES})

tests: inputs outputs
inputs: ${INPUTS}
outputs: ${OUTPUTS}

times: times.statistika.txt times.brute.txt times.hack.txt times.hack2.txt

times.%.txt: % inputs
	echo "Times for '$<'" > $@
	for f in ${INPUTS}; do \
		echo $$f `(time timeout 5s ./$< < $$f > /dev/null) 2>&1` >> $@; \
	done

testcases/01.in:
	echo -e '3 3 3\n1 2 3\n1 1 2\n3 3 3\n1 1 1 1\n1 1 2 2\n2 2 1 1' > $@
testcases/02.in:
	echo -e '3 3 1\n1 2 3\n2 1 3\n1 9 1\n2 2 1 1' > $@

# Subtask 1 (N, M, Q <= 100)
testcases/03.in:
	./gen.py 3 100 100 100 --max 4 > $@
testcases/04.in:
	./gen.py 4 97 98 100 --offset 481932 > $@
testcases/05.in:
	./gen.py 5 99 99 100 --offset 65537 > $@

# Subtask 2 (N, M <= 300, Q <= 2*10^4)

testcases/06.in:
	./gen.py 6 298 300 20000 --max 1 > $@
testcases/07.in:
	./gen.py 66 298 300 20000 --max 2 > $@
testcases/08.in:
	./gen.py 7 299 295 20000 > $@

# Subtask 3 (A_ij \in {0,1})

testcases/09.in:
	./gen.py 8 1000 1000 100000 --max 1 > $@
testcases/10.in:
	./gen.py 9 994 999 100000 --max 1 > $@

# Subtask 4 (h, w <= 10)

testcases/11.in:
	./gen.py 10 1000 1000 100000 --small > $@
testcases/12.in:
	./gen.py 10 999 997 100000 --small --max 2 > $@

# Subtask 5

testcases/13.in:
	./gen.py 12 1000 1000 100000 --offset 1234567 > $@
testcases/14.in:
	./gen.py 13 999 1000 100000 --max 8 > $@
testcases/15.in:
	./gen.py 14 1000 999 100000 --offset 101010 > $@
testcases/16.in:
	./gen.py 15 1000 1000 100000 --max 1 > $@

testcases/%.out: testcases/%.in statistika
	./statistika < $< > $@

brute: statistika-brute.cpp
	g++ $< --std=c++14 -O2 -o $@

hack: statistikaHack\ -\ allllekssssa.cpp
	g++ "$<" --std=c++14 -O2 -o $@
hack2: tester-hak-2.cpp
	g++ $< --std=c++14 -O2 -o $@
hack3: tester-hak-3.cpp
	g++ $< --std=c++14 -O2 -o $@

clean:
	rm -f statistika brute hack testcases/*.in testcases/*.out times.statistika.txt times.brute.txt times.hack.txt times.statistika.txt

tests.zip: ${INPUTS} ${OUTPUTS}
	zip $@ $^
