#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int MaxSpartanstvo(int n, int K, int p[], int s[], int k[])
{
    if (n>30) while (true);
    int ans=0;
    for (int mask=0;mask<(1<<n);mask++)
    {
        bool good=true;
        for (int i=1;i<=n;i++) if (p[i]>0)
        {
            if (mask&(1<<(i-1)) && !(mask&(1<<(p[i]-1)))) good=false;
        }
        if (good)
        {
            int sumk=0,sums=0;
            for (int i=1;i<=n;i++) if (mask&(1<<(i-1)))
            {
                sumk+=k[i];
                sums+=s[i];
            }
            if (sumk<=K) ans=max(ans,sums);
        }
    }

    return ans;
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
