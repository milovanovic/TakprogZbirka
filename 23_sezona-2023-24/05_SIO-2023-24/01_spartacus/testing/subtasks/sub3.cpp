#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int sumk=0;
int sums=0;

bool vis[205];

int dp[504];

int MaxSpartanstvo(int n, int K, int p[], int s[], int k[])
{
    vector<pair<int,int>> predmeti;

    for (int i=1;i<=n;i++) if (!vis[i])
    {
        sumk=0,sums=0;
        int pos=i;
        do{
            vis[pos]=true;
            sumk+=k[pos];
            sums+=s[pos];
            pos=p[pos];
            if (pos==0) break;
        } while (!vis[pos]);

        predmeti.push_back({sumk,sums});
    }

    for (auto it : predmeti)
    {
        for (int j=501;j>=it.first;j--)
        {
            dp[j]=max(dp[j],dp[j-it.first]+it.second);
        }
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
