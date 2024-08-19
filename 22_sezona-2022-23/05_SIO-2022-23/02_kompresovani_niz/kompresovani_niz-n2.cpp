#include <bits/stdc++.h>
#define maxn 100005
#define maxl 31
using namespace std;
int n,k,l;
long long a[maxn];
long long dp_pref[maxn];
long long pv[maxl];
long long sum=0;
long long Resi(int N, int* A, int K)
{
    n=N;
    k=K;
    l=k-1;
    if(K==1) {
        for(int i=1;i<=N;i++) sum+=A[i];
        return sum;
    }
    for(int i=1;i<=N;i++) a[i]=A[i];
    for(int i=1;i<=n;i++) {
        dp_pref[i]=a[i]+dp_pref[i-1];
        int o=a[i];
        for(int j=i-1;j>=0;j--) {
            if((i-j)%l==1%l) dp_pref[i]=min(dp_pref[i],dp_pref[j]+o);
            o|=a[j];
        }
    }
    return dp_pref[n];
}
