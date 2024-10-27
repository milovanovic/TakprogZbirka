#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5;
const int maxM = 10;

string t, s;
int n, m;
int dp[maxN + 1][maxM + 1];

void assert_lowercases(string str) {
	for (int i:str) {
		assert(i>='a' && i<='z');
	}
}

int main() {
    
  cin>>t;
  int n = t.size();

  assert(n > 0 && n <= maxN);
  assert_lowercases(t);
    
  cin>>s; 
	int m = s.size();


	assert(m > 0 && m <= maxM);
	assert_lowercases(s);

    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j<=m;j++) {
            dp[i][j] = maxN + 1;
      	}
    }

    dp[0][0] = 0;


    for (int i = 0; i < n; i++) { 
      for (int j = 0; j < m; j++) {
      	if (t[i] == s[j]) {       
           dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]  + 1);
           dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      	} else {
      		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      	}
      }
    }

    int ans = maxN + 1;
    int best_i = n;
    int best_j = m - 1;

    for (int j = 0; j < m; j++) {
    	ans = min(ans, dp[n][j]);
    	if (ans == dp[n][j]) {
    		best_j = j;
    	}
    }

    string ans_str = "";

    while(best_i != 0) {
       
       if (best_j!= 0 && dp[best_i][best_j] == dp[best_i - 1][best_j - 1]) {
             ans_str += t[best_i - 1];
             best_j--;    
        } else {
    		if (dp[best_i][best_j] == dp[best_i - 1][best_j] && t[best_i - 1] != s[best_j]) {
    			ans_str += t[best_i - 1];
    		} else {
    			ans_str+='*';
    		}
    	}
    	
    	best_i--;
    }

    reverse(ans_str.begin(), ans_str.end());

    cout<<ans<<endl;
    cout<<ans_str<<endl;

	return 0;
}