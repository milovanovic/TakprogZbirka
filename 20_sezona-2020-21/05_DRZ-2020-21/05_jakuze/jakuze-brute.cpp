#include <bits/stdc++.h>
using namespace std;
vector<int> a[300007];
int cnt,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m,tx[300007],ty[300007],vi[300007];
inline bool valid(int x,int y) {return x>=0 && x<n && y>=0 && y<m;}
inline bool simulate()
{
    for(int i=1;i<=n*m;i++) vi[i]=false;
    int xp,yp;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]==1) {xp=i; yp=j;}
    vi[1]=true;  tx[1]=xp; ty[1]=yp;
    for(int i=1;i<=n*m;i++)
    {
        if(!vi[i]) return false;
        int x=tx[i],y=ty[i];
        for(int j=0;j<4;j++)
        {
            int nx=x+dx[j],ny=y+dy[j];
            if(valid(nx,ny) && ! vi[a[nx][ny]])
            {
                int val=a[nx][ny];
                tx[val]=nx;
                ty[val]=ny;
                vi[val]=true;
            }
        }
    }
    return true;
}
int main()
{
    int q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        int t;
        scanf("%d",&t);
        a[i].push_back(t);
    }
    if(simulate()) printf("DA\n");
    else printf("NE\n");
    while(q--)
    {
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        xa--; xb--; ya--; yb--;
        swap(a[xa][ya],a[xb][yb]);
        if(simulate()) printf("DA\n");
        else printf("NE\n");
    }
}
