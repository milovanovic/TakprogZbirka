#include<bits/stdc++.h>
using namespace std;
int t;
bool check(long long n,long long m,long long k,long long prev) {
    if(k==1) {
        return m>=n*(n+1)/2;
    }
    for(long long i=1;i<=min(prev,n);i++) {
        if(check(n-i,m-i*(i+1)/2,k-1,i)) return true;
    }
    return false;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        long long n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        if(check(n,m,k,n)) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}

