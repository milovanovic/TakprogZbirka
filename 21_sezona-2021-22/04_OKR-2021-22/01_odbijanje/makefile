odbijanje: odbijanje.cpp
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

testcases/%.out: testcases/%.in odbijanje
	./odbijanje < $< > $@

tests.zip: ${INPUTS} ${OUTPUTS}
	zip -j $@ $^
clean:
	rm -f testcases/*.in testcases/*.out odbijanje checker tests.zip
release: tests.zip

# sample

testcases/01.in: odbijanje-st.md
	gawk '/```/ { test++; next }; test == 1 { print $$0 }' < $< > $@
testcases/02.in: odbijanje-st.md
	gawk '/```/ { test++; next }; test == 5 { print $$0 }' < $< > $@

# Subtask 1: N <= 100, Si <= 100, abs Xi <= 100

testcases/03.in: mktest.py
	./mktest.py 3 1 50 50 100 100 4000 4001 > $@

testcases/04.in: mktest.py
	./mktest.py 4 1 70 30 100 100 2331 2330 > $@

testcases/05.in: mktest.py
	./mktest.py 5 1 45 55 100 100 4321 4321 > $@

# Subtask 2: N <= 1000, Si <= 1000

testcases/06.in: mktest.py
	./mktest.py 6 2 555 444 1000000000 1000 400000 400000 > $@

testcases/07.in: mktest.py
	./mktest.py 7 2 200 800 1000000000 1000 140001 140000 > $@

# Subtask 3: N <= 5000

testcases/08.in: mktest.py
	./mktest.py 8 3 3000 2000 1000000000 1000000000 1900000000000 1900000000001 > $@

testcases/09.in: mktest.py
	./mktest.py 9 3 2444 2555 1000000000 1000000000 1700000000001 1700000000000 > $@

# Subtask 4: N <= 5 * 10^4

testcases/10.in: mktest.py
	./mktest.py 10 4 30000 20000 1000000000 1000000000 14444000000000 14444000000000 > $@

testcases/11.in: mktest.py
	./mktest.py 11 4 25000 25000 1000000000 1000000000 22222000000001 22222000000000 > $@

testcases/12.in: mktest.py
	./mktest.py 12 4 22000 28000 1000000000 1000000000 19999000000000 19999000000001 > $@
