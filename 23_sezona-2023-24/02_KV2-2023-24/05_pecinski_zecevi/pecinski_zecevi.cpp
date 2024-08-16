#include <bits/stdc++.h>

using namespace std;
long long int typedef li;

vector<vector<int>> g(500005);
int up[500005];
int siz[500005];
int dub[500005];

void dfs(int p, int q)
{
    up[p]=q,siz[p]=1,dub[p]=dub[q]+1;
    for (auto it : g[p]) if (it!=q) dfs(it,p),siz[p]+=siz[it];
}

int chin[500005]; //kom chain-u pripada
int president[500005]; //najvisi u chain-u
int chnt[500005]; //koliko dat chain ima elemenata
vector<int> podub[500005]; //za svaki chain, njegovi cvorovi izlistani po dubinskom redu

int idx=0;
void hfs(int p, int cc, int r)
{
    chin[p]=cc,president[p]=r,chnt[cc]++,podub[cc].push_back(p);
    if (g[p].empty()) return;
    int gde=0;
    for (auto it : g[p]) if (siz[it]>siz[gde]) gde=it;
    hfs(gde,cc,r);
    for (auto it : g[p]) if (it!=gde) hfs(it,++idx,it);
}

bool ima[500005]; //korisna informacija za imati
int fwtsiz[500005];
int logsiz[500005]; //floor(log(fwtsiz))
vector<int> fwt[500005]; //za dat chain fenwick (po dubini, offest-ovan)
void add(int c, int i)
{
    for (;i<=fwtsiz[c];i+=(i&-i)) fwt[c][i]++;
}
void rmv(int c, int i)
{
    for (;i<=fwtsiz[c];i+=(i&-i)) fwt[c][i]--;
}
int pre(int c, int i)
{
    int ret=0;
    for (;i;i-=(i&-i)) ret+=fwt[c][i];
    return ret;
}
int walk(int c, int x) //prvi index sa tom vrednoscu...
{
    int i=0,cur=0;
    for (int k=logsiz[c];k>=0;k--) if (i+(1<<k)<=fwtsiz[c])
    {
        int sta=fwt[c][i+(1<<k)];
        if (cur+sta<x) i+=(1<<k),cur+=sta;
    }
    return i+1;
}

int MaxUpwalk(int p, int k)
{
    int r=president[p];
    if (dub[p]-dub[r]+1<=k)
    {
        int sta=MaxUpwalk(up[r],k-(dub[p]-dub[r]+1));
        if (sta==-1)
        {
            int c=chin[p];
            int F=walk(c,1);
            if (F-1>dub[p]-dub[r]) return -1;
            return podub[c][F-1];
        }
        return sta;
    }

    int c=chin[p];
    int F=walk(c,pre(c,dub[p]-dub[r]-k)+1);
    if (F-1>dub[p]-dub[r]) return -1;
    return podub[c][F-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    dfs(1,0);
    hfs(1,++idx,1);

    for (int c=1;c<=idx;c++)
    {
        int temp=chnt[c]+1;
        fwtsiz[c]=temp;
        fwt[c].resize(temp+1);
        int lele=0;
        while (temp>1)
        {
            temp>>=1;
            lele++;
        }
        logsiz[c]=lele;
    }

    for (int i=1;i<=n;i++)
    {
        cin>>ima[i];
        if (ima[i])
        {
            add(chin[i],dub[i]-dub[president[i]]+1);
        }
    }

    vector<int> cvormenjaniz(n);
    for (int i=0;i<n;i++) cin>>cvormenjaniz[i];

    for (int i=1;i<=n;i++)
    {
        int cvormenja=cvormenjaniz[i-1];
        if (cvormenja)
        {
            if (ima[cvormenja]) rmv(chin[cvormenja],dub[cvormenja]-dub[president[cvormenja]]+1);
            else add(chin[cvormenja],dub[cvormenja]-dub[president[cvormenja]]+1);
            ima[cvormenja]=!ima[cvormenja];
        }

        int p=i; //pocetni cvor
        int k=i; //jacina skoka
        int skokova=0;
        while (true)
        {
            skokova++;
            if (dub[p]<=k) break;
            int newp=MaxUpwalk(p,k);
            if (newp==-1 || newp==p) goto nemoze;
            p=newp;
        }

        cout<<skokova<<" ";
        continue;
        nemoze: cout<<-1<<" ";

        //cout<<endl<<endl;
    }
}