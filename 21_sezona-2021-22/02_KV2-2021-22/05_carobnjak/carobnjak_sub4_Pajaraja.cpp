#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
long long a[MAXN];
long long jeje(vector<long long> v1,vector<long long> v2,int k)
{
    int a=v1.size(),b=v2.size();
    vector<long long> v;
    for(int i=0;i+1<a;i++) v.push_back(v1[i]);
    for(int i=1;i<b;i++) v.push_back(-v2[i]);
    long long sol=v1[a-1]-v2[0];
    sort(v.begin(),v.end(),greater<long long>());
    for(int i=0;i<k-2;i++) sol+=v[i];
    return sol;

}
long long knaj(vector<long long> vl,vector<long long> vr,int k)
{
    long long ret1=0,ret2=0;
    sort(vl.begin(),vl.end());
    sort(vr.begin(),vr.end());
    return max(jeje(vl,vr,k),jeje(vr,vl,k));
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    long long sol=0;
    for(int i=1;i<n;i++)
    {
        vector<long long> vl,vr;
        for(int j=1;j<=i;j++) vl.push_back(a[j]);
        for(int j=i+1;j<=n;j++) vr.push_back(a[j]);
        sol=max(sol,knaj(vl,vr,k));
    }
    cout<<sol;
}
