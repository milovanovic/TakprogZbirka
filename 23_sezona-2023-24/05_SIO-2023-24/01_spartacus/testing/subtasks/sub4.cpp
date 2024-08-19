#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int sumk=0;
int sums=0;

vector<int> g[205];
int s[205],k[205];

int tp[205][504];
int tren[205][504];
int dp[504];
int dren[504];

void dfs(int p, int q)
{
    for (auto it : g[p]) if (it!=q)
    {
        dfs(it,p);
        for (int i=0;i<=500;i++) tren[p][i]=tp[p][i];
        for (int i=500;i>=0;i--)
        {
            for (int kk=500;kk>=0;kk--)
            {
                if (i>=kk)
                {
                    tren[p][i]=max(tren[p][i],tp[p][i-kk]+tp[it][kk]);
                }
            }
        }
        for (int i=0;i<=500;i++) tp[p][i]=tren[p][i];
    }
    for (int i=500;i>=k[p];i--) tp[p][i]=tp[p][i-k[p]]+s[p];
    for (int i=k[p]-1;i>=0;i--) tp[p][i]=-1e9;
}

int MaxSpartanstvo(int n, int K, int p[], int _s[], int _k[])
{
    for (int i=1;i<=n;i++) s[i]=_s[i];
    for (int i=1;i<=n;i++) k[i]=_k[i];
    for (int i=1;i<=n;i++) if (p[i])
    {
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    for (int i=1;i<=n;i++) if (!p[i])
    {
        dfs(i,0);
        for (int j=0;j<=500;j++) dren[j]=dp[j];
        for (int kk=K;kk>=0;kk--)
        {
            for (int j=K;j>=kk;j--) dren[j]=max(dren[j],dp[j-kk]+tp[i][kk]);
        }
        for (int j=0;j<=500;j++) dp[j]=dren[j];
    }

    return dp[K];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;

    int *p = new int[N+1];
    int *s = new int[N+1];
    int *k = new int[N+1];

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> k[i];
    }

    cout << MaxSpartanstvo(N, K, p, s, k) << endl;

    delete[] p;
    delete[] s;
    delete[] k;
    return 0;
}
