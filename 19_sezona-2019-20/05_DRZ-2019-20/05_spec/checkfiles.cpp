#include<bits/stdc++.h>
using namespace std;

FILE *fin;

int n,q;

void checkSub1() {

    fscanf(fin,"%d%d", &n, &q);
    assert(n >= 1 && n <= 300000);
    assert(q >= 1 && q <= 300000);

    for(int i=0; i<n; i++) {
        int ai;
        fscanf(fin,"%d", &ai);
        assert(ai == 0 || ai == 1 || ai == 1000000);
    }

    for(int i=0; i<q; i++) {
        int qi;
        fscanf(fin,"%d", &qi);
        assert(qi >= 0 && qi <= 1000000);
    }
}

void checkSub2345(int maxn, int maxq, bool nesme0) {
    fscanf(fin,"%d%d", &n, &q);
    assert(n >= 1 && n <= maxn);
    assert(q >= 1 && q <= maxq);

    for(int i=0; i<n; i++) {
        int ai;
        fscanf(fin,"%d", &ai);
        assert(ai >= 0 && ai <= 1000000);
        assert(!nesme0 || ai != 0);
    }

    for(int i=0; i<q; i++) {
        int qi;
        fscanf(fin,"%d", &qi);
        assert(qi >= 0 && qi <= 1000000);
    }
}

int main() {

    for(int t=2; t<=28; t++) {
        char sin[55], sout[55];
        sprintf(sin, "%d.in", t);
        fin = fopen(sin, "r");

        if (t >= 2 && t <= 6) checkSub1();
        if (t >= 7 && t <= 12) checkSub2345(200, 200, false);
        if (t >= 13 && t <= 16) checkSub2345(1000, 1000, false);
        if (t >= 17 && t <= 20) checkSub2345(300000, 300000, true);
        if (t >= 21 && t <= 28) checkSub2345(300000, 300000, false);

        printf("%d ok\n", t);

        fclose(fin);
    }

    return 0;
}