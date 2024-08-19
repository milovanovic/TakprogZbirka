#include <bits/stdc++.h>
#include "testlib.h"

const int minN = 1;
const int maxN = 200;
 
const int minK = 0;
const int maxK = 500;

const int minS = 0;
const int maxS = 1000;

using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
 
    int N = inf.readInt(minN, maxN, "N");
    inf.readSpace();
    int K = inf.readInt(minK, maxK, "K");
    inf.readEoln();

    for (int i = 0; i < N; i++) {
        int p = inf.readInt(0, N, "p_i");
        ensure(p != i+1);
        if (i != N-1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        inf.readInt(minS, maxS, "s_i");
        if (i != N-1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        inf.readInt(0, K, "k_i");
        if (i != N-1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    inf.readEof();
}