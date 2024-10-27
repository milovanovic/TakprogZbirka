#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxV = 200000;
const int maxA = 1000000000;

int n, m, a[maxV + 2], pref[maxV + 2], tot[maxV + 2];

int main() {
    
    scanf("%d%d", &n, &m);
    assert(n > 0 && n <= maxV);
    assert(m > 0 && m <= maxV);
    
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	assert(a[i] >= 0 && a[i] <= maxA);
    }

    int answer = 0;

    for (int i = 1; i <= m; i++) {
    	int l, r;
    	scanf("%d%d", &l, &r);

        for (int j = l; j <= r; j++) {
            if (a[j] == 0) {
                answer++;
                break;
            }
        }
    	tot[l]++;
    	tot[r + 1]--;
    }
    
    for (int i = 1; i <= n; i++) {
    	tot[i]+=tot[i - 1];
    }
    
    printf("%d\n", answer);

	return 0;
}