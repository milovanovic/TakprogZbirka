#include <bits/stdc++.h>
using namespace std;

void Formacija(int N, int* P, int* Q, int* R, long long& Slabost);

int main(){
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int *P = new int[N+1], *Q = new int[N+1], *R = new int[N+1];
    long long Slabost;
    for (int i = 1; i <= N; i++){
        cin >> P[i];
    }
    for (int i = 1; i <= N; i++){
        cin >> Q[i];
    }
    Formacija(N, P, Q, R, Slabost);

    cout << Slabost << '\n';
    for (int i = 1; i <= N; i++){
        cout << R[i] << ' ';
    }

    delete[] P;
    delete[] Q;
    delete[] R;
}
