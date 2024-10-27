#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,k;
int main() {
    scanf("%d",&t);
    assert(1<=t && t<=10);
    while(t--) {
        scanf("%lld %lld %lld",&n,&m,&k);
        assert(1<=n && n<=1000000000);
        assert(1<=m && m<=100000000000000000ll);
        assert(1<=k && k<=n && k==1);
        if(n*(n+1)/2<=m) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}

