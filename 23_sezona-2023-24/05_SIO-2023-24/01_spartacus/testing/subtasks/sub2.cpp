#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int MaxSpartanstvo(int n, int K, int p[], int s[], int k[])
{
    int ans=0;
    int sumk=0,sums=0;
    for (int i=1;i<=n;i++)
    {
        sumk+=k[i],sums+=s[i];
        if (sumk<=K) ans=max(ans,sums);
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
