#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <cstdint>

using namespace std;

typedef vector<int> vi;

bool has_extra_tokens(ifstream& ifs) {
    string s;
    ifs >> s;
    return s.size() != 0;
}

const int maxn = 200010;
vector<int> e[maxn], w(maxn);

int convert(int x){
    if (x == 2) return 1;
    return 2;
}

int main(int argc, char** argv) {
    ifstream ouf(argv[1]);
    ifstream sof(argv[2]);
    ifstream inf(argv[3]);

    int t = 1;

    while (t--) {
        string a, b;
        sof >> a;
        if (a.size() == 0) {
            if (has_extra_tokens(ouf)) {
                return -1;
            } else {
                return 0;
            }
        } else {
            ouf >> b;
            if (a != b) {
                return -1;
            }
   
            int n;
            inf >> n;

            for (int i = 1; i <= n; ++i)
                inf >> w[i];

            for (int i = 1; i < n; ++i){
                int u, v;
                inf >> u >> v;

                e[u].push_back(v);
                e[v].push_back(u);
            }

            int r, b;

            string tt;
            ouf >> tt;

            if (tt.length() == 0) return -1;
            r = stoi(tt);
   
            vi red(r);

            vi color(n+1, 0);
            vi d(n+1, INT32_MAX);
         
            long long suma = 0;
            queue<int> q;
            unordered_set<int> cvor;
            for (int i = 0; i < r; ++i){
                string tmp;
                ouf >> tmp;

                if (tmp.length() == 0) return -1;
                red[i] = stoi(tmp);

                if (red[i] < 1 || red[i] > n) return -1;
                if (cvor.count(red[i])) return -1;
                cvor.insert(red[i]);

                suma += w[red[i]];
                q.push(red[i]);
                color[red[i]] = 1;
                d[red[i]] = 0;
            }


            ouf >> tt;

            if (tt.length() == 0) return -1;
            b = stoi(tt);

            vi blue(b);
            for (int i = 0; i < b; ++i){
                string tmp;
                ouf >> tmp;

                if (tmp.length() == 0) return -1;
                blue[i] = stoi(tmp);

                if (blue[i] < 1 || blue[i] > n) return -1;

                if (cvor.count(blue[i])) return -1;
                cvor.insert(blue[i]);

                suma += w[blue[i]];
                color[blue[i]] = 2;
                d[blue[i]] = 0;
                q.push(blue[i]);
            }

            if (to_string(suma) != a) return -1;

            while(!q.empty()){
                int c = q.front();
                q.pop();

                for (auto& i : e[c]){

                    if (color[i] == color[c]) return -1;

                    if (color[i] != 0) continue;

                    color[i] = convert(color[c]);
                    d[i] = d[c] + 1;

                    if (d[i] > 1) return -1;
                    q.push(i);
                }
            }

            for (int i = 1; i <= n; ++i){
                if (d[i] > 1) return -1;

                for (auto& j : e[i])
                    if (color[i] == color[j]) return -1;
            }

        }
    }

    string a;
    if (ouf >> a)
        return -1;

    return cout << "TOOO", 0;
}
