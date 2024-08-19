#include<bits/stdc++.h>
#define MAXN 5007
using namespace std;
priority_queue<pair<int,pair<int,int> > > pq;
queue<pair<int,int> > q;
vector<pair<int,int> > v;
bool arr[MAXN][MAXN],vi[MAXN][MAXN];
string s[MAXN];
int cnt;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
mt19937 rng(time(0));
void dfs(int x,int y)
{
    vi[x][y]=true;
    for(int i=0;i<4;i++)
    {
        if(!arr[x+dx[i]][y+dy[i]])  cnt++;
        else if(!vi[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
    int t;
    cin>>t;
    string st;
    if(t<10) st='0'+to_string(t);
    else st=to_string(t);
    ifstream in("testcases\\"+st+".in");
    //ofstream out("sols\\"+st+".out");
    int n,m;
    int lw=0;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>s[i];
        for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vi[i][j] && arr[i][j])
    {
        cnt=0;
        dfs(i,j);
        lw+=(cnt+3)/4;
    }
    cout<<lw;
}
