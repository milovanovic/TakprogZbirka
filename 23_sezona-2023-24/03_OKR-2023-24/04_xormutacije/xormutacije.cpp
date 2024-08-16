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

signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	int t;
	cin >> t;

	for (int e = 0; e < t; ++e){
		int n;
		cin >> n;

		vi a(n+1);
		for (int i = 0; i <= n; ++i){
			cin >> a[i];
		}

		vi res(n+1,0);
		int sol = 0;
		while(n){
			int k = log2(n);

			int m = 1<<k, suprotan = m-1;
			for (int i = m; i <= n; --suprotan, ++i){
				res[i] = suprotan;
				res[suprotan] = i;
				sol += (i^suprotan) * 2;
			}

			n=suprotan;
		}


		cout << sol << '\n';
		for (int i = 0; i < res.size(); ++i)
			cout << res[a[i]] << ' ';
		cout << '\n';
	}
}
