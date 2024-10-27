transfuzija: transfuzija.cpp
	g++ $< -o $@ --std=c++14 -O2

checker: checker.cpp
	g++ $< -o $@ --std=c++14 -O2

INDEXES := $(shell seq -w 1 12)
NAMES := $(addprefix testcases/,${INDEXES})
INPUTS := $(addsuffix .in,${NAMES})
OUTPUTS := $(addsuffix .out,${NAMES})

tests: inputs outputs
inputs: ${INPUTS}
outputs: ${OUTPUTS}

testcases/%.out: testcases/%.in transfuzija
	./transfuzija < $< > $@

tests.zip: ${INPUTS} ${OUTPUTS}
	zip -j $@ $^
clean:
	rm -f testcases/*.in testcases/*.out transfuzija checker tests.zip
release: tests.zip

# sample

testcases/01.in: transfuzija-st.md
	gawk '/~~~/ { test++; next }; test == 1 { print $$0 }' < $< > $@
testcases/02.in: transfuzija-st.md
	gawk '/~~~/ { test++; next }; test == 5 { print $$0 }' < $< > $@

# Subtask 1: samo A i O

testcases/03.in: mktest.py
	./mktest.py 3 10000 333222 666666 0 0 --improve --extra > $@

testcases/04.in: mktest.py
	./mktest.py 4 10000 700000 200000 0 0 --improve --smallimprove > $@

testcases/05.in: mktest.py
	./mktest.py 5 10000 500000 500000 0 0 --impossible > $@

# Subtask 2: A, B, O

testcases/06.in: mktest.py
	./mktest.py 6 10000 300000 300000 300000 0 --improve --extra > $@

testcases/07.in: mktest.py
	./mktest.py 7 10000 100000 600000 290000 0 --improve --smallimprove > $@

testcases/08.in: mktest.py
	./mktest.py 8 10000 30000 5000 3000 0 --improve --smallimprove > $@

# Subtask 3: full

testcases/09.in: mktest.py
	./mktest.py 9 10000 300000 200000 200000 100000 --improve --extra > $@

testcases/10.in: mktest.py
	./mktest.py 10 10000 50000 10000 10000 12345 --improve --smallimprove > $@

testcases/11.in: mktest.py
	./mktest.py 11 10000 666666 111111 111111 66666 --improve --smallimprove > $@

testcases/12.in: mktest.py
	./mktest.py 12 10000 50000 600000 10000 300000 --improve --smallimprove > $@
