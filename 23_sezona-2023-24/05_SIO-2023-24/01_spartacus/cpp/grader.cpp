#include <bits/stdc++.h>
using namespace std;
void OdrediVreme(int N, int M, int* S, int* U, int* V, int* T);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M; cin >> N >> M;
    int* S = new int[N + 1];
    int* U = new int[M + 1];
    int* V = new int[M + 1];
    int* T = new int[N + 1];

    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= M; i++) cin >> U[i] >> V[i];

    OdrediVreme(N, M, S, U, V, T);

    for (int i = 1; i <= N; i++) cout << T[i] << " ";
    cout << endl;

    delete[] S;
    delete[] U;
    delete[] V;
    delete[] T;
}
