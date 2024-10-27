#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ret = 0x7f7f7f7f7f7f7f7f;
    do {
        int curr = x;
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += abs(curr - a[i]);
            curr = a[i];
        }
        ret = min(ret, tmp);
    } while (next_permutation(a.begin(), a.end()));
    cout << ret << endl;
    return 0;
}
