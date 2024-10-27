#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

const int N=500,oo=INT_MAX/N;
int n,m;
vector<string> mat(N);
vector<int> dx={0,0,1,-1,1,1,-1,-1},dy={1,-1,0,0,1,-1,1,-1};
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m&&mat[x][y]=='.';}
int bfs()
{
    vector<vector<int> > di(n,vector<int>(m,oo));
    di[0][0]=0;
    queue<pair<int,int> > q;
    q.push({0,0});
    while(q.size())
    {
        int x=q.front().f,y=q.front().s;
        q.pop();
        for(int k=0;k<8;k++)
        {
            int xx=x+dx[k],yy=y+dy[k];
            if(!inside(xx,yy))
                continue;
            if(di[xx][yy]>di[x][y]+1)
                di[xx][yy]=di[x][y]+1,q.push({xx,yy});
        }
    }
    if(di[n-1][m-1]==oo)
        di[n-1][m-1]=-1;
    return di[n-1][m-1];
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    cout << bfs();
    return 0;
}
