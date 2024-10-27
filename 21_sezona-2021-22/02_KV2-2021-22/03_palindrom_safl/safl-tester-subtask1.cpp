#include<bits/stdc++.h>
#define maxn 3000005
using namespace std;
char s[maxn];
int n;
int main() {
    scanf("%s",s);
    n=strlen(s);
    assert(n<=2000000);
    int x=-1,y=-1;
    int cntb=0;
    for(int i=0;i<n;i++) {
        assert(s[i]=='a' || s[i]=='b');
        if(s[i]=='b') {
            cntb++;
            if(cntb==1) x=i;
            else y=i;
        }
    }
    assert(cntb==2);
    int umid;
    int bmid;
    if(n%2==0) {
        umid=n/2;
        bmid=n/2-1;
    }
    if(n%2==1) {
        umid=n/2+1;
        bmid=n/2-1;
    }
    printf("%d",min(max(max(x,y),umid)-min(min(x,y),bmid)+1,abs(x+y-n+1)+1));
    return 0;
}
