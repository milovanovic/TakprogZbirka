#include <iostream>
#include <vector> 
#include <cassert>

using namespace std;

const int MAXN = 201;
const int MAXK = 501;
const int INF = 1000000000;

vector<int> adj[MAXN];
bool in_cycle[MAXN];
int K, deg_in[MAXN], dp[MAXN][MAXK], s[MAXN], k[MAXN];

void solveDP(int node) {
    for (int kk = 0; kk < min(K+1, k[node]); kk++) {
        dp[node][kk] = -INF;
    }
    for (int kk = k[node]; kk <= K; kk++) {
        dp[node][kk] = s[node];
    }
    for (auto x : adj[node]) {
        solveDP(x);
        for (int kk = K; kk >= 0; kk--) {
            for (int l = 0; l <= kk; l++) {
                dp[node][kk] = max(dp[node][kk], dp[node][kk-l] + dp[x][l]);
            }
        }
    }
}

int MaxSpartanstvo(int N, int _K, int p[], int _s[], int _k[]) {
    K = _K;
    p[0] = 0;
    s[0] = 0;
    k[0] = 0;
    for (int i = 1; i <= N; i++) {
        adj[p[i]].push_back(i);
        deg_in[p[i]]++;
        in_cycle[i] = true;
        s[i] = _s[i];
        k[i] = _k[i];
    }
    vector<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg_in[i] == 0) {
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int leaf = q.back(); q.pop_back();
        in_cycle[leaf] = false;
        deg_in[p[leaf]]--;
        if (deg_in[p[leaf]] == 0) {
            q.push_back(p[leaf]);
        }
    }
    for (int i = 1; i <= N; i++) {
        assert(in_cycle[i] == false);
        if (in_cycle[i]) {
            int cur = i, sumS = 0, sumK = 0;
            vector<int> neighbours;
            do {
                sumS += s[cur];
                sumK += k[cur];
                for (auto x : adj[cur]) {
                    if (!in_cycle[x]) {
                        neighbours.push_back(x);
                        p[x] = i;
                    }
                }
                cur = p[cur];
            } while (cur != i);
            do {
                in_cycle[cur] = false;
                cur = p[cur];
            } while (cur != i);
            p[i] = 0;
            s[i] = sumS;
            k[i] = sumK;
            adj[i] = neighbours;
            adj[0].push_back(i);
        }
    }

    solveDP(0);
    return dp[0][K];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;

    int *p = new int[N+1];
    int *s = new int[N+1];
    int *k = new int[N+1];

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> k[i];
    }
    
    cout << MaxSpartanstvo(N, K, p, s, k) << endl;

    delete[] p;
    delete[] s;
    delete[] k;
    return 0;
}