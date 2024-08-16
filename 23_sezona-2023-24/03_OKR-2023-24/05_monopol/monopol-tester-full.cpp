#include <bits/stdc++.h>
#define maxn 3000000
using namespace std;
int k,n;
int a[maxn];
long long x[maxn];
long long pref[maxn];
priority_queue<long long> pq;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++) {
        cin>>a[i];
    }
    long long tot=0;
    for(int i=1;i<=n;i++)  {
        cin>>x[i];
        x[n+i]=x[i];
        tot+=x[i];
    }
    for(int i=1;i<=2*n;i++) {
        pref[i]=x[i]+pref[i-1];
    }
    sort(a,a+k);
    a[k]=a[0]+n;
    for(int i=0;i<k;i++) {
        if(a[i+1]-a[i]==1) continue;
        long long seg=0;
        long long mx=0;
        for(int j=a[i]+1;j<a[i+1];j++) {
            seg+=x[j];
            long long cur=0;
            long long lft=(a[i]+j)/2;
            long long rht=(a[i+1]+j)/2;
            cur=pref[rht]-pref[lft];
            if(lft-a[i]==j-lft) cur+=(x[lft]/2);
            if(a[i+1]-rht==rht-j) cur-=(x[rht]/2);
            mx=max(mx,cur);
        }
        pq.push(mx);
        pq.push(seg-mx);
    }
    int cnt=0;
    long long mn=0;
    while(!pq.empty()) {
        mn+=pq.top();
        pq.pop();
        cnt++;
        if(mn*2>tot) break;
    }
    if(mn*2>tot) cout<<cnt<<endl;
    else cout<<-1<<endl;
    return 0;
}
