#include <bits/stdc++.h>
using namespace std;

void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O);

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int *A = new int[N + 1];
    int *T = new int[Q + 1];
    int *T_mem = new int[Q + 1];
    int *I = new int[Q + 1];
    int *X = new int[Q + 1];
    bool *O = new bool[Q + 1];

    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 1; i <= Q; i++) {
        scanf("%d %d %d", &T[i], &I[i], &X[i]);
        T_mem[i] = T[i];
        O[i] = false;
    }

    Resi(N, A, Q, T, I, X, O);

    for(int i = 1; i <= Q; i++) {
        if(T_mem[i] == 2) {
            printf("%d\n", O[i] ? 1 : 0);
        }
    }

    delete[] A;
    delete[] T;
    delete[] T_mem;
    delete[] I;
    delete[] X;
    delete[] O;
    return 0;
}
