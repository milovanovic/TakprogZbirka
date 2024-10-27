#include<bits/stdc++.h>
#define maxn 3005
using namespace std;
char s[maxn];
int dp[maxn][maxn];
int seg[4*maxn];
int laz[4*maxn];
int n;
inline void create_segment_tree(int id,int l,int r,int pos) {
    laz[id]=0;
    if(l==r) {
        seg[id]=dp[l][pos];
        return;
    }
    int m=(l+r)/2;
    create_segment_tree(id*2+1,l,m,pos);
    create_segment_tree(id*2+2,m+1,r,pos);
    seg[id]=max(seg[id*2+1],seg[id*2+2]);
}
inline void propagate(int id,int l,int r) {
    seg[id]+=laz[id];
    if(l!=r) {
        laz[id*2+1]+=laz[id];
        laz[id*2+2]+=laz[id];
    }
    laz[id]=0;
}
inline void update(int id,int l,int r,int p) {
    propagate(id,l,r);
    if(r<=p) {
        laz[id]=1;
        propagate(id,l,r);
        return;
    }
    if(p<l) {
        return;
    }
    int m=(l+r)/2;
    update(id*2+1,l,m,p);
    update(id*2+2,m+1,r,p);
    seg[id]=max(seg[id*2+1],seg[id*2+2]);
}
int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++) {
        assert('a'<=s[i] && s[i]<='z');
    }
    for(int l=1;l<=n;l++) {
        for(int r=l;r<=n;r++) {
            dp[l][r]=-n;
            if(l==1) dp[l][r]=0;
        }
    }
    for(int l=3;l<=n;l++) {
        create_segment_tree(0,1,l-1,l-1);
        if(s[l]==s[l-1]) update(0,1,l-1,l-1);
        for(int r=l+1;r<=n;r++) {
            if(2*l-r-1>=1 && s[r]==s[2*l-r-1]) update(0,1,l-1,2*l-r-1);
            dp[l][r]=seg[0];
        }
    }
    int ans=0;
    for(int l=1;l<=n;l++) ans=max(ans,dp[l][n]);
    printf("%d",ans);
    return 0;
}
