#include<bits/stdc++.h>
#define maxn 3000000
using namespace std;
int n;
char s[maxn];
int cnt[30];
int lcnt[30];
int pref() {
    for(int i=0;i<30;i++) cnt[i]=0;
    int l=0;
    while(s[l]==s[n-l-1]) l++;
    int it=1-n%2;
    int r=(n-1)/2;
    while(s[r]==s[r+it]) {
        r--;
        it+=2;
    }
    for(int i=l;i<=r;i++) cnt[s[i]-'a']++;
    for(int i=n-r-1;i<=n-l-1;i++) cnt[s[i]-'a']--;
    bool ok=true;
    for(int i=0;i<30;i++) {
        if(cnt[i]!=0) ok=false;
        cnt[i]=0;
    }
    if(ok) return r-l+1;
    return n;
}
int mid() {
    for(int i=0;i<30;i++) cnt[i]=0;
    int x=0;
    while(s[x]==s[n-x-1]) x++;
    for(int i=x;i<=n-x-1;i++) cnt[s[i]-'a']++;
    int min_ans=n;
    for(int i=x;2*i<n;i++) {
        min_ans=n-x-i;
        cnt[s[i]-'a']-=2;
        if(cnt[s[i]-'a']<0) return min_ans;
    }
    return min_ans;
}
int main() {
    scanf("%s",s);
    bool ok=true;
    n=strlen(s);
    assert(2<=n && n<=2000000);
    for(int i=0;i<n;i++) {
        assert('a'<=s[i] && s[i]<='z');
        cnt[s[i]-'a']++;
        if(s[i]!=s[n-1-i]) ok=false;
    }
    int odd=0;
    for(int i=0;i<30;i++) {
        odd+=cnt[i]%2;
    }
    assert(odd==n%2);
    if(ok) {
        printf("1");
        return 0;
    }
    int ans=min(pref(),mid());
    reverse(s,s+n);
    ans=min(ans,mid());
    printf("%d",ans);
    return 0;
}
