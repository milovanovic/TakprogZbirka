#include <bits/stdc++.h>
#include "testlib.h"
#define maxn 3000000
using namespace std;
int n,k,t;
int val[30];

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    n=atoi(argv[1]);

    k=atoi(argv[2]);
    
    t=atoi(argv[3]);

    printf("%d %d\n",n,k);

    for(int i=0;i<30;i++) val[i]=rnd.wnext(13,t);

    for(int i=1;i<=n;i++) {
        if(strcmp(argv[4],"random")==0) {
            printf("%d",rnd.next(1000000000));
        }
        if(strcmp(argv[4],"one-two")==0) {
            printf("%d",rnd.next(2)+1);
        }
        if(strcmp(argv[4],"bit-density")==0) {
            int a=0;
            for(int j=0;j<30;j++) {
                if(!rnd.next(1<<val[j])) a|=(1<<j);
            }
            if(a>1000000000) a^=(1<<29);
            printf("%d",a);
        }
        if(i!=n) printf(" ");
        else printf("\n");
    }
    
    return 0;
}
