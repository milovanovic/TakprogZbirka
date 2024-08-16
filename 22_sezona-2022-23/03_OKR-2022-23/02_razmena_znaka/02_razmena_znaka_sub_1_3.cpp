#include <bits/stdc++.h>
#define MAXN 30007
using namespace std;
int a[MAXN],b[MAXN];
map<int,int> mp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        mp.clear();
        for(int i=0;i<n;i++) mp[(2*(i&1)-1)*a[i]]=true;
        bool ok=true;
        for(int i=0;i<n;i++) if(!mp[(2*(i&1)-1)*b[i]]) ok=false;
        if(ok) cout<<"DA\n";
        else cout<<"NE\n";
    }
}
