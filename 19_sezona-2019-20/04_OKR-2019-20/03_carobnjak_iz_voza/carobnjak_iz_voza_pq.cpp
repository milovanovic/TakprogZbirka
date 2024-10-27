#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000555
#define MAXSM 1000555

int n;
long long e;
priority_queue<int> pq;

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

    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }

    int res = 0;
    while(e > 0 && !pq.empty()) {
        e -= pq.top();
        pq.pop();
        res++;
    }

    printf("%d\n", res);

    return 0;
}