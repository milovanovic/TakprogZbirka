#include <bits/stdc++.h>
using namespace std;
int x[10007],y[10007],m;
bool jesmek(int a)
{
    int p=0,q=0,r=0,s=0;
    for(int i=0;i<=m;i++)
    {
        if(x[i]<x[a] && y[i]<y[a]) p++;
        if(x[i]<x[a] && y[i]>y[a]) q++;
        if(x[i]>x[a] && y[i]<y[a]) r++;
        if(x[i]>x[a] && y[i]>y[a]) s++;
    }
    return (p==s) && (q==r);
}
int main()
{
    int n;
    cin>>n;
    while(m<n)
    {
        cin>>x[m]>>y[m];
        int a=-2;
        for(int i=0;i<=m;i++) if(jesmek(i)) a=i;
        printf("%d\n",a+1);
        m++;
    }
}
