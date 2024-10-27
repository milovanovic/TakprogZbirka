#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int seed; cin >> seed;
    mt19937 rng(seed);
    for(int tt = 1; tt <= 22; tt++) {
        string filename; int maxN, minN, poz;
        cin >> filename >> minN >> maxN >> poz;
        ofstream fout; fout.open(filename);
        if(filename == "01.in") {
            fout << 5 << endl;
            fout << 3 << ' ' << 2 << ' ' << 1 << ' ' << 3 << ' ' << 1 << endl;
            fout << 3 << endl;
            fout << 1 << ' ' << 2 << ' ' << 4 << ' ' << 2 << endl;
            fout << 2 << endl;
            fout << 1 << ' ' << 1 << ' ' << 3 << ' ' << 1 << endl;
        } else if(filename == "02.in") {
            fout << 7 << endl;
            fout << 33 << ' ' << 11 << ' ' << 73 << ' ' << 78 << ' ' << 12 << ' ' << 62 << ' ' << 84 << endl;
            fout << 5 << endl;
            fout << 1 << ' ' << 2 << ' ' << 5 << ' ' << 3 << endl;
            fout << 2 << endl;
            fout << 1 << ' ' << 2 << ' ' << 6 << ' ' << -5 << endl;
            fout << 2 << endl;
            fout << 1 << ' ' << 1 << ' ' << 7 << ' ' << 1 << endl;
        } else {
            int N = uniform_int_distribution<int>(minN, maxN)(rng);
            fout << N << endl;
            for(int i = 1; i <= N; i++) {
                fout << uniform_int_distribution<int>(1, 1000)(rng);
                if(i < N) fout << ' ';
                else fout << endl;
            }
            int Q = uniform_int_distribution<int>(minN, maxN)(rng);
            fout << Q << endl;
            for(int i = 1; i <= Q-1; i++) {
                int tip = uniform_int_distribution<int>(1, 2)(rng);
                fout << tip;
                if(tip == 2) fout << endl;
                else {
                    int l = uniform_int_distribution<int>(1, N/6)(rng);
                    int r = uniform_int_distribution<int>(5*N/6, N)(rng);
                    int x;
                    if(poz) x = uniform_int_distribution<int>(1, 1000)(rng);
                    else    x = uniform_int_distribution<int>(-1000, 1000)(rng);
                    fout << ' ' << l << ' ' << r << ' ' << x << endl;
                }
            }
            fout << 2 << endl;
        }
        fout.close();
    }
    return 0;
}

/**
543217
01.in 0 0 0
02.in 0 0 0

03.in 190000 200000 1
04.in 9 9 0
05.in 4500 5000 0
06.in 4500 5000 0
07.in 4500 5000 0
08.in 190000 200000 0
09.in 190000 200000 0
10.in 190000 200000 0
11.in 190000 200000 0
12.in 190000 200000 0

13.in 190000 200000 1
14.in 9 9 0
15.in 4500 5000 0
16.in 4500 5000 0
17.in 4500 5000 0
18.in 190000 200000 0
19.in 190000 200000 0
20.in 190000 200000 0
21.in 190000 200000 0
22.in 190000 200000 0
**/
