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


const int maxn = 2e5 + 10;
vi e[maxn], a(maxn);
vi p(maxn), sub(maxn);
vector<vi> dp(maxn, vi(2, 0));

void dfs(int x, int y = 0){

	p[x] = y;

	for (auto& i : e[x]){
		if (i == y) continue;

		dfs(i, x);
	}	
}

vi red, blue;

void povrati(int x, int v, int par = 1){
	if (v == 0 && dp[x][0] < dp[x][1]){
		for (auto& i : e[x]){
			if (i == p[x]) continue;

			povrati(i, 1, 1-par);
		}

		return;
	}

	int s = 0;
	int suma = a[x];
	for (auto& i : e[x]){
		if (i == p[x]) continue;
		suma += dp[i][0];
		s += dp[i][1];
	}

	if (suma == dp[x][1]){
		if (par)
			red.push_back(x);
		else
			blue.push_back(x);

		for (auto& i : e[x]){
			if (i == p[x]) continue;

			povrati(i, 0, 1-par);
		}

		return;
	}	

	int ind;
	for (auto& i : e[x]){
		if (i == p[x]) continue;

		suma = sub[i] + a[i] + s - dp[i][1];

		if (suma == dp[x][1]){
			ind = i;
			break;
		}
	}

	for (auto& i : e[x]){
		if (i == p[x] || i == ind) continue;

		povrati(i, 1, 1-par);
	}

	if (par)
		blue.push_back(ind);
	else
		red.push_back(ind);

	for (auto& i : e[ind]){
		if (i == x) continue;

		povrati(i, 0, par);
	}
}

signed main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i){
		cin >> a[i];

		e[i].clear();
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1);

	vi d(n+1, 0);
	queue<int> q;

	for (int i = 2; i <= n; ++i){
		if ((int)e[i].size() == 1){
			q.push(i);
			dp[i][0] = 0;
			dp[i][1] = a[i];
		}
	}

	while(!q.empty()){
		int c = q.front();
		q.pop();

		++d[p[c]];

		if ((int)e[c].size() == 1 && c != 1){

			if (d[p[c]] == (int)e[p[c]].size() && p[c] == 1){
				q.push(1);
			}

			if (d[p[c]] + 1 == (int)e[p[c]].size() && p[c] != 1){
				q.push(p[c]);
			}

			continue;
		}

		dp[c][1] = a[c];
		int s = 0;
		for (auto& i : e[c]){
			if (i == p[c]) continue;
			dp[c][1] += dp[i][0];
			s += dp[i][1];
		}

		for (auto& i : e[c]){
			if (i == p[c]) continue;

			dp[c][1] = min(dp[c][1], sub[i] + a[i] + s - dp[i][1]);
			
		}

		dp[c][0] = s;

		dp[c][0] = min(dp[c][0], dp[c][1]);

		for (auto& i : e[c])
			if (i != p[c])
				sub[c] += dp[i][0];


		if (d[p[c]] == (int)e[p[c]].size() && p[c] == 1){
			q.push(1);
		}

		if (d[p[c]] + 1 == (int)e[p[c]].size() && p[c] != 1){
			q.push(p[c]);
		}			
	}

	povrati(1, 1);


	cout << dp[1][1] << '\n';

	cout << red.size() << '\n';
	for (int x : red)
		cout << x << ' ';
	cout << '\n';

	cout << blue.size() << '\n';
	for (int x : blue)
		cout << x << ' ';
	cout << '\n';
}