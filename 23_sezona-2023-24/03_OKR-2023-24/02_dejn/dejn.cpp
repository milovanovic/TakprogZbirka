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

bool cmp(int a, int b){
	return abs(a) < abs(b);
}

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

		map<int, int> m;
		for (int i = 0; i < n; ++i){
			int x;
			cin >> x;

			if (m[-1 * x] > 0){
				--m[-1 * x];
			} else {
				m[x]++;
			}
		}

		bool ok = 1;
		vi a;
		for (auto& i : m){
			if (i.second > 1){
				ok = 0; break;
			}

			if (i.second == 0) continue;
			a.push_back(i.first);
		}

		sort(a.begin(), a.end(), cmp);
		n = a.size();

		if (n % 2 || !ok){
			cout << "-1\n";
			continue;
		}

		int sol = 0;
		for (int i = 0; i < n; ++i){
			if (i % 2 && a[i] > 0){
				ok = 0; break;
			}

			if (i % 2 == 0 && a[i] < 0){
				ok = 0; break;
			}

			if (i % 2){
				sol += -1 * a[i] -a[i-1];
			}
		}

		if (!ok) sol = -1;
		cout << sol << '\n';
	}
}