#include<bits/stdc++.h>
using namespace std;

#define MAXN 250555

int n;
long long e;
int a[MAXN];
bool mark[MAXN];

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

    int res = 0;
    while(e > 0) {
        int j = -1;
        for(int i=0; i<br; i++) if (!mark[i] && (j==-1 || a[i] > a[j])) j=i;
        e -= a[j];
        mark[j] = true;
        res++;
    }

    printf("%d\n", res);

    return 0;
}