#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n, q;
int p[maxn];
int d[maxn];
long long gt[maxn];
long long ad[maxn];
long long off[maxn];
void solve()
{
    long long cur = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += d[i];
        if (p[i])
        {
            int steps = d[i] / p[i] + 1;
            int j = i + steps - 1;
            if (j <= n)
            {
                ad[j] += p[i];
                off[j] += (1ll * p[i] * (j - i) - d[i]);
            }
        }
        cur += ad[i];
        sum += off[i];
        sum += cur;
        gt[i] = sum;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> p[i];
    }
    solve();
    while (q--)
    {
        int x;
        cin >> x;
        if (x > gt[n])
            cout << -1 << endl;
        else
        {
            int l = 1;
            int r = n;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (gt[m] >= x)
                    r = m;
                else
                    l = m + 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
