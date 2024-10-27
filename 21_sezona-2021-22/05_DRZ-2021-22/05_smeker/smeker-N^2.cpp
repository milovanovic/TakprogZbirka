#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > vx,vy;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        vx.push_back({x,i});
        vy.push_back({y,i});
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        int a=vx[i/2].second,b=vy[i/2].second;
        if((i&1) && a==b) printf("%d\n",a);
        else printf("-1\n");

    }
}
