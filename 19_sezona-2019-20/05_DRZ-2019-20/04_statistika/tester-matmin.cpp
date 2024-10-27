// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int NAJ = 60;

int n, m, q;
int a[1005][1005];
int z[NAJ][1005][1005];
int u[1000005], k;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			u[k++] = a[i][j];
		}
	}
	sort(u, u+k);
	k = unique(u, u+k) - u;
	k = min(k, NAJ);
	for (int i=0; i<k; i++) {
		for (int x=1; x<=n; x++) {
			for (int y=1; y<=m; y++) {
				z[i][x][y] = z[i][x-1][y] + z[i][x][y-1] - z[i][x-1][y-1] + (a[x][y] == u[i]);
			}
		}
	}

	while (q--) {
		int x, y, h, w, ok = 0;
		cin >> x >> y >> h >> w;
		x--, y--;
		for (int i=0; i<k; i++) {
			int d = z[i][n][m] - z[i][x+h][y+w] - z[i][x][y] + z[i][x+h][y] + z[i][x][y+w];
			if (d) {
				cout << d << '\n';
				ok = 1;
				break;
			}
		}
		if (!ok) cout << "1\n";
	}
}
