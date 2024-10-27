#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    for(int i=0;i<n;i++) cnt[a[i]-'a']++;
    int mn=n;
    for(int i=0;i<m;i++) mn=min(mn,cnt[b[i]-'a']);
    cout<<mn<<endl<<a;
}
