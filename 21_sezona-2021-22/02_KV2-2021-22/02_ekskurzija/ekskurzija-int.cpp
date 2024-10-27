#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&m,&k);
        int t=n/k;
        int min_number=(t+1)*(t+2)/2*(n%k)+t*(t+1)/2*(k-n%k);
        if(m>=min_number) printf("Tak\n");
        else printf("Nie\n");
    }
    return 0;
}
