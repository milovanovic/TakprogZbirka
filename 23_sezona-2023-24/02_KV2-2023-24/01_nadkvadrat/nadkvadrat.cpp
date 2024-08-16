#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> x(3);
    vector<int> y(3);

    for (int i=0;i<3;i++) cin>>x[i]>>y[i];

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int len=max(x[2]-x[0],y[2]-y[0]);
    cout<<(long long)len*len;
}
