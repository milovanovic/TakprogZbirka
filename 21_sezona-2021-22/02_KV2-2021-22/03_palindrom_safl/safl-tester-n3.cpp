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
    //assert(1<=n && n<=50);
    int ans=n;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n && j-i+1<ans;j++) {
            bool ok=true;
            for(int k=0;k<n && ok;k++) {
                if(k<i || k>j) {
                    int rev_k=n-k-1;
                    if(rev_k<i || rev_k>j) {
                        if(s[k]!=s[rev_k]) ok=false;
                    }
                }
            }
            for(int k=i;k<=j && ok;k++) {
                int rev_k=n-k-1;
                cnt[s[k]-'a']++;
                if(rev_k<i || rev_k>j) {
                    cnt[s[rev_k]-'a']--;
                }
            }
            for(int k=0;k<30;k++) if(cnt[k]<0) ok=false;
            if(ok) ans=min(ans,j-i+1);
            for(int k=0;k<30;k++) cnt[k]=0;
        }
    }
    printf("%d",ans);
    return 0;
}
