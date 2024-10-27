#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int,int>

const int maxN = 5e4 + 10;
int n;
long long r;
int x[maxN], y[maxN];
vector<pii> circle, can;

int main()
{
    scanf("%d%lld",&n,&r);

    for (int i  = 1; i<=n; i++)
        scanf("%d%d",&x[i],&y[i]);

    circle.pb({0, r});
    circle.pb({0, -r});
    circle.pb({r, 0});
    circle.pb({-r, 0});

    long long z = r;
    for (long long i = 1; i<=r-1; i++)
    {
        while(i*i + z*z > r*r) z--;

        if (z*z + i*i == 1ll*r*r)
        {
            circle.pb({i, z});
            circle.pb({i, -z});
            circle.pb({-i, z});
            circle.pb({-i, -z});
        }
    }

    for (int i = 1; i<=n; i++)
        for (auto j:circle)
        {
            int xi = x[i] - j.first;
            int yi = y[i] - j.second;
            can.pb({xi, yi});
        }

    sort(can.begin(), can.end());

    long long ans = 0;

    long long cur = 1;
    for (auto i = 1; i < can.size(); i++)
        if (can[i]!=can[i-1])
        {
            ans+=cur*(cur - 1)*(cur - 2) / 6;
            cur =  1;
        }
        else
            cur++;

    ans+=cur*(cur - 1)*(cur - 2) / 6;

    cout<<ans<<endl;

    return 0;
}
