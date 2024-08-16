#include <bits/stdc++.h>
#include <chrono>
using namespace std;

using ll = long long;
using ld = long double;

#define pb push_back
#define si(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fi first
#define se second

int a[200005];

bool check(int l, int r, int j){
    int lst = 0;
    for(int i=l; i<=r; i++){
        if(i == j) continue;
        if(a[i] < lst) return 0;
        lst = a[i];
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) assert(1 <= a[i] && a[i] <= n);
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int l, r;
        cin >> l >> r;
        assert(1 <= l && l <= r && r <= n);
        bool good = 0;
        bool sorted = 1;
        for(int j=l; j<=r; j++){
            if(a[j-1] <= a[j] && a[j] <= a[j+1]) continue;
            sorted = 0;
            if(check(l, r, j)){
                good = 1;
                break;
            }
        }
        if(good || sorted) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}