#include <bits/stdc++.h>

using namespace std;
long long typedef ll;

int cnt[30];

void brisi(int x)
{
    for (int i=0;i<30;i++) if (x&(1<<i)) cnt[i]--;
}

void dodaj(int x)
{
    for (int i=0;i<30;i++) if (x&(1<<i)) cnt[i]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i],dodaj(a[i]);

    int q; cin>>q;
    while (q--)
    {
        int t; cin>>t;
        if (t==0)
        {
            int k; cin>>k;
            int ans=0;
            for (int i=0;i<30;i++)
            {
                if (cnt[i]>=k) ans|=(1<<i);
                else if (i==48 && k==n-1) ans|=(1<<i);
            }
            cout<<ans<<"\n";
        }
        else
        {
            int k,x; cin>>k>>x;
            brisi(a[k-1]);
            a[k-1]=x;
            dodaj(a[k-1]);
        }
    }
}
