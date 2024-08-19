g++ -std=gnu++14 -O2 -pipe -static -Wl,--stack=536870912 -o test.exe grader.cpp code.cpp

IF NOT ERRORLEVEL 1 GOTO aok
echo ERROR
GOTO :eof

:aok
echo OK