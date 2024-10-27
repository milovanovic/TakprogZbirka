#include <bits/stdc++.h>
using namespace std;
int a[200007],b[200007],lps[200007],n,q;
int findperiod()
{
    for(int i=0;i<n/2;i++) if(b[i]!=b[i+n/2]) return n;
    return n/2;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) b[i]=a[i]^a[(i+1)%n];
    printf("%d\n",findperiod());
    while(q--)
    {
        int p,v;
        scanf("%d%d",&p,&v);
        p--;
        a[p]=v;
        b[(p+n-1)%n]=a[(p+n-1)%n]^a[p];
        b[p]=a[p]^a[(p+1)%n];
        printf("%d\n",findperiod());
    }
}

