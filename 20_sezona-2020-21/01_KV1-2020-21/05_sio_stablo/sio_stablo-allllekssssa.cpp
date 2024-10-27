#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int, int>

const int maxi = 1e6 + 10;

vector<pii> v[maxi];

int n;
long long ans;
int ob[maxi];
int d[maxi];
map<pair<pii, int>, int > mp;
map<pii, int> mp1;


int num(char ch)
{
    if (ch == 'S') return 0;
    if (ch == 'I') return 1;
    return 2;
}

void dfs(int x, int par)
{
    d[x] = 1;
    for (auto i:v[x])
        if (i.first != par && !ob[i.first]){
         dfs(i.first, x);
         d[x]+=d[i.first];
    }
}

int center;

void find_center(int node, int root, int par)
{
    int mx = d[root] - d[node];

    for (auto i:v[node])
        if (i.first != par && !ob[i.first])
        {
            mx = max(mx, d[i.first]);
            find_center(i.first, root, node);
        }

    if (mx <= d[root]/2) center = node;
}

void traverse(int node, int root, int par, pii pathVal)
{
   mp1[pathVal]++;
   mp[{pathVal, root}]++;
   if (pathVal.first == 0 && pathVal.second == 0) ans+=2;

   for (auto i:v[node])
    if (!ob[i.first] && i.first != par)
   {
       pii pathVal1 = pathVal;
       if (i.second == 0)
       {
           pathVal1.first--;
           pathVal1.second--;
       }

       if (i.second == 1) pathVal1.first++;
       if (i.second == 2) pathVal1.second++;

       traverse(i.first, root, node, pathVal1);
   }
}


void decompose(int node)
{

   dfs(node, 0);

   find_center(node, node, 0);

   mp.clear();
   mp1.clear();

   ob[center] =  1;

   for (auto i:v[center])
    if (!ob[i.first])
   {
       pii val = {0, 0};
       if (!i.second) val = {-1, -1};
       if (i.second == 1) val = {1, 0};
       if (i.second == 2) val = {0, 1};

       traverse(i.first, i.first, 0, val);

   }

   for (auto i:mp)
   {
       pii val = i.first.first;
       val.first*=-1;
       val.second*=-1;
       ans+= 1ll*i.second * (mp1[val] - mp[{val, i.first.second}]);
   }

   for (auto i:v[center]){
    if (!ob[i.first])
     decompose(i.first);
    }
}

int main()
{
    cin>>n;
    assert(n<=int (3e5) && n>0);

    for (int i = 1;i<n;i++)
    {
        int x, y;
        char ch;
        scanf("%d%d %c", &x, &y, &ch);
        assert(x!=y && x>0 && x<=n && y>0 && y<=n); // not enough for the tree
        assert(ch=='S' || ch == 'I' || ch == 'O');
        v[x].pb({y, num(ch)});
        v[y].pb({x, num(ch)});
    }

    decompose(1);

    cout<<ans/2<<endl;
}
