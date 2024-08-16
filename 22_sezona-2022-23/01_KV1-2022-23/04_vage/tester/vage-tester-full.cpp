#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
vector<pair<int,pair<int,pair<int,int> > > > events;
int seg[4*maxn];
void update(int id,int l,int r,int p,int v) {
    seg[id]+=v;
    if(l==r) return;
    int m=(l+r)/2;
    if(p<=m) update(id*2+1,l,m,p,v);
    else update(id*2+2,m+1,r,p,v);
}
int query(int id,int l,int r,int x,int y) {
    if(x<=l && r<=y) return seg[id];
    if(y<l || r<x) return 0;
    int m=(l+r)/2;
    return query(id*2+1,l,m,x,y)+query(id*2+2,m+1,r,x,y);
}
int ans[maxn];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    assert(1<=n && n<=200000);
    assert(1<=m && m<=200000);
    for(int i=1;i<=n;i++) {
        int d,u;
        scanf("%d %d",&d,&u);
        assert(0<=d && d<=u && u<=1000000000);
        events.push_back({d,{-1,{0,i}}});
        events.push_back({u,{n+1,{0,i}}});
    }
    for(int i=1;i<=m;i++) {
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        assert(1<=l && l<=r && r<=n);
        assert(0<=x && x<=1000000000);
        events.push_back({x,{l,{r,i}}});
    }
    sort(events.begin(),events.end());
    for(auto ev:events) {
        int l=ev.second.first;
        int r = ev.second.second.first;
        int id = ev.second.second.second;
        if(l<0) update(0,1,n,id,1);
        else {
            if(l>n) update(0,1,n,id,-1);
            else ans[id] = query(0,1,n,l,r);
        }
    }
    for(int i=1;i<=m;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
