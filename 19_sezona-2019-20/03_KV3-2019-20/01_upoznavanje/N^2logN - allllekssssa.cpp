#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi = 1e6+10;
int a[maxi];
int n;
int x;

int main()
{
    assert(n<=1e6);
    cin>>n>>x;

    assert(x>=-1e8 && x<=1e8);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        assert(a[i]>=-1e8 && a[i]<=1e8);
    }

    sort(a+1, a+n+1);

    if (x<=a[1]) return !printf("%d\n", a[n] - x);
    if (x>=a[n]) return !printf("%d\n",x-a[1]);
    return !printf("%d\n", min(2*a[n] - x - a[1], a[n] + x - 2*a[1]));
}
