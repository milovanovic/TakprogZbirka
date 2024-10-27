#include<bits/stdc++.h>
#define maxn 3000000
using namespace std;
int n;
char s[maxn];
int cnt[30];
bool check(int t) {
    int i=0;
    int j=t-1;
    int cnt_b=0;
    for(int i=0;i<30;i++) cnt[i]=0;
    for(int k=i;k<=j;k++) {
        cnt[s[k]-'a']++;
        int rev_k=n-k-1;
        if(rev_k<i || rev_k>j) cnt[s[rev_k]-'a']--;
    }
    for(int k=0;2*k<n;k++) {
        int rev_k=n-k-1;
        if((k<i || k>j) && (rev_k<i || rev_k>j)) {
            if(s[k]!=s[rev_k]) cnt_b++;
        }
    }
    while(j<n) {
        bool ok=true;
        for(int i=0;i<30;i++) {
            if(cnt[i]<0) ok=false;
        }
        if(cnt_b==0 && ok) return true;
        if(j==n-1) return false;
        int rev=n-i-1;
        if(rev<i || rev>j) {
            if(s[i]!=s[rev]) cnt_b++;
            cnt[s[rev]-'a']++;
        }
        else {
            cnt[s[i]-'a']--;
        }
        cnt[s[i]-'a']--;
        i++;
        j++;
        cnt[s[j]-'a']++;
        rev=n-j-1;
        if(rev<i || rev>j) {
            if(s[j]!=s[rev]) cnt_b--;
            cnt[s[rev]-'a']--;
        }
        else {
            cnt[s[j]-'a']++;
        }
    }
    return false;
}
int main() {
    scanf("%s",s);
    bool ok=true;
    n=strlen(s);
    int l=1,r=n;
    while(l<r) {
        int m=(l+r)/2;
        if(check(m)) r=m;
        else l=m+1;
    }
    printf("%d",l);
    return 0;
}
