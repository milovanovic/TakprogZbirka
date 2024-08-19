#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 3000000
using namespace std;
int n,k;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    n = inf.readInt(1, 100000, "N");
    inf.readSpace();
    k = inf.readInt(1, n, "K");
    inf.readEoln();
    for(int i=1;i<=n;i++) {
        inf.readInt(0, 1000000000,"A");
        if(i!=n) inf.readSpace();
        else inf.readEoln();
    }
    inf.readEof();
}
