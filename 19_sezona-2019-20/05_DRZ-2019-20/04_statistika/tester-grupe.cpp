// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, q;

int expect_int(int lo, int hi) {
	string s;
	cin >> s;
	if (s.size() > 15)
		throw 0;
	ll x = 0;
	for (char c : s) {
		if (!isdigit(c))
			throw 0;
		x = 10*x + c - 48;
	}
	if (x < lo || x > hi)
		throw 0;
	if (x == 0 && s != "0")
		throw 0;
	return x;
}

void expect_eof() {
	string s;
	cin >> s;
	if (s.size())
		throw 0;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	n = expect_int(1, 1'000);
	m = expect_int(1, 1'000);
	q = expect_int(1, 100'000);
	int amax = 0, smax = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int x = expect_int(0, 1'000'000'000);
			amax = max(amax, x);
		}
	}

	for (int i=0; i<q; i++) {
		int x = expect_int(1, n);
		int y = expect_int(1, m);
		int h = expect_int(1, n);
		int w = expect_int(1, m);
		if (x+h-1 > n || y+w-1 > m)
			throw 0;
		if (x == 1 && y == 1 && h == n && w == m)
			throw 0;
		smax = max({smax, h, w});
	}

	expect_eof();

	// grupa 1
	if (n <= 100 && q <= 100) {
		throw 0;
	}

	// grupa 2
	if (n <= 300 && m <= 300 && q <= 20000) {
		throw 0;
	}

	// grupa 3
	if (amax <= 1) {
		throw 0;
	}

	// grupa 4
	if (smax <= 10) {
		throw 0;
	}

}
