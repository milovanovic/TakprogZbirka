#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
int n,m;
map<int,int> mp;
vector<int> a[maxn];
int cnt=1;
int main() {
    scanf("%d %d",&n,&m);
    assert(1<=n && n<=200000);
    assert(1<=m && m<=200000);
    for(int i=1;i<=n;i++) {
        int d,u;
        scanf("%d %d",&d,&u);
        assert(0<=d && d==u && u<=1000000000);
        if(mp[d]==0) mp[d]=cnt++;
        a[mp[d]].push_back(i);
    }
    for(int i=1;i<=cnt;i++) sort(a[i].begin(),a[i].end());
    for(int i=1;i<=m;i++) {
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        assert(1<=l && l<=r && r<=n);
        assert(0<=x && x<=1000000000);
        if(mp[x]==0) {
            printf("0\n");
        }
        else {
            int p,q;
            int j=mp[x];
            p=0;
            q=a[j].size();
            while(p<q) {
                int s=(p+q)/2;
                if(a[j][s]<l) p=s+1;
                else q=s;
            }
            int u=p;
            p=0;
            q=a[j].size();
            while(p<q) {
                int s=(p+q)/2;
                if(a[j][s]<=r) p=s+1;
                else q=s;
            }
            int v=p;
            printf("%d\n",v-u);
        }
    }
    return 0;
}
