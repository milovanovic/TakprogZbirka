// Retired?
#include <bits/stdc++.h>
using namespace std;

void mn(int& x, int y) {
	x = min(x, y);
}

void mx(int& x, int y) {
	x = max(x, y);
}

struct rect {
	int x0 = 2e9, x1 = -1, y0 = 2e9, y1 = -1;
};

struct pt {
	int x, y;
};

int n, m, q;
int a[1005][1005];
map<int, rect> mbr;
map<int, vector<pt>> e;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int v;
			cin >> v;
			a[i][j] = v;
			auto& rv = mbr[v];
			mn(rv.x0, i);
			mn(rv.y0, j);
			mx(rv.x1, i);
			mx(rv.y1, j);
			e[v].push_back({i, j});
		}
	}

	while (q--) {
		int x, y, h, w;
		cin >> x >> y >> h >> w;

		for (auto& it : mbr) {
			auto& v = it.first;

			auto& rct = it.second;
			if (x <= rct.x0 && rct.x1 <= x+h-1 && y <= rct.y0 && rct.y1 <= y+w-1) {
				continue;
			}

			int br = 0;
			for (auto& it : e[v]) {
				auto px = it.x;
				auto py = it.y;
				if (x <= px && px <= x+h-1 && y <= py && py <= y+w-1) {
					continue;
				}

				br++;
			}

			cout << br << '\n';
			break;
		}
	}
}
