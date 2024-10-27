#include <bits/stdc++.h>

using namespace std;

const int N=500,M=N*N*5,L=5,oo=INT_MAX/N;
int n,m,tr=N*N*L;
vector<string> mat(N);
vector<int> dx={0,0,1,-1,1,1,-1,-1,2,2,-2,-2,1,1,-1,-1},dy={1,-1,0,0,1,-1,1,-1,1,-1,1,-1,2,-2,2,-2},l={0,4,0,8,0},r={7,7,3,15,7},d={1,N,N,1,N};
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m&&mat[x][y]=='.';}
int getNum(int x,int y,int z){return z+y*L+x*N*L;}
tuple<int,int,int> getField(int i){return make_tuple(i/N/L,(i%(N*L))/L,i%L);}
vector<int> dist(M,oo);
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    set<pair<int,int> > q;
    q.insert({0,0});
    dist[0]=0;
    while(q.size())
    {
        int di,tr,x,y,z;
        tie(di,tr)=*q.begin();
        q.erase(q.begin());
        if(di>dist[tr])
            continue;
        tie(x,y,z)=getField(tr);
        if(x==n-1&&y==m-1)
        {
            printf("%i\n",dist[tr]);
            return 0;
        }
        for(int i=0;i<5;i++)
        {
            int br=getNum(x,y,i);
            if(dist[br]>dist[tr]+i+1)
                dist[br]=dist[tr]+i+1,q.insert({dist[br],br});
        }
        for(int k=l[z];k<=r[z];k++)
            for(int i=1;i<=d[z];i++)
            {
                int xx=x+dx[k]*i,yy=y+dy[k]*i,br=getNum(xx,yy,z);
                if(!inside(xx,yy)||dist[br]<=dist[tr])
                    break;
                if(dist[br]>dist[tr]+1)
                    dist[br]=dist[tr]+1,q.insert({dist[br],br});
            }
    }
    printf("-1\n");
    return 0;
}
