#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 200005
using namespace std;
int n;
int k;
int a[maxn];
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    n=atoi(argv[2]);

    k=atoi(argv[3]);

    int mx=atoi(argv[4]);

    int mn=atoi(argv[5]);

    if(strcmp(argv[1],"common")==0) {

        for(int i=1;i<=n;i++) {
            a[i]=rnd.next(-mn,mx);
        }
    }

    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++) {
        printf("%d",a[i]);
        if(i!=n) printf(" ");
        else printf("\n");
    }
    return 0;
}
