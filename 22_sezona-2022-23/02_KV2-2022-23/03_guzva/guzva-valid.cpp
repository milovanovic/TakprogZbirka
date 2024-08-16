#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 200000
using namespace std;

int main(int argc, char* argv[])
{

    registerValidation(argc, argv);

    int n = inf.readInt(2, 1000000, "n");
    inf.readSpace();
    int m = inf.readInt(2, 1000000, "m");
    inf.readEoln();
    ensuref(n*m<=1000000,"nm");
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int a=inf.readInt(1, 1000000000, "a");
            if(j<m) inf.readSpace();
            else inf.readEoln();
        }
    }
    int q=inf.readInt(1, 500000, "q");
    inf.readEoln();
    while(q--) {
        int x,y;
        x = inf.readInt(1, n, "x");
        inf.readSpace();
        y = inf.readInt(1, m, "y");
        inf.readEoln();
        ensuref(x!=1 || y!=1, "hotel");
        ensuref(x!=n || y!=m, "stadion");
    }
    inf.readEof();
    return 0;

}
