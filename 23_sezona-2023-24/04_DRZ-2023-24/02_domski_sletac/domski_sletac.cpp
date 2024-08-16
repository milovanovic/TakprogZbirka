#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;


ifstream in;
ofstream out;

const int mod = 1e9+7;

signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vi(m, 0)), dp = a, rows = a, cols = a;

	for (auto& i : a)
		for(auto& j : i)
			cin >> j;

	for (int i = 0; i < n; ++i){
		rows[i][0] = a[i][0];
		for (int j = 1; j < m; ++j)
			rows[i][j] = rows[i][j-1] + a[i][j];
	}

	for (int j = 0; j < m; ++j){
		cols[0][j] = a[0][j];
		for (int i = 1; i < n; ++i)
			cols[i][j] = cols[i-1][j] + a[i][j];
	}

	auto pref_cols = vector<vector<int>>(n, vi(m, 0));
	auto pref_rows = pref_cols;
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			pref_rows[i][j] = pref_rows[i][j-1] + rows[i][j-1];

	for (int j = 0; j < m; ++j)
		for (int i = 1; i < n; ++i)
			pref_cols[i][j] = pref_cols[i-1][j] + cols[i-1][j];

	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			int levo = dp[i][j-1] + pref_cols[i][j];
			int gore = dp[i-1][j] + pref_rows[i][j];

			dp[i][j] = min(levo, gore);
		}
	}

	cout << dp[n-1][m-1] << '\n';
}