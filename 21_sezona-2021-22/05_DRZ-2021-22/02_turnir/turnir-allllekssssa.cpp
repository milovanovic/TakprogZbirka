#include<bits/stdc++.h>

using namespace std;

const int maxV = 1e4 + 10;

long long dp[202][maxV];
long long s[maxV];
int n, m, k;
long long a[202][202];

int main() {
    
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
    	cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    	}

    	sort(a[i] + 1, a[i] + m + 1);
    }
   
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= k; j++) {
        	dp[i][j] = dp[i-1][j];

        	for (int l = 1; l <= m; l++) {
        		if (a[i][l] + 1 <= j) {
        			dp[i][j] = max(dp[i][j], dp[i-1][j - a[i][l] - 1] + l * s[i]);
        		}
        	}

        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
    	ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
	return 0;
}