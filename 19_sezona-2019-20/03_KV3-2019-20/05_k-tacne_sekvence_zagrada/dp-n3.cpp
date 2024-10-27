#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 1000;
const int offs = maxn + 10;
ull* dp[maxn+5][maxn+5];

void ad(ull& x, ull y) {
	if (x + y < x)
		x = ~(x^x);
	else
		x += y;
}

ull& daj_simple(int len, int dip, int bal) {
	return dp[len][dip][bal + offs];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<maxn+5; i++)
		for (int j=0; j<maxn+5; j++)
			dp[i][j] = new ull[2*offs];

	daj_simple(0, 0, 0) = 1;
	for (int i=0; i<maxn+2; i++) {
		for (int j=0; j<maxn+2; j++) {
			for (int k=-maxn-1; k<=maxn+1; k++) {
				ull v = dp[i][j][k + offs];
				if (k == -j) {
					ad(daj_simple(i+1, j+1, k-1), v);
				} else {
					ad(daj_simple(i+1, j, k-1), v);
				}
				ad(daj_simple(i+1, j, k+1), v);
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		ull t;
		cin >> n >> k >> t;
		// moze?
		ull ways = 0;
		for (int dip=0; dip<=k; dip++) {
			for (int bal=-dip; bal<=k-2*dip; bal++) {
				ad(ways, daj_simple(n, dip, bal));
			}
		}

		if (t > ways) {
			cout << "Ne postoji\n";
			continue;
		}

		int udip = 0, ubal = 0;
		string sol;
		for (int i=0; i<n; i++) {
			int vdip = udip, vbal = ubal + 1;
			ull ways = 0;

			for (int d=0; d<=n; d++) {
				for (int b=i-n; b<=n-i; b++) {
					int dd = max(vdip, -vbal+d);
					int bb = vbal + b;
					if (2*dd + bb <= k)
						ad(ways, daj_simple(n-i-1, d, b));
				}
			}
			
			if (t <= ways) {
				sol += '(';
				ubal++;
			} else {
				t -= ways;
				sol += ')';
				if (ubal == -udip)
					udip++;
				ubal--;
			}
		}
		cout << sol << '\n';
	}
}