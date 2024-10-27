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
        assert(1<=m && m<=100000000000000000);
        assert(1<=k && k<=n);
        long long min_number=0;
        for(int i=0;i<k;i++) {
            if(i<(n%k)) {
                for(int j=1;j<=n/k+1;j++) min_number=min_number+j;
            }
            else {
                for(int j=1;j<=n/k;j++) min_number=min_number+j;
            }
        }
        if(m>=min_number) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}
