#include<bits/stdc++.h>
using namespace std;

#define MAXN 2333555
#define MAXSM 2333555

int n;
long long e;
int s[MAXN],m[MAXN],cnt[MAXSM],cnt2[MAXSM];

int main() {

    scanf("%d%lld", &n, &e);

    int ss = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &s[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%d", &m[i]);
        ss += m[i];
    }

    for(int i=0; i<n; i++) {
        cnt2[m[i]]++;
        while(s[i] > 0) {
            cnt[s[i]]++;
            s[i] /= 2;
        }
    }

    int res = 0;
    for(int i=MAXSM-1; i>=1; i--) {
        while(e > ss && cnt[i] > 0) {
            e -= i;
            cnt[i]--;
            res++;
        }
    }

    for(int i=MAXSM-1; i>=1; i--) {
        while(e > 0 && cnt2[i] > 0) {
            e -= i;
            cnt[i]--;
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}