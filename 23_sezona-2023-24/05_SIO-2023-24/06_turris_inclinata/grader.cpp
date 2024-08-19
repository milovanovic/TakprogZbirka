#include <bits/stdc++.h>
using namespace std;
void Penjanje(int N,int Q,int *P,int *F,int *U,int *O);

int main()
{
    int N,Q;
    cin >> N >> Q;
    int* P = new int[N+1];
    int* F = new int[N+1];
    int* U = new int[Q+1];
    int* O = new int[Q+1];

    for (int i=1; i<=N; i++) cin >> P[i];
    for (int i=1; i<=N; i++) cin >> F[i];
    for (int i=1; i<=Q; i++) cin >> U[i];

    Penjanje(N,Q,P,F,U,O);

    for(int i=1;i<=Q;i++) cout << O[i] <<endl;

    delete[] P;
    delete[] F;
    delete[] U;
    delete[] O;
}
