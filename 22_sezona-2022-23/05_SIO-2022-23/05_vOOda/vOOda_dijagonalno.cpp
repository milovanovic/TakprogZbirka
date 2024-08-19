#include<bits/stdc++.h>
#define MAXN 5007
using namespace std;
priority_queue<pair<int,pair<int,int> > > pq;
queue<pair<int,int> > q;
vector<pair<int,int> > v;
bool arr[MAXN][MAXN],fl[MAXN][MAXN];
string s[MAXN];
int broj[MAXN][MAXN],rando[MAXN][MAXN];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
mt19937 rng(time(0));
int brojsuseda(int x,int y)
{
    int cnt=0;
    for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]])  cnt++;
    return cnt;
}
int skor(int x,int y)
{
    int a=brojsuseda(x,y);
    int pre=0;
    for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]] && broj[x+dx[i]][y+dy[i]])  pre++;
    if(a<2) return 1000000000;
    return -100000*broj[x][y]+1000*pre+100*(4-a)+rando[x][y]%100;
}
void u_pq(int x,int y)
{
    rando[x][y]=rng()%100;
    pq.push({skor(x,y),{x,y}});
}
void dodajflood(int x,int y)
{
    broj[x][y]++;
    if(broj[x][y]==2)
    {
        q.push({x,y});
        fl[x][y]=true;
    }
    else
    {
        u_pq(x,y);
        for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) u_pq(x+dx[i],y+dy[i]);
    }

}
void poplavi(int x,int y)
{
    fl[x][y]=true;
    for(int i=0;i<4;i++) if(arr[x+dx[i]][y+dy[i]] && !fl[x+dx[i]][y+dy[i]]) dodajflood(x+dx[i],y+dy[i]);
}
int main()
{
    int t,threshold;
    cin>>t>>threshold;
    if(threshold==0) threshold=1000000000;
    string st;
    if(t<10) st='0'+to_string(t);
    else st=to_string(t);
    ifstream in("testcases\\"+st+".in");
    ofstream out("sols-dijagonalno\\"+st+".out");
    int n,m;
    int lw=0;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>s[i];
        for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
    }
    while(true)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) arr[i][j]=(s[i][j-1]=='.');
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) fl[i][j]=false;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) broj[i][j]=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) rando[i][j]=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(arr[i][j]) u_pq(i,j);
        int br=0;
        while(!pq.empty())
        {
            pair<int,int> p=pq.top().second;
            int rez=pq.top().first;
            pq.pop();
            if(fl[p.first][p.second] || rez!=skor(p.first,p.second)) continue;
            q.push(p);
            //cout<<p.first<<" "<<p.second<<endl;
            v.push_back(p);
            br++;
            while(!q.empty())
            {
                pair<int,int> pr=q.front();
                q.pop();
                poplavi(pr.first,pr.second);
            }
        }
        cout<<br<<endl;
        if(br<threshold) break;
        v.clear();
    }
    out<<v.size()<<endl;
    for(int i=0;i<v.size();i++) out<<v[i].first<<" "<<v[i].second<<endl;
    //for(int i=1;i<=n;i++) cout<<s[i]<<endl;
}
