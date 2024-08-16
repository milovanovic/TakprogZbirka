#include <cstdio>
#include <cstdlib>

#define MAXN 1000
#define MAXM 10

// indeksirano od nule
int M, N;
int A[MAXM];
int X[MAXN], B[MAXN];

int preostalo[MAXN];

void ulaz() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
}

// odredjuje da li se i-ti autobus nalazi u podskupu predstavljenim brojem x
bool u_podskupu(int i, int x) {
    return ((1 << i) & x) > 0;
}

void resi() {
    int broj_podskupova = 1 << M;
    int max_podskup = 0;
    for (int podskup = 0; podskup < broj_podskupova; podskup++) {
        bool ok = true;
        int broj = 0;
        for (int j = 0; j < N; j++) {
            preostalo[j] = B[j];
        }
        for (int i = 0; i < M && ok; i++) {
            if (!u_podskupu(i, podskup)) {
                continue;
            }
            broj++;
            int b = A[i];
            for (int j = 1; j < N && ok; j++) {
                b -= abs(X[j] - X[j - 1]);
                for (int k = j - 1; k >= 0 && b < 0; k--) {
                    if (preostalo[k] > -b) {
                        preostalo[k] -= -b;
                        b = 0;
                    } else {
                        b += preostalo[k];
                        preostalo[k] = 0;
                    }
                }
                if (b < 0) {
                    ok = false;
                }
            }
        }
        if (ok && max_podskup < broj) {
            max_podskup = broj;
        }
    }
    printf("%d\n", max_podskup);
}

int main() {
    ulaz();
    resi();
    return 0;
}