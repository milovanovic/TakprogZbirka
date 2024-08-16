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
long long area(point p,point q,point r)
{
    return abs((q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x));
}
void assertinterval(int l,int r,int v)
{
    assert(l<=v && v<=r);
}
int main()
{
    int n;
	scanf("%d",&n);
	assertinterval(3,3,n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++) assertinterval(-1000000000,1000000000,a[i].x);
	for(int i=1;i<=n;i++) assertinterval(-1000000000,1000000000,a[i].y);
	for(int i=1;i<=n;i++)
    {
        assert(!mp[make_pair(a[i].x,a[i].y)]);
        mp[make_pair(a[i].x,a[i].y)]=true;
    }
	origin.x=0; origin.y=0;
	long long res=0;
	if(area(a[1],a[2],a[3])==area(origin,a[2],a[3])+area(a[1],origin,a[3])+area(a[1],a[2],origin)) res++;
	if(area(origin,a[2],a[3])==0) res++;
	if(area(a[1],origin,a[3])==0) res++;
	if(area(a[1],a[2],origin)==0) res++;
	printf("%lld",res);
}
