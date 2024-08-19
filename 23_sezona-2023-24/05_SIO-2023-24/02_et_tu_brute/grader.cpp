#include <bits/stdc++.h>
using namespace std;
int Cezar(int N,int K,int *A);

int main()
{
    int N,K;
    cin >> N >> K;
    int* A = new int[N+1];

    for (int i=1; i<=N; i++) cin >> A[i];


    cout << Cezar(N,K,A) <<endl;

    delete[] A;
}
