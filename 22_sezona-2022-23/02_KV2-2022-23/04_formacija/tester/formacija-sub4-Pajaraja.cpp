#include <bits/stdc++.h>
#define MAXN 100007
#define MOD 1000000007
using namespace std;
map<pair<int,int>,bool> mp;
struct point {
    long long x,y;
};
point a[MAXN],hull[MAXN],origin;
long long orient(point p,point q,point r)
{
    return (q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
}
long long area(point p,point q,point r)
{
    return abs(orient(p,q,r));
}
bool operator <(point p,point q)
{
    if(p.x==q.x) return p.y<q.y;
    return p.x<q.x;
}
void assertinterval(int l,int r,int v)
{
    assert(l<=v && v<=r);
}
int main()
{
    int n;
	scanf("%d",&n);
	assertinterval(1,18,n);
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
	sort(a+1,a+n+1);
	for(int mask=1;mask<(1<<n);mask++)
    {
        vector<point> tr,lh,uh;
        for(int i=1;i<=n;i++) if((mask|(1<<(i-1)))==mask) tr.push_back(a[i]);
        if(tr.size()==1) continue;
        int k=0;
        for (int i = 0; i < tr.size(); ++i)
        {
            while (k >= 2 && orient(hull[k - 2],hull[k - 1], tr[i]) <= 0) k--;
            hull[k++] = tr[i];
        }
        for (int i = tr.size() - 1, t = k + 1; i > 0; --i)
        {
            while (k >= t && orient(hull[k - 2],hull[k - 1], tr[i - 1]) <= 0) k--;
            hull[k++] = tr[i - 1];
        }
        k--;
        long long povrsina1=0,povrsina2=0;
        for(int i=0;i<k;i++) povrsina1+=area(hull[0],hull[i],hull[(i+1)%k]);
        for(int i=0;i<k;i++) povrsina2+=area(origin,hull[i],hull[(i+1)%k]);
        if(povrsina1==povrsina2) res++;
    }
    printf("%lld",res);
}
