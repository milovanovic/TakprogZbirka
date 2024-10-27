#include<bits/stdc++.h>
#define maxn 3000000
using namespace std;
int n;
char s[maxn];
int cnt[30];
int lcnt[30];
int pref() {
    int l=0;
    while(s[l]==s[n-l-1]) l++;
    int it=1-n%2;
    int r=(n-1)/2;
    while(s[r]==s[r+it]) {
        r--;
        it+=2;
    }
    return r-l+1;
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
    printf("%d",pref());
    return 0;
}
