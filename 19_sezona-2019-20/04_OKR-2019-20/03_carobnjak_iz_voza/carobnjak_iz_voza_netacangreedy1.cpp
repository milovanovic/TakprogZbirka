// uzima samo obicne magije redom, sve dok je suma epcijalnih > e

#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000555
#define MAXSM 1000555

int n;
long long e;
priority_queue<int> pq;
int m[MAXN];

int main() {

    int x;

    scanf("%d%lld", &n, &e);
    
    int br = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        while(x > 0) {
            pq.push(x);
            x /= 2;
        }
    }

    int ss = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &m[i]);
        ss += m[i];
    }

    sort(m,m+n);

    int res = 0;
    while(e > ss && !pq.empty()) {
        e -= pq.top();
        pq.pop();
        res++;
    }

    for(int i=n-1; i>=0; i--) {
        e -= m[i];
        res++;
        if (e <= 0) break;
    }

    printf("%d\n", res);

    return 0;
}