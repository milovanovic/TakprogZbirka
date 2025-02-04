#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define cin blabla
#define cout blablabaklldf

typedef long double ld;
typedef long long ll;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

ll read_ll(ifstream& ifs) {
	string s;
	ifs >> s;
	if (s.size() > 12 || s.empty())
		exit(-4);
	ll v = 0, m = 1;
	if (s[0] == '-') {
		m = -1;
		s.erase(s.begin());
	}
	if (s.empty())
		exit(-5);
	for (char c : s) {
		if (!isdigit(c))
			exit(-6);
		v = 10*v + c - '0';
	}
	return v*m;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	ll k = read_ll(inf), n = read_ll(ouf);
	if (n < 1 || n > 2000)
		return -1;
	vector<pair<ll, ll>> a(n);
	for (ll i=0; i<n; i++)
		a[i].first = read_ll(ouf), a[i].second = read_ll(ouf);

	const ll lim = 1'000'000'000;

	for (ll i=0; i<n; i++) {
		if (abs(a[i].first) > lim || abs(a[i].second) > lim)
			return -2;
		for (ll j=0; j<i; j++)
			if (a[i] == a[j])
				return -3;
	}

	ll out_k = 0;

	for (ll i=0; i<n; i++) {
		map<pair<ll, ll>, ll> mp;
		for (ll j=0; j<n; j++) {
			if (j != i) {
				ll x = a[i].first - a[j].first;
				ll y = a[i].second - a[j].second;
				if (x < 0 || (x == 0 && y < 0))
					x *= -1, y *= -1;
				ll g = gcd(abs(x), abs(y));
				x /= g;
				y /= g;
				mp[{x, y}]++;
			}
		}
		for (auto p : mp)
			out_k += p.second*(p.second-1)/2;
	}

	out_k /= 3;

	if (out_k != k)
		return -7;

	if (has_extra_tokens(ouf))
		return -8;
}
