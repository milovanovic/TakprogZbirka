#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxV = 200000;
const int maxA = 1000000000;

int n, m, a[maxV + 2], pref[maxV + 2], tot[maxV + 2];
vector<int> in[maxV];
multiset<int> st;

int main() {
    
    scanf("%d%d", &n, &m);
    assert(n > 0 && n <= maxV);
    assert(m > 0 && m <= maxV);
    
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	assert(a[i] >= 0 && a[i] <= maxA);
    }

    for (int i = 1; i <= m; i++) {
    	int l, r;
    	scanf("%d%d", &l, &r);
    	assert(l > 0 && l <= r);
    	assert(r > 0 && r <= n);
    	in[l].pb(r);
    	tot[l]++;
    	tot[r + 1]--;
    }

    for (int i = 1; i <= n; i++) {
    	tot[i]+=tot[i - 1];
    }


    int currentRemoved = 0;
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        for (int x: in[i]) {
        	st.insert(x);
        }

        currentRemoved-=pref[i];

        while(tot[i] - currentRemoved > a[i]) {
        	answer++;
        	currentRemoved++;
        	int val = *st.rbegin();
        	st.erase(st.find(val));
        	pref[val + 1]++;
        }
    }
    
    printf("%d\n", answer);

	return 0;
}