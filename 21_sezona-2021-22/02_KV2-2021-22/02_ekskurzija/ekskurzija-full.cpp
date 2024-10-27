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
        assert(1<=k && k<=n);
        long long t=n/k;
        long long min_number=(t+1)*(t+2)/2*(n%k)+t*(t+1)/2*(k-n%k);
        if(m>=min_number) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}
