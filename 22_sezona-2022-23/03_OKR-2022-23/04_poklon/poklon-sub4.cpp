#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define pb push_back
#define si(x) int(x.size())
#define all(x) x.begin(), x.end()
#define fi first
#define se second

const int N = 200000;

int nxt[N+5][3];
int a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    nxt[n+1][1] = n + 1;
    nxt[n+1][2] = n + 1;
    for(int i=n; i>=1; i--){
        nxt[i][1] = nxt[i+1][1];
        nxt[i][2] = nxt[i+1][2];
        if(a[i] == 1) nxt[i][1] = i;
        else nxt[i][2] = i;
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(nxt[l][2] > r){
            cout << "DA\n";
            continue;
        }
        int x = nxt[l][2];
        int y = nxt[x][1];
        if(y > r){
            cout << "DA\n";
            continue;
        }
        if(nxt[y+1][1] > r){
            cout << "DA\n";
            continue;
        }
        if(y == x + 1){
            int t = nxt[y][2];
            t = nxt[t][1];
            if(t > r){
                cout << "DA\n";
                continue;
            }
        }
        cout << "NE\n";
    }
    return 0;
}