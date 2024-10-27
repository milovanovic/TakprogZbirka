#include <bits/stdc++.h>
using namespace std;
int a[200007],b[200007],n,q;
vector<int> d;
int findperiod()
{
    for(int i=0;i<d.size();i++)
    {
        int p=d[i];
        bool fas=false;
        for(int i=0;i<n-p && !fas;i++) if(b[i]!=b[p+i]) fas=true;
        if(!fas) return p;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) b[i]=a[i]^a[(i+1)%n];
    for(int i=1;i<=n;i++) if(n%i==0) d.push_back(i);
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
