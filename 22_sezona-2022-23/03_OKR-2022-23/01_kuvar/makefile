kuvar: kuvar.cpp
	g++ $< -o $@ --std=c++14 -O2

kuvar-hack: kuvar-hack.cpp
	g++ $< -o $@ --std=c++14 -O2

INDEXES := $(shell seq -w 1 12)
NAMES := $(addprefix testcases/,${INDEXES})
INPUTS := $(addsuffix .in,${NAMES})
OUTPUTS := $(addsuffix .out,${NAMES})

tests: inputs outputs
inputs: ${INPUTS}
outputs: ${OUTPUTS}

times: times.kuvar.txt times.kuvar-hack.txt

times.%.txt: % inputs
	echo "Times for '$<'" > $@
	for f in ${INPUTS}; do \
		echo $$f `(time timeout 10s ./$< < $$f > /dev/null) 2>&1` >> $@; \
	done


testcases/%.out: testcases/%.in kuvar
	./kuvar < $< > $@

tests.zip: ${INPUTS} ${OUTPUTS}
	zip -j $@ $^
clean:
	rm -f testcases/*.in testcases/*.out kuvar checker tests.zip times.*.txt
release: tests.zip

# Sample

testcases/01.in: kuvar-st.md
	gawk '/```/ { test++; next }; test == 1 { print $$0 }' < $< > $@

testcases/02.in: kuvar-st.md
	gawk '/```/ { test++; next }; test == 5 { print $$0 }' < $< > $@

# Subtask 1: N <= 1e3, z[i] = i

testcases/03.in: mktest.py
	./mktest.py 3 1 1000 --frachard 10 > $@

testcases/04.in: mktest.py
	./mktest.py 4 1 1000 --frachard 95 > $@


# Subtask 2: N <= 1e3

testcases/05.in: mktest.py
	./mktest.py 5 2 1000 --frachard 47 > $@

testcases/06.in: mktest.py
	./mktest.py 6 2 1000 --frachard 62 > $@


# Subtask 3: N <= 1e5, z[i] = z[0]

testcases/07.in: mktest.py
	./mktest.py 7 3 100000 --frachard 77 --veryhard > $@


# Subtask 4: N <= 1e5, z[i] = i

testcases/08.in: mktest.py
	./mktest.py 8 4 100000 --frachard 50 > $@

testcases/09.in: mktest.py
	./mktest.py 9 4 100000 --frachard 46 > $@

# Subtask 5: N <= 1e5

testcases/10.in: mktest.py
	./mktest.py 10 5 100000 --frachard 35 --veryhard > $@

testcases/11.in: mktest.py
	./mktest.py 11 5 100000 --frachard 40 > $@

testcases/12.in: mktest.py
	./mktest.py 12 5 100000 --frachard 30 --veryhard > $@
