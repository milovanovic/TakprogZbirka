opet_xor: opet_xor.cpp grader.cpp
	g++ $^ -o $@ --std=gnu++14 -O2 -pipe

hack: opet_xor-tester.cpp grader.cpp
	g++ $^ -o $@ --std=gnu++14 -O2 -pipe
hack2: opet_xor-stosic.cpp grader.cpp
	g++ $^ -o $@ --std=gnu++14 -O2 -pipe

INDEXES := $(shell seq -w 1 13)
NAMES := $(addprefix testcases/,${INDEXES})
INPUTS := $(addsuffix .in,${NAMES})
OUTPUTS := $(addsuffix .out,${NAMES})

tests: inputs outputs
inputs: ${INPUTS}
outputs: ${OUTPUTS}

times: times.opet_xor.txt

times.%.txt: % inputs
	echo "Times for '$<'" > $@
	for f in ${INPUTS}; do \
		echo $$f `(time timeout 10s ./$< < $$f > /dev/null) 2>&1` >> $@; \
	done

testcases/%.out: testcases/%.in opet_xor
	./opet_xor < $< > $@


grader.zip: grader.cpp compile_cpp.cmd
	mkdir cpp
	cp grader.cpp compile_cpp.cmd cpp/
	zip $@ cpp/*
	rm -r cpp
tests.zip: ${INPUTS} ${OUTPUTS}
	zip -j $@ $^

clean:
	rm -f testcases/*.in testcases/*.out opet_xor tests.zip grader.zip times.*.txt
	rm -rf cpp
release: grader.zip tests.zip

# Sample

testcases/01.in:
	mkdir -p testcases
	echo -ne '5 3\n1 1 3 3 3\n2 1 3\n1 3 2\n2 1 3\n' > $@

# Subtask 1: Q <= 10, X[i] <= 10 for type-2

testcases/02.in: mktest.py
	mkdir -p testcases
	./mktest.py 20002 1 100000 10 > $@

testcases/03.in: mktest.py
	mkdir -p testcases
	./mktest.py 30001 1 300000 10 > $@

# Subtask 2: N, Q <= 200

testcases/04.in: mktest.py
	mkdir -p testcases
	./mktest.py 4 2 200 200 > $@

testcases/05.in: mktest.py
	mkdir -p testcases
	./mktest.py 5 2 200 200 --mostly_q > $@


# Subtask 3: N, Q <= 5000

testcases/06.in: mktest.py
	mkdir -p testcases
	./mktest.py 6 3 5000 5000 > $@

testcases/07.in: mktest.py
	mkdir -p testcases
	./mktest.py 7 3 5000 5000 --mostly_q > $@


# Subtask 4: N, Q <= 3e5, only type-2

testcases/08.in: mktest.py
	mkdir -p testcases
	./mktest.py 8 4 300000 100000 > $@

testcases/09.in: mktest.py
	mkdir -p testcases
	./mktest.py 9 4 300000 300000 > $@


# Subtask 5: N, Q <= 3e5, A[i] < 64

testcases/10.in: mktest.py
	mkdir -p testcases
	./mktest.py 10 5 300000 100000 > $@

testcases/11.in: mktest.py
	mkdir -p testcases
	./mktest.py 11 5 300000 300000 --mostly_q > $@

# Subtask 6: N, Q <= 3e5

testcases/12.in: mktest.py
	mkdir -p testcases
	./mktest.py 12 6 300000 100000 > $@

testcases/13.in: mktest.py
	mkdir -p testcases
	./mktest.py 13 6 300000 300000 --mostly_q > $@
