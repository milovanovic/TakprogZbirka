#include <bits/stdc++.h>

using namespace std;
#define lld long long
set<long long> in;
int main() {
    string filename;
    lld minN = 2, minM = 2, maxN, maxM, minAB = 1, maxAB, minT = 1, maxT = 5;
    cin >> filename >> maxN >> maxM >> maxAB;
    freopen(filename.c_str(), "r", stdin);
    lld T; cin >> T;
    if(T < minT || T > maxT) {
        cerr << "T NIJE DOBRO!" << endl;
        return 0;
    }
    while(T--) {
        cerr << "T: " << T << endl;
        in.clear();
        lld N, M; cin >> N >> M;
        if(N < minN || N > maxN) {
            cerr << "N NIJE DOBRO!" << endl;
            return 0;
        }
        if(M < minM || M > maxM) {
            cerr << "M NIJE DOBRO!" << endl;
            return 0;
        }
        for(int i = 1; i <= N; i++) {
            long long x; cin >> x;
            if(in.find(x) != in.end()) {
                cerr << "A[i] duplikat!" << endl;
                return 0;
            }
            if(x < minAB || x > maxAB) {
                cerr << "A[i] NIJE DOBRO!" << endl;
                return 0;
            }
            in.insert(x);
        }
        for(int i = 1; i <= M; i++) {
            long long x; cin >> x;
            if(in.find(x) != in.end()) {
                cerr << "B[i] duplikat!" << endl;
                return 0;
            }
            if(x < minAB || x > maxAB) {
                cerr << "B[i] NIJE DOBRO!" << endl;
                return 0;
            }
            in.insert(x);
        }
    }
}
