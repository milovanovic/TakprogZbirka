#include <bits/stdc++.h>
using namespace std;
void Init(int N,int *A);
int Query(int L,int R);

const string folder="testcases\\";
int main()
{
    for(int tc=27;tc<=27;tc++)
    {
    ifstream in(folder+to_string(tc)+".in");
    ofstream out(folder+to_string(tc)+".out");
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N,Q;
    in >> N >> Q;
    int* A = new int[N+1];
    int* L = new int[Q+1];
    int* R = new int[Q+1];

    for (int i=1; i<=N; i++) in >> A[i];

    Init(N, A);

    for(int i=1; i<=Q; i++)
    {
        in>>L[i]>>R[i];
        out<<Query(L[i],R[i])<<endl;
    }

    delete[] A;
    delete[] L;
    delete[] R;
    }
}
