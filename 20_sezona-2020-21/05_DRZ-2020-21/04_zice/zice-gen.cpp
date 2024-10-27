#include <bits/stdc++.h>
#define MAXN 300010
#define PRINT(x) cerr<<#x<<'='<<x<<endl;
using namespace std;
int A[MAXN], B[MAXN];
vector<pair<int,int> > p;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int seed; cin >> seed;
    mt19937 rng(seed);
    for(int i = 1; i <= 17; i++) {
        string filename; int minN, maxN, tip;
        cin >> filename >> minN >> maxN >> tip;
        ofstream fout; fout.open(filename);
        p.clear();
        if(filename == "01.in") {
            fout << 4 << endl;
            fout << 1 << ' ' << 3 << ' ' << 7 << ' ' << 9 << endl;
            fout << 7 << ' ' << 1 << ' ' << 2 << ' ' << 8 << endl;
        } else if(filename == "02.in") {
            fout << 6 << endl;
            fout << 7 << ' ' << 9 << ' ' << 8 << ' ' << 5 << ' ' << 4 << ' ' << 6 << endl;
            fout << 9 << ' ' << 7 << ' ' << 8 << ' ' << 2 << ' ' << 3 << ' ' << 6 << endl;
        } else if(filename == "11.in") {
            int N = 5000;
            fout << 5000 << endl;
            for(int i = 1; i <= 2500; i++) A[i] = i;
            for(int i = 2501; i <= 5000; i++) A[i] = i+2;
            B[1] = 2501;
            B[5000] = 2502;
            for(int i = 2; i <= 2500; i++) B[i] = i;
            for(int i = 2501; i < 5000; i++) B[i] = i+2;
            for(int i = 1; i <= N; i++) p.push_back({A[i], B[i]});
            shuffle(p.begin(), p.end(), rng);
            for(int i = 0; i < N; i++) {
                fout << p[i].first;
                if(i < N) fout << ' ';
            }
            fout << endl;
            for(int i = 0; i < N; i++) {
                fout << p[i].second;
                if(i < N) fout << ' ';
            }
        } else if(filename == "16.in") {
            int N = 300000;
            fout << 300000 << endl;
            for(int i = 1; i <= 150000; i++) A[i] = i;
            for(int i = 150001; i <= 300000; i++) A[i] = i+2;
            B[1] = 150001;
            B[300000] = 150002;
            for(int i = 2; i <= 150000; i++) B[i] = i;
            for(int i = 150001; i < 300000; i++) B[i] = i+2;
            for(int i = 1; i <= N; i++) p.push_back({A[i], B[i]});
            shuffle(p.begin(), p.end(), rng);
            for(int i = 0; i < N; i++) {
                fout << p[i].first;
                if(i < N) fout << ' ';
            }
            fout << endl;
            for(int i = 0; i < N; i++) {
                fout << p[i].second;
                if(i < N) fout << ' ';
            }
        } else {
            int N = uniform_int_distribution<int>(minN, maxN)(rng);
            fout << N << endl;
            int diff = 1000000000/N;
            for(int i = 1; i <= N; i++) {
                A[i] = uniform_int_distribution<int>((i-1)*diff+1, i*diff)(rng);
                B[i] = uniform_int_distribution<int>((i-1)*diff+1, i*diff)(rng);
            }
            if(tip == 1) {
                for(int i = 1; i <= N; i+=6) {
                    shuffle(A+i, A+min(i+6, N+1), rng);
                }
            } else if (tip == 2) {
                for(int i = 1; i <= N;) {
                    int jmp = uniform_int_distribution<int>(1, N-i+1)(rng);
                    reverse(A+i, A+i+jmp);
                    i+=jmp;
                }
            } else {
                for(int i = 1; i <= N;) {
                    int jmp = uniform_int_distribution<int>(1, N-i+1)(rng);
                    shuffle(A+i, A+i+jmp, rng);
                    i+=jmp;
                }
            }
            for(int i = 1; i <= N; i++) p.push_back({A[i], B[i]});
            shuffle(p.begin(), p.end(), rng);
            for(int i = 0; i < N; i++) {
                fout << p[i].first;
                if(i < N) fout << ' ';
            }
            fout << endl;
            for(int i = 0; i < N; i++) {
                fout << p[i].second;
                if(i < N) fout << ' ';
            }
        }
        fout.close();
    }
    return 0;
}
/*
423423
01.in 0 0 0
02.in 0 0 0

03.in 250000 300000 1
04.in 250000 300000 1
05.in 300000 300000 1

06.in 250000 300000 2
07.in 250000 300000 2
08.in 300000 300000 2

09.in 4500 5000 3
10.in 4500 5000 3
11.in 0 0 0

12.in 250000 300000 3
13.in 250000 300000 3
14.in 250000 300000 3
15.in 300000 300000 3
16.in 0 0 0
*/
