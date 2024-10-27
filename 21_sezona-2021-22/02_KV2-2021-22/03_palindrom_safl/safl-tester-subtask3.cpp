#include<bits/stdc++.h>
#define maxn 3000000
using namespace std;
int n;
char s[maxn];
int cnt[30];
int main() {
    scanf("%s",s);
    bool ok=true;
    n=strlen(s);
    assert(1<=n && n<=3000);
    int ans=n;
    for(int i=0;i<n;i++) {
        int cnt_b=0;
        for(int k=0;2*k<n;k++) {
            int rev_k=n-k-1;
            if(s[k]!=s[rev_k]) cnt_b++;
        }
        for(int j=i;j<n && j-i+1<ans;j++) {
            int rev_j=n-j-1;
            if(rev_j<i || rev_j>j) {
                if(s[j]!=s[rev_j]) cnt_b--;
            }
            cnt[s[j]-'a']++;
            if(rev_j<i || rev_j>j) {
                cnt[s[rev_j]-'a']--;
            }
            else {
                if(j!=rev_j) cnt[s[j]-'a']++;
            }
            bool ok=true;
            for(int k=0;k<30;k++) if(cnt[k]<0) ok=false;
            if(ok && cnt_b==0) ans=min(ans,j-i+1);
        }
        for(int k=0;k<30;k++) cnt[k]=0;
    }
    printf("%d",ans);
    return 0;
}
