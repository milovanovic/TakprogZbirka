#include <bits/stdc++.h>
#define pii pair<int,int>
#define lld long long
#define se second
#define fi first
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
using namespace std;
#define seed 542312
#define MAX1 1000000000000000LL
#define MAX2 1000
int main() {
    mt19937_64 rng(seed);
    for(int i = 1; i <= 23; i++) {
        PRINT(i);
        lld X, Y, T;
        string file = string(1, (char)(i/10+'0'))+string(1, (char)(i%10+'0'))+".in";
        ofstream fout; fout.open(file);
        if(i == 1) {
            X = 5; Y = 4; T = 8;
        } else if(i == 2) {
            X = 3456; Y = 1; T = 1800;
        } else if(i == 3) {
            X = 305; Y = 534; T = 13413413003;
        } else if(4 <= i && i <= 7) {
            X = uniform_int_distribution<long long>(1, 1000000000)(rng);
            Y = uniform_int_distribution<long long>(1, MAX2)(rng);
            T = uniform_int_distribution<long long>(1, min(1000000000LL,2*X))(rng);
        } else if(8 <= i && i <= 13) {
            X = uniform_int_distribution<long long>(1, 100)(rng);
            Y = uniform_int_distribution<long long>(1, MAX2)(rng);
            T = uniform_int_distribution<long long>(2*X+1, MAX2)(rng);
        } else {
            X = uniform_int_distribution<long long>(1, 1000)(rng);
            Y = uniform_int_distribution<long long>(1, MAX2)(rng);
            T = uniform_int_distribution<long long>(MAX1-1000, MAX1)(rng);
        }
        if(i >= 8 && i%3 == 0) T -= T%X;
        fout << X << ' ' << Y << ' ' << T;
        fout.close();
        file = string(1, (char)(i/10+'0'))+string(1, (char)(i%10+'0'))+".out";
        fout.open(file);
        lld rez = 0;
        if(T%X == 0) rez = (T/X)*(X+Y)-Y;
        else rez = (T/X)*(X+Y) + T%X;
        fout << rez;
        fout.close();
    }
    return 0;
}
