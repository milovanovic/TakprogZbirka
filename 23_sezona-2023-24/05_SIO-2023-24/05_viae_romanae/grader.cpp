#include <bits/stdc++.h>
using namespace std;
void Putevi(int N, int M, int Q, int* U, int* V, int* W, int* X, int* Y, int* Ans);

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    int* U = new int[M+1];
    int* V = new int[M+1];
    int* W = new int[M+1];
    int* X = new int[Q+1];
    int* Y = new int[Q+1];
    int* Ans = new int[Q+1];

    for (int i=1; i<=M; i++) cin >> U[i] >> V[i] >> W[i];
    for (int i=1; i<=Q; i++) cin >> X[i] >> Y[i];

    Putevi(N, M, Q, U, V, W, X, Y, Ans);

    for(int i=1;i<=Q;i++) cout << Ans[i] <<endl;

    delete[] U;
    delete[] V;
    delete[] W;
    delete[] X;
    delete[] Y;
    delete[] Ans;
}
