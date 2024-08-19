#include <bits/stdc++.h>
using namespace std;
const string folder="testcases\\";
void Formacija(int N, int* P, int* Q, int* R, long long& Slabost);

int main()
{
    int testcases = 30;
    for(int tc=1;tc<=testcases;tc++)
    {
        ifstream in(folder+to_string(tc)+".in");
        ofstream out(folder+to_string(tc)+".out", std::ios_base::app);
        int N;
        in >> N;
        int *P = new int[N+1], *Q = new int[N+1], *R = new int[N+1];
        long long Slabost;
        for (int i = 1; i <= N; i++){
            in >> P[i];
        }
        for (int i = 1; i <= N; i++){
            in >> Q[i];
        }
        Formacija(N, P, Q, R, Slabost);

        out << Slabost << '\n';

        delete[] P;
        delete[] Q;
        delete[] R;
    }
}
