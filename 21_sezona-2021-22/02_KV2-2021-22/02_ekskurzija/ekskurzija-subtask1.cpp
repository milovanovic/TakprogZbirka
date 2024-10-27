#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,k;
int main() {
    scanf("%d",&t);
    assert(1<=t && t<=10);
    while(t--) {
        scanf("%lld %lld %lld",&n,&m,&k);
        assert(1<=n && n==3);
        assert(1<=m && m<=100000000000000000ll);
        assert(1<=k && k<=n);
        if(k==1) {
            if(m>=6) printf("Tak\n");
            else printf("Nie\n");
        }
        if(k==2) {
            if(m>=4) printf("Tak\n");
            else printf("Nie\n");
        }
        if(k==3) {
            if(m>=3) printf("Tak\n");
            else printf("Nie\n");
        }
    }
    return 0;
}

