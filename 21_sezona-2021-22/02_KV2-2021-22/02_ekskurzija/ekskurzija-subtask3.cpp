#include<bits/stdc++.h>
using namespace std;
int t;
bool check(long long n,long long m,long long k) {
    if(k==1) {
        return m>=n*(n+1)/2;
    }
    for(long long i=1;i<=n;i++) {
        if(check(n-i,m-i*(i+1)/2,k-1)) return true;
    }
    return false;
}
int main() {
    scanf("%d",&t);
    assert(1<=t && t<=10);
    while(t--) {
        long long n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        assert(1<=n && n<=10);
        assert(1<=m && m<=10);
        assert(1<=k && k<=n);
        if(check(n,m,k)) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}

