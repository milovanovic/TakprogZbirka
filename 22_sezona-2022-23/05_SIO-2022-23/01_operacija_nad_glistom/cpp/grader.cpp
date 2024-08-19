#include <bits/stdc++.h>
using namespace std;
int Resi(int N,int *A);

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int* A = new int[N+1];

    for (int i=0; i<N; i++) cin >> A[i];

    cout << Resi(N, A);

    delete[] A;
}
