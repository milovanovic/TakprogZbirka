#include<bits/stdc++.h>
using namespace std;
int novcanica_za_cifru(int a) {
    int rt=0;
    while(a>=5) {
        a-=5;
        rt++;
    }
    while(a>=2) {
        a-=2;
        rt++;
    }
    while(a>=1) {
        a-=1;
        rt++;
    }
    return rt;
}
int main() {
    long long k;
	scanf("%lld",&k);
	int ans=0;
	for(;k>0;k/=10) ans+=novcanica_za_cifru(k%10);
	printf("%d",ans);
	return 0;
}
