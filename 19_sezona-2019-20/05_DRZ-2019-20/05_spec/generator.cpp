#include<bits/stdc++.h>
using namespace std;

#define MAXN 333555
#define Milion 1000000

#define grMAXN 300000

FILE *fin, *fout;

int n,q;
int a[MAXN],qi[MAXN];

// nije finalno N ako se dodaju 0 na pocetak
int tN[] = {-1, 16,    293993, 290000, 299299, 300000, 295939,    2,   199, 200, 200, 54,  198,    999,  99,  1000, 1000,    300000, 299993, 290290, 300000,   299299, 300000, 250250, 299999, 299970, 299299, 300000, 295255};
int tQ[] = {-1, 7,     299997, 299999, 300000, 295995, 299333,    199, 200, 199, 200, 200, 200,    1000, 997, 999,  1000,    299997, 292929, 289999, 300000,   299298, 299999, 200000, 299999, 298999, 299199, 300000, 300000};
int tSeed[] = {-1, 83473, 2384728, 123283, 39483, 1283728, 34838, 28384, 384738, 183483, 2929, 384838, 29299, 747573, 7436464, 64647, 834737, 3747347, 5654653, 5353, 2338, 384873, 837, 28328, 2883, 8828, 28737, 84812, 3848, 23299, 847772, 2322};

void printTest() {
    fprintf(fin, "%d %d\n", n, q);
    for(int i=0; i<n; i++) fprintf(fin, "%d ", a[i]);
    fprintf(fin, "\n");
    for(int i=0; i<q; i++) fprintf(fin, "%d\n", qi[i]);
    fclose(fin);
}

void genPapirTest() {
    int ta[] = {4, 1, 4, 5, 2, 2, 3, 3, 2, 3, 5, 0, 5, 4, 4, 2};
    int tq[] = {5, 3, 2, 1, 4, 6, 3};
    for(int i=0; i<n; i++) a[i] = ta[i];
    for(int i=0; i<q; i++) qi[i] = tq[i];
    printTest();
}

void dodaj0napoc(int br0) {

    br0 = min(br0, grMAXN - n);

    n += br0;

    for(int i=n-1; i>=br0; i--) {
        a[i] = a[i-br0];
    }

    for(int i=0; i<br0; i++) a[i] = 0;
}

void genQiSub1() {
    for(int i=0; i<q; i++) {
        if (rand()%2 == 0) {
            qi[i] = Milion;
        } else {
            qi[i] = rand() % Milion;
        }
    }
}

void genSub1random(int p0, int p1, int p106) { // verovatnoce u 100k
    
    for(int i=0; i<n; i++) {
        if (rand() % 100000 < p0) {
            a[i] = 0;
        } else if (rand() % 100000 < p1) {
            a[i] = 1;
        } else {
            a[i] = Milion;
        }
    }

    genQiSub1();
    printTest();
}

void genSve0() {
    for(int i=0; i<n; i++) a[i] = 0;
    genQiSub1();
    printTest();
}

void genSub1ravnomerni(int k0, int br106) {

    int tr = 0;
    while(tr < n) {

        int tl = min(k0, n-tr);

        int poc = rand()%4;
        int kr = tl-rand()%4;
        int uk = 4739 + rand()%4;

        int tbr = 2;
        for(int i=0; i<tl; i++) {
            if (i<poc || i>kr) {
                a[tr+i] = 1;
                continue;
            }

            if (i == poc || i == kr) {
                a[tr+i] = Milion;
                tbr++;
                continue;
            }

            if (kr-i+1 == uk-tbr) {
                a[tr+i] = Milion;
                tbr++;
                continue;
            }

            if (rand()%2 == 0) {
                a[tr+i] = Milion;
                tbr++;
            } else {
                a[tr+i] = 1;
            }

        }

        tr += tl;
        a[tr] = 0;
        tr++;
    }

    dodaj0napoc(4);

    genQiSub1();
    printTest();
}

void genN2() {
    a[0] = 3; a[1] = 5;
    for(int i=0; i<q/2; i++) {
        qi[i] = i;
    }
    for(int i=q/2; i<q; i++) {
        qi[i] = rand() % Milion;
    }

    printTest();
}

void genStepeni(bool mrda, bool bez0) {
    int p = 1;
    for(int i=0; i<n; i++) {
        if (a[i] == 0 && i > 0) {
            p++;
            for(long long j=1; i+j-1<n; j*=p) {
                int t = i+j-1;
                if (mrda) {
                    if (t>1 && rand()%2 == 0) t--;
                }
                while(a[t] != 0 && t<n) t++;
                if (t<n) a[t] = p; 
            }
        }
    }

    for(int i=0; i<q; i++) qi[i] = i;
    random_shuffle(qi, qi+q);

    if (bez0) {
        for(int i=0; i<n; i++) if (a[i] == 0) a[i]=1;
        qi[1] = 2;
    }

    printTest();
}

void genSamomali(int p0, int pOst, int maxMali, int maxOstali, bool genQizA) {

    for(int i=0; i<n; i++) {
        if (rand() % 100000 < p0) {
            a[i] = 0;
        } else {
            if (rand() % 100000 < pOst) {
                a[i] = rand()%(maxMali-1) + 2;
            } else {
                a[i] = rand()%(maxOstali - maxMali) + maxMali + 1;
            }
        }
    }

    if (genQizA) {
        for(int i=0; i<q; i++) qi[i] = a[i];
    } else {

        for(int i=0; i<q/2; i++) {
            qi[i] = i;
        }
        for(int i=q/2; i<q; i++) {
            qi[i] = rand() % maxOstali;
        }
    }

    printTest();
}

void genSub2spec() {

    for(int i=0; i<n; i++) a[i] = rand() % (200 - 5) + 5;

    a[0] = 2; a[1] = 2;
    a[81] = 2; a[82] = 2; a[84] = 2; a[85] = 2; a[86] = 2;
    a[197] = 2; a[198] = 2; a[199] = 2;

    a[3] = 3; a[4] = 3;
    a[196] = 3; a[194] = 3; a[191] = 3;

    a[5] = 4; a[7] = 4;
    a[167] = 4; a[168] = 4;

    for(int i=0; i<q/2; i++) {
        qi[i] = i;
    }
    for(int i=q/2; i<q; i++) {
        qi[i] = rand() % 1000;
    }

    printTest();
}

bool mark[MAXN];
void genParovi(int razmak, int brp, int maxbr, bool genQizA, int dod0) {

    for(int i=0; i<n; i++) a[i] = rand() % (Milion - maxbr) + maxbr;

    int tr=0;
    while(tr+razmak < n) {

        int t = rand()%(maxbr-1) + 2;
        for(int j=0; j<brp; j++) {
            int p = rand()%razmak;
            a[tr+p] = t;
        }

        tr += razmak;
        a[tr] = 0;
        tr++;
    }

    dodaj0napoc(dod0);

    if (genQizA) {
        for(int i=0; i<q; i++) qi[i] = a[i];
    } else {
        for(int i=0; i<q/2; i++) {
            qi[i] = i;
        }
        for(int i=q/2; i<q; i++) {
            qi[i] = rand() % Milion;
        }
    }
    random_shuffle(qi, qi+q);

    printTest();
}

void genSub4spec() {

    for(int i=0; i<n; i++) a[i] = rand() % (20000 - 5) + 5;


    //dvojke
    for(int i=0; i<7; i++) a[i] = 2;
    for(int i=n-7; i<n; i++) a[i] = 2;

    int p = 151515;
    for(int i=p; i<p+7; i++) a[i] = 2;
    for(int i=p+8; i<p+8+8; i++) a[i] = 2;

    // trojke
    p=151000;
    for(int i=p; i<p+4; i++) a[i] = 3;
    for(int i=p+5; i<p+5+3; i++) a[i]=3;
    for(int i=9; i<9+3; i++) a[i]=3;
    for(int i=n-15; i<n-15+3; i++) a[i] = 3;

    // 97k
    a[13] = 97000; a[15] = 97000; a[n-17] = 97000;

    

    for(int i=0; i<n; i++) qi[i] = a[i];
    random_shuffle(qi, qi+q);
    qi[0] = 2;
    qi[1] = 3;
    qi[2] = 97000;

    printTest();
}

void genSamo3() {

    for(int i=0; i<n; i++) {
        if (i == 151535) {
            a[i] = 0;
        } else if (rand()%2 == 1) {
            a[i] = 1;
        } else {
            a[i] = 3;
        }
    }

    dodaj0napoc(5);

    for(int i=0; i<q; i++) {
        if (rand()%2 == 1) {
            qi[i] = 3;
        } else {
            qi[i] = rand()%5;
        }
    }

    printTest();
}


int main(int argc, char *argv[]) {

    char sin[55], sout[55];
    strcpy(sin, argv[1]); strcat(sin, ".in");
    //strcpy(sout, argv[1]); strcat(sout, ".out");

    int tt = stoi(argv[1]);

    fin = fopen(sin, "w");
    //fout = fopen(sout, "w");

    srand(tSeed[tt]);

    n = tN[tt];
    q = tQ[tt];

    if (tt == 1) {
        genPapirTest();
    }

    // subtask 1

    if (tt == 2) {
        genSub1random(10, 80000, 20000);
    }

    if (tt == 3) {
        genSub1ravnomerni(10000, 4739);
    }

    if (tt == 4) {
        genSve0();
    }

    if (tt == 5) {
        genSub1random(95000, 0, 5000);
    }

    if (tt == 6) {
        genSub1random(0, 5000, 95000);
    }

    // subtask 2

    if (tt == 7) {
        genN2();
    }

    if (tt == 8) {
        genStepeni(false, false);
    }

    if (tt == 9) {
        genSamomali(1000, 45000, 6, 65, false);
    }

    if (tt == 10) {
        genSub2spec();
    }

    if (tt == 11) {
        genSve0();
    }

    if (tt == 12) {
        genParovi(10, 2, 8, true, 0);
    }

    // subtask 3

    if (tt == 13) {
        genStepeni(true,false);
    }

    if (tt == 14) {
        genSamomali(500, 45000, 10, 10000, true);
    }

    if (tt == 15) {
        genSamomali(10000, 75000, 15, 10000, true);
    }

    if (tt == 16) {
        genParovi(20, 3, 25, true, 0);
    }

    // subtask 4

    if (tt == 17) {
        genSamomali(0, 30000, 30, 10000, true);
    }

    if (tt == 18) {
        genStepeni(true, true);
    }

    if (tt == 19) {
        genParovi(n, 16, 2, true, 0);
    }

    if (tt == 20) {
        genSub4spec();
    }

    // subtask 5

    if (tt == 21) {
        genSve0();
    }

    if (tt == 22) {
        genSub4spec();
    }

    if (tt == 23) {
        genSamomali(1000, 40000, 50, 1000000, true);
    }

    if (tt == 24) {
        genSamomali(9000, 45000, 155, 1000000, true);
    }

    if (tt == 25) {
        genParovi(100, 5, 155, true, 0);
    }

    if (tt == 26) {
        genParovi(1000, 3, 55, true, 97);
    }

    if (tt == 27) {
        genStepeni(true, false);
    }

    if (tt == 28) {
        genSamo3();
    }

    return 0;
}