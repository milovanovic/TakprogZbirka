#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
set<pair<int,int> > l;
set<pair<int,int> > r;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    assert(1<=n && n<=200000);
    assert(1<=m && m<=200000);
    for(int i=1;i<=n;i++) {
        int d,u;
        scanf("%d %d",&d,&u);
        assert(0<=d && d<=u && u<=1000000000);
        set<pair<int,int> >::iterator it,jt;
        it=l.upper_bound({d,n+1});
        jt=r.upper_bound({d,n+1});
        if(it!=l.begin()) {
            it--;
            assert(jt!=r.begin());
            jt--;
            assert((*it).first<=(*jt).first && (*jt).first<d);
        }
        it=l.lower_bound({u,-1});
        jt=r.lower_bound({u,-1});
        if(it!=l.end()) {
            assert(jt!=r.end());
            assert((*it).first<=(*jt).first && u<(*it).first);
        }
        l.insert({d,i});
        r.insert({u,i});
    }
    for(int i=1;i<=m;i++) {
        int li,ri,x;
        scanf("%d %d %d",&li,&ri,&x);
        assert(1<=li && li<=ri && ri<=n);
        assert(0<=x && x<=1000000000);
        set<pair<int,int> >::iterator it,jt;
        it=l.upper_bound({x,n+1});
        if(it!=l.begin()) {
            it--;
            jt=r.lower_bound({x,-1});
            if(jt!=r.begin()) {
                jt--;
                if((*it).first>(*jt).first) {
                    printf("%d\n",(li<=(*it).second && (*it).second<=ri));
                }
                else printf("0\n");
            }
            else printf("%d\n",(li<=(*it).second && (*it).second<=ri));
        }
        else printf("0\n");
    }
    return 0;
}
