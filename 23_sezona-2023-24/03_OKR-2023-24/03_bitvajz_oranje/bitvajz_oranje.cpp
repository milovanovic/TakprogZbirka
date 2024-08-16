#include <bits/stdc++.h>

using namespace std;
long long typedef ll;

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    int q; cin>>q;
    while (q--)
    {
        int l; cin>>l;
        if (l<0)
        {
            ll r; cin>>r;
            a[-l-1]=r;
        }
        else
        {
            int r; cin>>r;
            if (r-l>=60)
            {
                cout<<0<<"\n";
                continue;
            }

            ll x=0;
            bool moze=true;
            for (int i=l-1;i<=r-1;i++)
            {
                if (x&a[i])
                {
                    moze=false;
                    break;
                }
                x|=a[i];
            }

            if (moze) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
}
