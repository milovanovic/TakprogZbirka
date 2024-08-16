#include<bits/stdc++.h>
#define maxn 500000
using namespace  std;
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        int d,u;
        scanf("%d %d",&d,&u);
    }
    for(int i=1;i<=m;i++) {
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        printf("%d\n",r-l+1);
    }
    return 0;
}
