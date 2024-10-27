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

	rect operator+ (const rect& b) const {
		return {min(x0, b.x0), max(x1, b.x1), min(y0, b.y0), max(y1, b.y1)};
	}

	rect& operator+= (const rect& b) {
		return *this = *this + b;
	}
};

rect jedan(int x, int y) {
	return {x, x, y, y};
}

struct pt {
	int x, y;
};

int n, m, q;
int a[1005][1005];
int u[1000005], k;
rect pref_mbr[1000005];
vector<pt> e[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int v;
			cin >> v;
			a[i][j] = v;
			u[k++] = v;
		}
	}

	sort(u, u+k);
	k = unique(u, u+k) - u;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int o = lower_bound(u, u+k, a[i][j]) - u;
			pref_mbr[o] += jedan(i, j);
			e[o].push_back({i, j});
		}
	}

	for (int i=1; i<k; i++) {
		pref_mbr[i] += pref_mbr[i-1];
	}

	while (q--) {
		int x, y, h, w;
		cin >> x >> y >> h >> w;

		int lo = 0, hi = k, o = -1;

		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			auto rct = pref_mbr[mid];

			if (x <= rct.x0 && rct.x1 <= x+h-1 && y <= rct.y0 && rct.y1 <= y+w-1) {
				lo = mid + 1;
			} else {
				o = mid;
				hi = mid - 1;
			}
		}

		int br = 0;

		for (auto& it : e[o]) {
			auto px = it.x;
			auto py = it.y;
			if (x <= px && px <= x+h-1 && y <= py && py <= y+w-1) {
				continue;
			}

			br++;
		}

		cout << br << '\n';
	}
}
