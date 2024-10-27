#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
vector<int> sol;
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (auto x : cnt) {
        if (x.second >= k) {
            sol.push_back(x.first);
        }
    }
    cout << sol.size() << endl;
    for (auto x : sol) {
        cout << x << " ";
    }
    return 0;
}
