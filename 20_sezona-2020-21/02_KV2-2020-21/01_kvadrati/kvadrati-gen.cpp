#include <bits/stdc++.h>
#define pii pair<int,int>
#define se second
#define fi first
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
using namespace std;
string filename; int maxX, seed, rez;

pii tacka(mt19937 &rng) { return make_pair(uniform_int_distribution<int>(-maxX, maxX)(rng), uniform_int_distribution<int>(-maxX, maxX)(rng)); }

void gen0(mt19937 &rng) {
    pii A = tacka(rng);
    pii B;
    while(1) {
        B = tacka(rng);
        if(A != B && abs(A.fi-B.fi) != abs(A.se-B.se) && A.fi != B.fi && A.se != B.se) break;
    }
    cout << A.fi << ' ' << A.se << '\n';
    cout << B.fi << ' ' << B.se << '\n';
}
void gen1(mt19937 &rng) {
    pii A = tacka(rng);
    int minn = min({maxX-A.fi, maxX-A.se, A.fi+maxX, A.se+maxX});
    int dist = uniform_int_distribution<int>(1, minn)(rng);
    int dx = uniform_int_distribution<int>(0, 1)(rng);
    int dy = uniform_int_distribution<int>(0, 1)(rng);
    pii B;
    B.fi = A.fi + (dx ? dist:-dist);
    B.se = A.se + (dy ? dist:-dist);
    cout << A.fi << ' ' << A.se << '\n';
    cout << B.fi << ' ' << B.se << '\n';
}
void gen2(mt19937 &rng) {
    pii A = tacka(rng);
    pii B;
    int type = uniform_int_distribution<int>(0, 1)(rng);
    if(type) {
        B.fi = A.fi;
        while(1) {
            B.se = uniform_int_distribution<int>(-maxX, maxX)(rng);
            if(B.se != A.se) break;
        }
    } else {
        B.se = A.se;
        while(1) {
            B.fi = uniform_int_distribution<int>(-maxX, maxX)(rng);
            if(B.fi != A.fi) break;
        }
    }
    cout << A.fi << ' ' << A.se << '\n';
    cout << B.fi << ' ' << B.se << '\n';
}

int main() {
    cin >> filename >> maxX >> seed >> rez;
    freopen(filename.c_str(), "w", stdout);
    mt19937 rng(seed);
    if(filename == "01.in") {
        cout << 1 << ' ' << 1 << '\n';
        cout << 3 << ' ' << 3 << '\n';
        return 0;
    } else if(filename == "02.in") {
        cout << 56 << ' ' << 34 << '\n';
        cout << 105 << ' ' << 34 << '\n';
    } else {
        if(rez == 0) gen0(rng);
        else if(rez == 1) gen1(rng);
        else gen2(rng);
    }
    return 0;
}
