#include <bits/stdc++.h>
#define maxn 3000000
using namespace std;
int k,n;
int a[maxn];
long long x[maxn];
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
    sort(a,a+k);
    a[k]=a[0]+n;
    for(int i=0;i<k;i++) {
        if(a[i+1]-a[i]==1) continue;
        long long seg=0;
        long long mx=0;
        for(int j=a[i]+1;j<a[i+1];j++) {
            seg+=x[j];
            long long cur=x[j];
            for(int k=a[i]+1;k<j;k++) {
                if(j-k<k-a[i]) cur+=x[k];
                if(j-k==k-a[i]) cur+=x[k]/2;
            }
            for(int k=j+1;k<a[i+1];k++) {
                if(k-j<a[i+1]-k) cur+=x[k];
                if(k-j==a[i+1]-k) cur+=x[k]/2;
            }
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
