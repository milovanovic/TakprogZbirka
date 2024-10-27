#include<bits/stdc++.h>

using namespace std;

const long long maxN = 1e5+1;
const long long maxV = 1e9;

long long a[maxN], b[maxN];
int n;

long long lcm(long long x, long long y)
{
    return x*y / __gcd(x, y);
}

int main()
{
    cin>>n;

   assert(n>0 && n<maxN);

    for (int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        assert(a[i]>0 && a[i]<=maxV);
    }

    b[1] = a[1];
    b[n] = a[n-1];

    for (int i =2;i<n;i++)
        b[i] = lcm(a[i], a[i-1]);

    for (int i=1;i<n;i++)
        if (__gcd(b[i], b[i+1])!=a[i]) return !printf("-1\n");

    for (int i=1;i<=n;i++)
        printf("%lld ",b[i]);
    printf("\n");
}
