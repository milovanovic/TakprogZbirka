#include <bits/stdc++.h>
using namespace std;
int a[200007],b[200007],n,q;
vector<int> d;
void assertperiod()
{
    for(int i=0;i<d.size();i++)
    {
        int p=d[i];
        bool fas=false;
        for(int i=0;i<n-p && !fas;i++) if(a[i]!=a[p+i]) fas=true;
        if(!fas) printf("UMRO");
    }

}
int main()
{
    for(int tc=1;tc<=22;tc++)
    {
        ifstream in("testcases\\"+to_string(tc)+".in");
        in>>n>>q;
        for(int i=0;i<n;i++) in>>a[i];
        for(int i=1;i<n;i++) if(n%i==0) d.push_back(i);
        assertperiod();
        while(q--)
        {
            int p,v;
            in>>p>>v;
            p--;
            a[p]=v;
            assertperiod();
        }
        printf("%d\n",tc);
    }
}
