#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll f(ll x) {
	return x*(x-1)*(x-2)/6;
}

ll flb(ll x) {
	ll l=0, r=1e4, o=0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (f(m) <= x)
			o = m, l = m + 1;
		else
			r = m - 1;
	}
	return o;
}

void test1() {
	const ll cap = 1e8;
	ll sofar = 7, used = 13, lines = 4;
	while (sofar < cap) {
		ll b = 1;
		while (f(b+1) - f(b) < sofar)
			b++;
		lines++;
		sofar += f(b-1);
		used += b-1;
		cerr << lines << ' ' << used << ' ' << sofar << '\n';
	}
}

void test2() {
	const int h = 100'000'000;
	vector<int> p(h+1);
	vector<int> l(h+1);
	vector<int> c(h+1);
	for (int i=1; i<=h; i++) {
		int b = flb(i);
		int j = i - f(b);
		p[i] = j;
		l[i] = l[j] + 1;
		c[i] = c[j] + b;
	}
	int i;

	i = max_element(l.begin(), l.end()) - l.begin();
	cerr << i << ' ' << l[i] << '\n';
	i = max_element(c.begin(), c.end()) - c.begin();
	cerr << i << ' ' << c[i] << '\n';

	for (int i=1, z=0; i<=h && z<7; i++) {
		if (c[i] >= 1040) {
			z++;
			cerr << "kul " << i << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test1();
	test2();
}