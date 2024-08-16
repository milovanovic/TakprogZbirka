#include <bits/stdc++.h>
#define maxn 3000000
using namespace std;
int k,n;
int a[maxn];
int x[maxn];
bool ex[maxn];
bool nw[maxn];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++) {
        cin>>a[i];
        ex[a[i]]=true;
    }
    for(int i=1;i<=n;i++)  {
        cin>>x[i];
        x[n+i]=x[i];
    }
    int ans=-1;
    for(int mask=1;mask<(1<<n);mask++) {
        int cur=n;
        for(int i=0;i<n;i++) {
            nw[i+1]=false;
            if(mask&(1<<i)) {
                nw[i+1]=true;
                if(ex[i+1]) {
                    cur=-1;
                }
            }
        }
        if(cur!=-1) {
            cur=__builtin_popcount(mask);
            long long tot=0;
            long long mn=0;
            for(int i=1;i<=n;i++) {
                int nx=n;
                int nn=n;
                tot+=x[i];
                for(int j=1;j<=n;j++) {
                    int dist=min(abs(i-j),n-abs(i-j));
                    if(ex[j] && dist<nx) {
                        nx=dist;
                    }
                    if(nw[j] && dist<nn) {
                        nn=dist;
                    }
                }
                if(nn<nx) mn+=x[i];
                else {
                    if(nx==nn) mn+=x[i]/2;
                }
            }
            if(mn*2>tot) {
                if(ans==-1 || ans>cur) ans=cur;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}