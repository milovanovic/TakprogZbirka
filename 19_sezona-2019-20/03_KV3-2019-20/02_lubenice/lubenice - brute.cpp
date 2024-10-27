#include<bits/stdc++.h>

using namespace std;

int k1, k2, k3;
long long l, r;
int main()
{
    cin >> k1 >> k2 >> k3 >> l >> r ;

    long long ans = 0;
    for (long long i = l; i <= r ; i++)
    if ( ( i + k1 - 1 ) / k1 + (i + k2 - 1) / k2 + (i + k3 - 1) / k3 <= i)
        ans++;

    cout<<ans<<endl;
}
