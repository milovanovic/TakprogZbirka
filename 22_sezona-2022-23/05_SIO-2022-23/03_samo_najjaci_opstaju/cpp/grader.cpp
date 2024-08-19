#include <bits/stdc++.h>
using namespace std;
void Init(int N,int *A);
int Query(int L,int R);
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    int* A = new int[N+1];
    int* L = new int[Q+1];
    int* R = new int[Q+1];

    for (int i=1; i<=N; i++) cin >> A[i];

    Init(N, A);

    for(int i=1; i<=Q; i++)
    {
        cin>>L[i]>>R[i];
        cout<<Query(L[i],R[i])<<endl;
    }

    delete[] A;
    delete[] L;
    delete[] R;
}
