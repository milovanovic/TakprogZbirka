#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

typedef long double ld;

int h, w, r, q;

struct krug {
	int x, y;

	krug(int x=1e8, int y=1e8) : x(x), y(y) {}

	ld operator* (int t) const {
		if (t < x-r || t > x+r)
			return 1e50;
		return y - sqrt(ld(r+t-x)*(r-t+x));
	}
};

vector<krug> b;

ld racunaj(int x) {
	ld sol = h;
	for (auto& k : b)
		sol = min(sol, k * x);
	return max(ld(0), sol);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(12) << fixed;
	
	cin >> w >> h >> r >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 2) {
			int x;
			cin >> x;
			cout << racunaj(x) << '\n';
		} else if (t == 1) {
			int x, y;
			cin >> x >> y;
			b.emplace_back(x, y);
		}
	}
}

