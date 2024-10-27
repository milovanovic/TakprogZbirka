#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 16;

int n, k, a[MAXN];
vector<int> resenje;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (find(resenje.begin(), resenje.end(), a[i]) != resenje.end()) {
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == a[i]) {
                cnt++;
            }
        }
        if (cnt >= k) {
            resenje.push_back(a[i]);
        }
    }
    sort(resenje.begin(), resenje.end());
    cout << resenje.size() << endl;
    for (auto x : resenje) {
        cout << x << " ";
    }
    return 0;
}
