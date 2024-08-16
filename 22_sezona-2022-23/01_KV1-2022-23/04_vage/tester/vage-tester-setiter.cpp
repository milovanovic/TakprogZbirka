#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
vector<pair<int,pair<int,pair<int,int> > > > events;
int seg[4*maxn];
set<int> st;
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
    st.insert(n+1);
    for(auto ev:events) {
        int l=ev.second.first;
        int r = ev.second.second.first;
        int id = ev.second.second.second;
        if(l<0) st.insert(id);
        else {
            if(l>n) st.erase(id);
            else {
                set<int>::iterator iter = st.lower_bound(l);
                while((*iter)<=r) {
                    ans[id]++;
                    iter++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
