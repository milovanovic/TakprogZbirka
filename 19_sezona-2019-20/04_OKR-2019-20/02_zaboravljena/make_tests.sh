#! /bin/bash

mkdir -p testcases

# sample
echo 4 3 5 > testcases/01.in
echo 2 2 4 > testcases/02.in

# subtask 1: n = k = 3, 20 pts
echo 3 3 8 > testcases/03.in
echo 3 3 5 > testcases/04.in
echo 3 3 9 > testcases/05.in
echo 3 3 4 > testcases/06.in

# subtask 2: k = 2, 25 pts
echo 99 2 4951 > testcases/07.in
echo 70 2 2500 > testcases/08.in
echo 11 2 56 > testcases/09.in
echo 100 2 5000 > testcases/10.in
echo 100 2 4 > testcases/11.in

# subtask 3: t <= n^2/4, 25 pts
echo 100 4 2000 > testcases/12.in
echo 90 89 300 > testcases/13.in
echo 99 98 195 > testcases/14.in
echo 100 3 1000 > testcases/15.in
echo 75 75 700 > testcases/16.in

# subtask 4: razno, 30 pts
echo 100 3 10000 > testcases/17.in
echo 100 3 9999 > testcases/18.in
echo 95 95 9020 > testcases/19.in
echo 99 99 9800 > testcases/20.in
echo 87 43 7567 > testcases/21.in
echo 100 99 10000 > testcases/22.in

# solution (just "1" if possible and "0" otherwise)

for f in testcases/*.in; do
    ./official < $f | grep nemoguce > /dev/null
    echo $? > ${f//.in}.out
done

# check

for f in testcases/*.in; do
    sol=${f//.in}.out
    ./checker <(./official < $f) $sol $f
    echo $f $?
done
