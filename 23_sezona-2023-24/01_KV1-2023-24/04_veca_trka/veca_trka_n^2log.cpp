#include <bits/stdc++.h>
#define MAXN 150007
using namespace std;
int N;
long long x[MAXN],v[MAXN],K;
int main()
{
    scanf("%d%lld",&N,&K);
    for(int i=1;i<=N;i++) scanf("%lld%lld",&x[i],&v[i]);
    vector<double> pret;
    for(int i=1;i<=N;i++) for(int j=i+1;j<=N;j++) if(v[i]>v[j]) pret.push_back((x[j]-x[i])*(1.0/(v[i]-v[j])));
    sort(pret.begin(),pret.end());
    cout<<fixed<<pret[K-1];
}
