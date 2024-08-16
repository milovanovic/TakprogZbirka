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
    for(int i=1;i<=n;i++)  {
        cin>>x[i];
        x[n+i]=x[i];
    }
    sort(a,a+k);
    a[k]=a[0]+n;
    long long tot=n*x[1];
    for(int i=0;i<k;i++) {
        if(a[i+1]-a[i]==1) continue;
        if(a[i+1]-a[i]==2) {
            pq.push(x[1]);
        }
        else {
            long long d=a[i+1]-a[i]-1;
            long long f=x[1]*(d+1)/2;
            pq.push(f);
            pq.push(d*x[1]-f);
        }
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