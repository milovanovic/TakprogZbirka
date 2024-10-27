#include<bits/stdc++.h>
#define maxn 3200
using namespace std;
int n,m;
long long a[maxn][maxn];
long long d[maxn][maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=0;i<3*n;i++) {
        for(int j=0;j<3*m;j++) {
            a[i][j]=a[i%n][j%m];
        }
    }
    for(int x=0;x<n;x++) {
        for(int y=0;y<m;y++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(i+1<n) {
                        d[x][y] = d[x][y]+abs(a[x+i+1][y+j]-a[x+i][y+j]);
                    }
                    if(j+1<m) {
                        d[x][y] = d[x][y]+abs(a[x+i][y+j+1]-a[x+i][y+j]);
                    }
                }
            }
        }
    }
    long long ans=d[0][0];
    for(int x=0;x<n;x++) {
        for(int y=0;y<m;y++) {
            ans=max(ans,d[x][y]);
        }
    }
    printf("%lld",ans);
    return 0;
}
