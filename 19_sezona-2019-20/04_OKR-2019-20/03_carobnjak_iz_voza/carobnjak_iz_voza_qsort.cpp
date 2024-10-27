#include<bits/stdc++.h>
using namespace std;

#define MAXN 25000555

int n;
long long e;
int a[MAXN];

int main() {

    int x;

    scanf("%d%lld", &n, &e);
    
    int br = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        while(x > 0) {
            a[br++] = x;
            x /= 2;
        }
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        a[br++] = x;
    }

    sort(a,a+br);

    int res = 0;
    for(int i=br-1; i>=0; i--) {
        e -= a[i];
        res++;
        if (e <= 0) break;
    }

    printf("%d\n", res);

    return 0;
}