karte2: karte2.cpp
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
	rm -f testcases/*.in testcases/*.out karte2 tests.zip stats.txt
release: tests.zip

# sample

testcases/01.in: karte2-st.md
	@mkdir -p testcases
	gawk '/~~~/ { test++; next }; test == 1 { print $$0 }' < $< > $@
testcases/02.in: karte2-st.md
	@mkdir -p testcases
	gawk '/~~~/ { test++; next }; test == 5 { print $$0 }' < $< > $@

testcases/%.in: maketest.py
	@mkdir -p testcases
	./maketest.py $* > $@

testcases/%.out: testcases/%.in karte2
	./karte2 < $< > $@

stats.txt: karte2 ${OUTPUTS}
	for f in ${OUTPUTS}; do echo $$f && sort $$f | uniq -c; done > $@

