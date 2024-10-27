#include<bits/stdc++.h>
using namespace std;

#define MAXN 2333555
#define MAXSM 1000000

int n;
long long e;
int s[MAXN],m[MAXN],cnt[MAXSM+10],ps[MAXN],pm[MAXN];

// 1: s[i] = 0, n <= 500 000 (20 = 4 primera)
// 2: m[i] = 0, n <= 500 000 (25 = 5 primera)
// 3: n <= 1000 (35 = 7 primera)
// 4: n <= 500 000 (20 = 4 primera)

// 1. n = 17350, s[i] = 0, resenje n/2 + random(n/2), 574
// 2. n = 173555, s[i] = 0, resenje n/2 + random(n/2), 2922
// 3. n = 335333, s[i] = 0, resenje n - random(n/10), 283729
// 4. n = 499999, s[i] = 0, resenje n/4 + random(n/2), 123872

// 5. n = 27350, m[i] = 0, resenje uk/2 + random(uk/2), 34534
// 6. n = 173555, m[i] = 0, resenje uk/2 + random(uk/2), 123123
// 7. n = 300400, m[i] = 0, resenje uk/4 + random(uk/2), 1232
// 8. n = 355455, m[i] = 0, resenje uk - random(uk/10), 6565
// 9. n = 499997, m[i] = 0, resenje uk/2 + random(uk/2), 2039

// 10. n = 1, s[1] = 999999, m[1] = 356789, resenje maxe - 2, 879348
// 11. n = 37, resenje max tacno, 239048
// 12. n = 950, resenje uk/2 + random(uk/2), 37843
// 13. n = 977, resenje uk/4 + random(uk/2), 39849
// 14. n = 998, resenje uk/4 + random(uk/2), 93738
// 15. n = 999, resenje uk - random(10), 398439
// 16. n = 1000, resenje uk - random(uk/10), 349839

// 17. n = 170490, resenje uk - random(10), 394839
// 18. n = 285495, resenje uk/4 + random(uk/2), 9438
// 19. n = 399499, max - 1, 94893
// 20. n = 499995, resenje uk - random(uk/3), 29838

int tN[25] = {0, 17350, 173555, 435333, 499999, 27350, 273555, 400400, 455455, 499997, 1, 37, 950, 977, 998, 999, 1000, 490490, 495495, 499499, 499995};
int sZ[25] = {0, 1, 1, 1, 1}; // koji primeri su s[i] = 0
int sM[25] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}; // koji primeri su m[i] = 0;

int tSM[25] = {0, 4, 4, 4, 4,    5, 5, 6, 6, 7,    5, 5, 5, 5, 5, 5, 5,    6, 6, 6, 6};
int tMM[25] = {0, 4, 4, 4, 4,    5, 5, 6, 6, 7,    5, 5, 5, 5, 5, 5, 5,    6, 6, 6, 6};

// 1 -> resenje uk/2 + random(uk/2)
// 2 -> resenje uk - random(uk/10)
// 3 -> resenje uk - random(10)
// 4 -> resenje uk - random(uk/3)
// 5 -> max
// 6 -> max - 1
// 7 -> resenje uk/4 + random(uk/2)
int tE[25] = {0,   1, 1, 2, 7,    1, 1, 7, 2, 1,    5, 5, 1, 7, 7, 3, 2,      3, 7, 6, 4};

int tSeed[25] = {0, 574, 2922, 283729, 12387, 34534, 123123, 1232, 6565, 2039, 879348, 239048, 37843, 39849, 93738, 398439, 349839, 394839, 9438, 94893, 29838};

int main(int argc, char *argv[]) {

    char sin[55], sout[55];
    strcpy(sin, argv[1]); strcat(sin, ".in");
    strcpy(sout, argv[1]); strcat(sout, ".out");

    int tt = stoi(argv[1]);

    FILE *fin = fopen(sin, "w");
    FILE *fout = fopen(sout, "w");

    n = tN[tt];

    srand(tSeed[tt]);

    for(int i=0; i<n; i++) {
        if (sZ[tt] == 1) {
            s[i] = 0;
        } else {
            if (rand()%tSM[tt] == 0) {
                s[i] = rand() % 100;
            } else {
                s[i] = MAXSM - rand()%(MAXSM/2);
            }
        }
    }

    for(int i=0; i<n; i++) {
        if (sM[tt] == 1) {
            m[i] = 0;
        } else { 
            if (rand()%tMM[tt] == 0) {
                m[i] = rand() % 100;
            } else {
                m[i] = MAXSM - rand()%(MAXSM/2);
            }
        }
    }

    if (tt == 10) {
        s[0] = 999999;
        m[0] = 356789;
    } 

    for(int i=0; i<n; i++) {
        ps[i] = s[i];
        pm[i] = m[i];
    }

    int mbr = 0;

    for(int i=0; i<n; i++) {
        cnt[m[i]]++;
        mbr++;
        while(s[i] > 0) {
            cnt[s[i]]++;
            s[i] /= 2;
            mbr++;
        }
    }

    int brk;
    // 1 -> resenje uk/2 + random(uk/2)
    // 2 -> resenje uk - random(uk/10)
    // 3 -> resenje uk - random(10)
    // 4 -> resenje uk - random(uk/3)
    // 5 -> max
    // 6 -> max - 1
    // 7 -> resenje uk/4 + random(uk/2)
    if (tE[tt] == 1) {
        brk = mbr/2 + rand()%(mbr/2);
    } else if (tE[tt] == 2) {
        brk = mbr - rand()%(mbr/10);
    } else if (tE[tt] == 3) {
        brk = mbr - rand()%10;
    } else if (tE[tt] == 4) {
        brk = mbr - rand()%(mbr/3);
    } else if (tE[tt] == 5) {
        brk = mbr;
    } else if (tE[tt] == 6) {
        brk = mbr - 1;
    } else if (tE[tt] == 7) {
        brk = mbr/4 + rand()%(mbr/2);
    }

    int res = 0;
    for(int i=MAXSM; i>=1; i--) {
        while(cnt[i] > 0 && res < brk) {
            e += i;
            cnt[i]--;
            res++;
        }
    }

    if (tt == 10) {
        e -= 2;
        res--;
    }

    fprintf(fin, "%d %lld\n", n, e);
    for(int i=0; i<n; i++) fprintf(fin, "%d ", ps[i]); fprintf(fin, "\n");
    for(int i=0; i<n; i++) fprintf(fin, "%d ", pm[i]); fprintf(fin, "\n");
    fclose(fin);

    fprintf(fout, "%d\n", res);
    fclose(fout);

    return 0;
}