#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";
int Cezar(int N,int K,int *A);

int main()
{
    int testcases=50;
    for(int tc=1;tc<=testcases;tc++)
    {
        ifstream in(folder+to_string(tc)+".in");
        ofstream out(folder+to_string(tc)+".out");
        int N,K;
        in >> N >> K;
        int* A = new int[N+1];

        for (int i=1; i<=N; i++) in >> A[i];


        out << Cezar(N,K,A) <<endl;

        delete[] A;
    }

}
