#include <bits/stdc++.h>
#define MAXN 100007
#define MOD 1000000007
using namespace std;
map<pair<int,int>,bool> mp;
struct point {
    long long x,y;
};
point a[MAXN],origin;
long long st[MAXN];
vector<pair<point,int>> u;
long long orient(point p,point q,point r)
{
    return (q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
}
bool operator <(point p,point q)
{
    return orient(p,q,origin)>0;
}
void assertinterval(int l,int r,int v)
{
    assert(l<=v && v<=r);
}
int main()
{
    int n;
	scanf("%d",&n);
	assertinterval(1,100000,n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++) assertinterval(-1000000000,1000000000,a[i].x);
	for(int i=1;i<=n;i++) assertinterval(-1,1,a[i].y);
	for(int i=1;i<=n;i++) assert(a[i].y!=0);
	for(int i=1;i<=n;i++)
    {
        assert(!mp[make_pair(a[i].x,a[i].y)]);
        mp[make_pair(a[i].x,a[i].y)]=true;
    }
	origin.x=0; origin.y=0;
	long long res=0;
    int total=0; st[0]=1;
    for(int i=1;i<=n;i++) st[i]=(st[i-1]*2LL)%MOD;
    for(int j=1;j<=n;j++)
    {
        if(a[j].x>0 || (a[j].x==0 && a[j].y>=0)) {total++; u.push_back({a[j],-1});}
        else
        {
            point f; f.x=-a[j].x; f.y=-a[j].y;
            u.push_back({f,+1});
        }
    }
    sort(u.begin(),u.end());
    for(int j=0;j<u.size();j++)
    {
        if(u[j].second==1) res=(res+st[total])%MOD;
        total+=u[j].second;
    }
    u.clear();
    for(int i=1;i<=n;i++) {a[i].x=-a[i].x; a[i].y=-a[i].y;}
    total=0;
    for(int j=1;j<=n;j++)
    {
        if(a[j].x>0 || (a[j].x==0 && a[j].y>=0)) {total++; u.push_back({a[j],-1});}
        else
        {
            point f; f.x=-a[j].x; f.y=-a[j].y;
            u.push_back({f,+1});
        }
    }
    sort(u.begin(),u.end());
    for(int j=0;j<u.size();j++)
    {
        if(u[j].second==1) res=(res+st[total])%MOD;
        total+=u[j].second;
    }
	printf("%lld",(st[n]+MOD-1-res)%MOD);
}
