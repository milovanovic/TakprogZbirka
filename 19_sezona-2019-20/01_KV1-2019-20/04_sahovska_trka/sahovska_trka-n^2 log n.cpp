#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;

const int N=201,oo=INT_MAX/2;
int n,m;
bool mat[N][N];
vector<int> dx={-1,1,0,0,1,1,-1,-1,2},dy={0,0,1,-1,1,-1,1,-1,1};
vector<vector<bool> > aa;
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m&&mat[x][y];}
struct segTree{
    int n;
    vector<int> nxt,prv,lazy;
    vector<pair<int,int> > minn;
    void build(int l,int r,int i)
    {
        if(l==r){
            minn[i]={oo,l};
            return;
        }
        int m=(l+r)>>1;
        build(l,m,2*i);
        build(m+1,r,2*i+1);
        minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void init(vector<bool> a)
    {
        n=a.size();
        nxt.resize(n);
        prv.resize(n);
        lazy.resize(4*n,oo);
        minn.resize(4*n);
        for(int i=1;i<n;i++)
            prv[i]=a[i-1]?prv[i-1]:i;
        nxt[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
            nxt[i]=a[i+1]?nxt[i+1]:i;
        build(0,n-1,1);
    }
    void prop(int i)
    {
        minn[2*i]={min(minn[2*i].f,lazy[i]),minn[2*i].s};
        minn[2*i+1]={min(minn[2*i+1].f,lazy[i]),minn[2*i+1].s};
        lazy[2*i]=min(lazy[2*i],lazy[i]);
        lazy[2*i+1]=min(lazy[2*i+1],lazy[i]);
        lazy[i]=oo;
    }
    void update(int i)
    {
        if(minn[2*i].f==-1)
            minn[i]=minn[2*i+1];
        else if(minn[2*i+1].f==-1)
            minn[i]=minn[2*i];
        else
            minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void mn(int qs,int qe,int mi,int l,int r,int i)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]=min(lazy[i],mi);
            minn[i]={min(minn[i].f,mi),minn[i].s};
            return;
        }
        prop(i);
        int m=(l+r)>>1;
        mn(qs,qe,mi,l,m,2*i);
        mn(qs,qe,mi,m+1,r,2*i+1);
        update(i);
    }
    void updateSingle(int i,int mi)
    {
        mn(i,i,mi,0,n-1,1);
    }
    void updateRange(int i,int mi)
    {
        mn(prv[i],nxt[i],mi,0,n-1,1);
    }
};
struct seg2d{
    int n;
    vector<segTree> leaves;
    vector<pair<pair<int,int>,int> > minn;
    void build(int l,int r,int i)
    {
        if(l==r)
        {
            leaves[l].init(aa[l]);
            minn[i]={leaves[l].minn[1],l};
            return;
        }
        int m=(l+r)>>1;
        build(l,m,2*i);
        build(m+1,r,2*i+1);
        minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void init()
    {
        n=aa.size();
        leaves.resize(n);
        minn.resize(4*n);
        build(0,n-1,1);
    }
    void update(int i)
    {
        if(minn[2*i].f.f==-1)
            minn[i]=minn[2*i+1];
        else if(minn[2*i+1].f.f==-1)
            minn[i]=minn[2*i];
        else
            minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void AupdateSingle(int pos,int j,int mi,int l,int r,int i)
    {
        if(l>pos||r<pos)
            return;
        if(l==r)
        {
            leaves[l].updateSingle(j,mi);
            minn[i]={leaves[l].minn[1],l};
            return;
        }
        int m=(l+r)>>1;
        AupdateSingle(pos,j,mi,l,m,2*i);
        AupdateSingle(pos,j,mi,m+1,r,2*i+1);
        update(i);
    }
    void AupdateRange(int pos,int j,int mi,int l,int r,int i)
    {
        if(l>pos||r<pos)
            return;
        if(l==r)
        {
            leaves[l].updateRange(j,mi);
            minn[i]={leaves[l].minn[1],l};
            return;
        }
        int m=(l+r)>>1;
        AupdateRange(pos,j,mi,l,m,2*i);
        AupdateRange(pos,j,mi,m+1,r,2*i+1);
        update(i);
    }
    void updateSingle(int pos,int j,int mi)
    {
        AupdateSingle(pos,j,mi,0,n-1,1);
    }
    void updateRange(int pos,int j,int mi)
    {
        AupdateRange(pos,j,mi,0,n-1,1);
    }
}row[5],col[2],d1[2],d2[2];
pair<int,tuple<int,int,int> > myMin(pair<int,tuple<int,int,int> > a,pair<int,tuple<int,int,int> > b)
{
    if(a.f==-1)
        return b;
    if(b.f==-1)
        return a;
    return min(a,b);
}
vector<pair<int,int> > startd1,startd2;
pair<int,tuple<int,int,int> > getMin()
{
    pair<int,tuple<int,int,int> > ret={-1,make_tuple(0,0,0)},con;
    for(int k=0;k<5;k++){
        auto sol=row[k].minn[1];
        con={sol.f.f,make_tuple(sol.s,sol.f.s,k)};
        ret=myMin(ret,con);
    }
    for(int k=0;k<2;k++){
        auto sol=col[k].minn[1];
        con={sol.f.f,make_tuple(sol.f.s,sol.s,k==0?2:4)};
        ret=myMin(ret,con);
        sol=d1[k].minn[1];
        con={sol.f.f,make_tuple(startd1[sol.s].f+sol.f.s,startd1[sol.s].s+sol.f.s,k==0?1:4)};
        ret=myMin(ret,con);
        sol=d2[k].minn[1];
        con={sol.f.f,make_tuple(startd2[sol.s].f+sol.f.s,startd2[sol.s].s-sol.f.s,k==0?1:4)};
        ret=myMin(ret,con);
    }
    return ret;
}
int main()
{
	//freopen("0.78 541.txt","r",stdin);
	//freopen("my.txt","w",stdout);
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<m;j++)
            mat[i][j]=s[j]=='.';
    }
    vector<vector<int> > sol(n,vector<int>(m,oo));
    for(int i=n-1;i>0;i--)
        startd1.pb({i,0});
    for(int i=0;i<m;i++)
        startd1.pb({0,i}),startd2.pb({0,i});
    for(int i=1;i<n;i++)
        startd2.pb({i,m-1});
    for(int i=0;i<n;i++){
        aa.pb({});
        for(int j=0;j<m;j++)
            aa.back().pb(mat[i][j]);
    }
    for(int k=0;k<5;k++)
        row[k].init();
    aa.clear();
    for(int i=0;i<m;i++){
        aa.pb({});
        for(int j=0;j<n;j++)
            aa.back().pb(mat[j][i]);
    }
    for(int k=0;k<2;k++)
        col[k].init();
    aa.clear();
    for(int i=0;i<n+m-1;i++){
        int x=startd1[i].f,y=startd1[i].s;
        aa.pb({});
        for(;x>=0&&x<n&&y>=0&&y<m;x++,y++)
            aa.back().pb(mat[x][y]);
    }
    for(int k=0;k<2;k++)
        d1[k].init();
    aa.clear();
    for(int i=0;i<n+m-1;i++){
        int x=startd2[i].f,y=startd2[i].s;
        aa.pb({});
        for(;x>=0&&x<n&&y>=0&&y<m;x++,y--)
            aa.back().pb(mat[x][y]);
    }
    for(int k=0;k<2;k++)
        d2[k].init();
    row[0].updateSingle(0,0,0);
    auto mn=getMin();
    while(mn.f!=-1&&mn.f!=oo){
        int x,y,k;
        tie(x,y,k)=mn.s;
        int d=mn.f;
        //printf("%i %i %i: %i\n",x,y,k,d);
        sol[x][y]=min(sol[x][y],d);
        for(int o=0;o<5;o++)
            if(o!=k)
                row[o].updateSingle(x,y,d+o+1);
        if(k==0)
        {
            row[0].updateSingle(x,y,-1);
            for(int o=0;o<8;o++)
            {
                int xx=x+dx[o],yy=y+dy[o];
                if(inside(xx,yy))
                    row[0].updateSingle(xx,yy,d+1);
            }
        }
        if(k==1)
        {
            row[1].updateSingle(x,y,-1);
            d1[0].updateSingle(y-x+n-1,x-startd1[y-x+n-1].f,-1);
            d2[0].updateSingle(x+y,x-startd2[x+y].f,-1);
            d1[0].updateRange(y-x+n-1,x-startd1[y-x+n-1].f,d+1);
            d2[0].updateRange(x+y,x-startd2[x+y].f,d+1);
        }
        if(k==2)
        {
            row[2].updateSingle(x,y,-1);
            col[0].updateSingle(y,x,-1);
            row[2].updateRange(x,y,d+1);
            col[0].updateRange(y,x,d+1);
        }
        if(k==3)
        {
            row[3].updateSingle(x,y,-1);
            for(int o=0;o<2;o++,swap(dx[8],dy[8]))
                for(int i=-1;i<2;i+=2)
                    for(int j=-1;j<2;j+=2)
                    {
                        int xx=x+dx[8]*i,yy=y+dy[8]*j;
                        if(inside(xx,yy))
                            row[3].updateSingle(xx,yy,d+1);
                    }
        }
        if(k==4)
        {
            row[4].updateSingle(x,y,-1);
            col[1].updateSingle(y,x,-1);
            d1[1].updateSingle(y-x+n-1,x-startd1[y-x+n-1].f,-1);
            d2[1].updateSingle(x+y,x-startd2[x+y].f,-1);
            d1[1].updateRange(y-x+n-1,x-startd1[y-x+n-1].f,d+1);
            d2[1].updateRange(x+y,x-startd2[x+y].f,d+1);
            row[4].updateRange(x,y,d+1);
            col[1].updateRange(y,x,d+1);
        }
        mn=getMin();
    }
    if(sol[n-1][m-1]==oo)
        sol[n-1][m-1]=-1;
    printf("%i\n",sol[n-1][m-1]);
    return 0;
}
