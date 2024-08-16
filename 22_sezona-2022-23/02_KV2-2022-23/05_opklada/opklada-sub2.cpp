#include <bits/stdc++.h>
#define MAXN 307
using namespace std;
int l[MAXN][MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int t=0;t<2;t++) for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&l[i][j]);
        bool fail =false;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(l[i][j]+l[0][0]!=l[i][0]+l[0][j]) fail=true;
        if(fail) {printf("NE\n"); continue;}
        printf("DA\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) printf("%d ",l[i][j]);
            printf("\n");
        }
    }
}
