slova: slova.cpp
	g++ $< -o $@ --std=c++14 -O2

INDEXES := $(shell seq -w 1 12)
NAMES := $(addprefix testcases/,${INDEXES})
INPUTS := $(addsuffix .in,${NAMES})
OUTPUTS := $(addsuffix .out,${NAMES})

tests: inputs outputs
inputs: ${INPUTS}
outputs: ${OUTPUTS}

testcases/%.out: testcases/%.in slova
	./slova < $< > $@

tests.zip: ${INPUTS} ${OUTPUTS}
	zip -j $@ $^
clean:
	rm -f testcases/*.in testcases/*.out slova tests.zip
release: tests.zip

# sample

testcases/01.in: slova-st.md
	gawk '/~~~/ { test++; next }; test == 1 { print $$0 }' < $< > $@
testcases/02.in: slova-st.md
	gawk '/~~~/ { test++; next }; test == 5 { print $$0 }' < $< > $@

# Subtask 1: N <= 26

testcases/03.in:
	echo -n -e '26\nABCDEFGHIJKLMNOPQRSTUVWXYZ' > $@

# Subtask 2: N <= 27

testcases/04.in:
	echo -n -e '27\nABCDEFGHIJKZLMNOPQRSTUVWXYY' > $@
testcases/05.in:
	echo -n -e '27\nABCDEFGHIJKZLMNOPQRSTUVWXYZ' > $@

# Subtask 3: N <= 3000

testcases/06.in: blocks.py addrand.py
	./blocks.py 2000 1006 | ./addrand.py 1000 2006 > $@
testcases/07.in: blocks.py addrand.py
	./blocks.py 2900 1007 | ./addrand.py 100 2007 --all > $@
testcases/08.in: blocks.py addrand.py
	./blocks.py 300 1008 | ./addrand.py 2700 2008 --prepend-all > $@

# Subtask 4: N <= 1e6

testcases/09.in: blocks.py addrand.py
	./blocks.py 600000 1009 | ./addrand.py 400000 2009 --prepend-all  > $@
testcases/10.in: blocks.py addrand.py
	./blocks.py 950000 1010 | ./addrand.py 50000 2010 --all > $@
testcases/11.in: blocks.py addrand.py
	./blocks.py 800000 1011 | ./addrand.py 200000 2011 > $@
testcases/12.in: blocks.py addrand.py
	./blocks.py 100000 1012 | ./addrand.py 900000 2012 --prepend-all  > $@
