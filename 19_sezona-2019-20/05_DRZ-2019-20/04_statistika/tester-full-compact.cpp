#include <bits/stdc++.h>
using namespace std;

struct elem {
	int x, c;

	elem(int x = 2e9, int c = 0) : x(x), c(c) {}

	elem operator+ (const elem& b) const {
		return x == b.x ? elem{x, c + b.c} : elem{min(x, b.x), x < b.x ? c : b.c};
	}
};

int n, m, q;
elem z[2][2][1005][1005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++)
		for (int j=1, x; j<=m; j++)
			cin >> x, z[0][0][i][j] = z[0][1][i][j] = z[1][0][i][j] = z[1][1][i][j] = elem(x, 1);
	for (int dx : {-1, 1}) {
		for (int dy : {-1, 1}) {
			auto f = z[dx>0][dy>0];
			for (int r : {0, 1}) {
				for (int i=~dx?1:n; i!=(~dx?n+1:0); i+=dx) {
					for (int j=~dy?1:m; j!=(~dy?m+1:0); j+=dy) {
						f[i][j] = f[i][j] + f[i-r*dx][j-!r*dy];
					}
				}
			}
		}
	}

	while (q--) {
		int x, y, h, w;
		cin >> x >> y >> h >> w;
		cout << (z[1][1][x+h-1][y-1] + z[0][0][x][y+w] + z[1][0][x-1][y] + z[0][1][x+h][y+w-1]).c << '\n';
	}
}
