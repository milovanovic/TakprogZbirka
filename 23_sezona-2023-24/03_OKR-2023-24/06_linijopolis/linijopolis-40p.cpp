#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 1000
#define MAXM 1000

// indeksirano od nule
int M, N;
int A[MAXM];
int X[MAXN], B[MAXN];

int skok_do[MAXN];
bool ok = true;

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

int azuriraj(int &b, int i) {
    if (i < 0) {
        ok = false;
        return -1;
    }
    if (B[i] == 0) {
        return azuriraj(b, skok_do[i]);
    }
    if (b >= 0) {
        return i;
    }
    if (B[i] >= -b) {
        B[i] -= -b;
        b = 0;
        return i;
    }
    b += B[i];
    B[i] = 0;
    return (skok_do[i] = azuriraj(b, skok_do[i]));
}

void resi() {
    sort(A, A + M);
    int max_broj = 0;
    for (int i = 0; i < N; i++) {
        skok_do[i] = i - 1;
    }
    for (max_broj = 0; max_broj < M; max_broj++) {
        int b = A[M - max_broj - 1];
        for (int i = 1; i < N && ok; i++) {
            b -= abs(X[i] - X[i - 1]);
            azuriraj(b, i - 1);
        }
        if (!ok) {
            break;
        }
    }
    printf("%d\n", max_broj);
}

int main() {
    ulaz();
    resi();
    return 0;
}