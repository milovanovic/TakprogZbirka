all: official checker

official: zaboravljena.cpp
	g++ -std=c++14 -O2 $< -o $@

checker: zaboravljena-checker.cpp
	g++ -std=c++14 -O2 $< -o $@

debug-checker: zaboravljena-checker-debug.cpp
	g++ -std=c++14 -O2 $< -o $@
