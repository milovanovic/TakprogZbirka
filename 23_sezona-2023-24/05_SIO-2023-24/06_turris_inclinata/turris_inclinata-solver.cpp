#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";
void Penjanje(int N,int Q,int *P,int *F,int *U,int *O);

int main()
{
    int testcases=80;
    for(int tc=1;tc<=testcases;tc++)
    {
        ifstream in(folder+to_string(tc)+".in");
        ofstream out(folder+to_string(tc)+".out");
        int N,Q;
        in >> N >> Q;
        int* P = new int[N+1];
        int* F = new int[N+1];
        int* U = new int[Q+1];
        int* O = new int[Q+1];

        for (int i=1; i<=N; i++) in >> P[i];
        for (int i=1; i<=N; i++) in >> F[i];
        for (int i=1; i<=Q; i++) in >> U[i];

        Penjanje(N,Q,P,F,U,O);

        for(int i=1;i<=Q;i++) out << O[i] <<endl;

        delete[] P;
        delete[] F;
        delete[] U;
        delete[] O;
    }
}
