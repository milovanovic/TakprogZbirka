#include <bits/stdc++.h>
#define lld long long
using namespace std;
#define MAXN 75010
lld N, M, A[MAXN], B[MAXN];
lld minN, maxN, minM, maxM, maxAB, seed, rez;
set<lld> in;
void generateA(lld X, mt19937_64 rng) {
    cerr << "A" << endl;
    A[1] = uniform_int_distribution<long long>(1, X)(rng);
    A[2] = A[1]+X;
    in.insert(A[1]); in.insert(A[2]);
    int curN = 2;
    while(curN < N) {
        int cnt = 0;
        bool endr = 0;
        lld cur;
        while(1) {
            cnt++;
            if(cnt > 100) {
                endr = 1;
                break;
            }
            cur = A[1]+X*uniform_int_distribution<long long>(0, maxAB/X-1)(rng);
            if(in.find(cur) == in.end()) break;
        }
        if(endr) break;
        curN++;
        A[curN] = cur;
        in.insert(cur);
    }
    lld cur = A[1];
    while(curN < N) {
        if(in.find(cur) != in.end()) cur += X;
        else {
            curN++;
            A[curN] = cur;
            cur += X;
            in.insert(A[curN]);
        }
    }
}

void generateB0(lld A0, lld X, mt19937_64 rng) {
    cerr << "B0" << endl;
    int curM = 0;
    for(lld t = A0; t <= maxAB; t+=X) {
        if(in.find(t) == in.end()) {
            curM = 1;
            B[curM] = t;
            in.insert(t);
            break;
        }
    }
    while(curM < M) {
        int cnt = 0;
        bool endr = 0;
        lld cur;
        while(1) {
            cnt++;
            if(cnt > 100) {
                endr = 1;
                break;
            }
            cur = uniform_int_distribution<long long>(1, maxAB)(rng);
            if(in.find(cur) == in.end()) break;
        }
        if(endr) break;
        curM++;
        B[curM] = cur;
        in.insert(cur);
    }
    lld cur = 1;
    while(curM < M) {
        if(in.find(cur) != in.end()) cur++;
        else {
            curM++;
            B[curM] = cur;
            cur++;
            in.insert(B[curM]);
        }
    }
}
void generateB1(lld A0, lld X, mt19937_64 rng) {
    cerr << "B1" << endl;
    int curM = 0;
    while(curM < M) {
        int cnt = 0;
        bool endr = 0;
        lld cur;
        while(1) {
            cnt++;
            if(cnt > 100) {
                endr = 1;
                break;
            }
            cur = uniform_int_distribution<long long>(1, maxAB)(rng);
            if(abs(cur-A0)%X != 0 && in.find(cur) == in.end()) break;
        }
        if(endr) break;
        curM++;
        B[curM] = cur;
        in.insert(cur);
    }
    lld cur = 1;
    while(curM < M) {
        if(X == 1) break;
        if(abs(cur-A0)%X == 0 || in.find(cur) != in.end()) cur++;
        else {
            curM++;
            B[curM] = cur;
            cur++;
            in.insert(B[curM]);
        }
    }
    cur = 1;
    while(curM < M) {
        if(in.find(cur) != in.end()) cur++;
        else {
            curM++;
            B[curM] = cur;
            cur++;
            in.insert(B[curM]);
        }
    }
}

int main() {
    string filename;
    cin >> filename >> minN >> maxN >> minM >> maxM >> maxAB >> seed >> rez;
    mt19937_64 rng(seed);
    freopen(filename.c_str(), "w", stdout);
    if(filename == "01.in") {
        cout << 3 << endl;
        cout << 4 << ' ' << 3 << endl;
        cout << 1 << ' ' << 7 << ' ' << 4 << ' ' << 13 << endl;
        cout << 3 << ' ' << 11 << ' ' << 9 << endl;
        cout << 3 << ' ' << 2 << endl;
        cout << 9 << ' ' << 5 << ' ' << 3 << endl;
        cout << 7 << ' ' << 11 << endl;
        cout << 2 << ' ' << 3 << endl;
        cout << 3 << ' ' << 15 << endl;
        cout << 1 << ' ' << 7 << ' ' << 2 << endl;
        cout << 2 << ' ' << 2 << endl;
        cout << 5643634654354 << ' ' << 12346544323565 << endl;
        cout << 22341124534 << ' ' << 7655867344;
        return 0;
    }
    int T = 5;
    //if(filename == "12.in" || filename == "13.in" || filename == "14.in" || filename == "15.in" || filename == "16.in"|| filename == "17.in"|| filename == "18.in"|| filename == "19.in"|| filename == "20.in"|| filename == "21.in") T = 4;
    cout << T << endl;
    while(T--) {
        in.clear();
        int tip = (rez&1); rez /= 2;
        N = uniform_int_distribution<long long>(minN, maxN)(rng);
        M = uniform_int_distribution<long long>(minM, maxM)(rng);
        lld X = uniform_int_distribution<long long>(1, maxAB/N)(rng);;
        generateA(X, rng);
        if(tip == 0) {
            generateB0(A[1], X, rng);
        } else {
            generateB1(A[1], X, rng);
        }
        shuffle(A+1, A+1+N, rng);
        shuffle(B+1,B+1+M, rng);
        cout << N << ' ' << M << endl;
        for(int i = 1; i <= N; i++) {
            cout << A[i];
            if(i != N) cout << ' ';
        }
        cout << endl;
        for(int i = 1; i <= M; i++) {
            cout << B[i];
            if(i != M) cout << ' ';
        }
        if(T != 0) cout << endl;
    }
    return 0;
}
