#include<bits/stdc++.h>
#define MAXN 5007
using namespace std;
priority_queue<pair<int,pair<int,int> > > pq;
queue<pair<int,int> > q;
vector<pair<int,int> > v,c;
bool arr[MAXN][MAXN],fl[MAXN][MAXN];
string s[MAXN];
int broj[MAXN][MAXN],dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
mt19937 rng(time(0));
void dodajflood(int x,int y)
{
    broj[x][y]++;
    if(broj[x][y]==2)
    {
        q.push({x,y});
        fl[x][y]=true;
    }
}
void poplavi(int x,int y)
{
    fl[x][y]=true;
    for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) dodajflood(x+dx[i],y+dy[i]);
}
int main()
{
    int t,rand;
    cin>>t>>rand;
    string st;
    if(t<10) st='0'+to_string(t);
    else st=to_string(t);
    ifstream in("testcases\\"+st+".in");
    ofstream out("sols-stupid\\"+st+".out");
    int n,m,br=0;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>s[i];
        for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(arr[i][j]) c.push_back({i,j});
    if(rand) shuffle(c.begin(),c.end(),rng);
    for(int i=0;i<c.size();i++) if(!fl[c[i].first][c[i].second])
    {
        br++;
        v.push_back(c[i]);
        q.push(c[i]);
        while(!q.empty())
        {
            poplavi(q.front().first,q.front().second);
            q.pop();
        }
    }
    cout<<br<<endl;
    out<<v.size()<<endl;
    for(int i=0;i<v.size();i++) out<<v[i].first<<" "<<v[i].second<<endl;
    //for(int i=1;i<=n;i++) cout<<s[i]<<endl;
}
