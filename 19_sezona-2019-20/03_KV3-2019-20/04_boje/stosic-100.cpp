#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, x;
};

int p[1000005], ps, mg, n, m, k;

int e(int x) {
	if (x == p[x])
		return x;
	return p[x] = e(p[x]);
}

void spoji(int x, int y) {
	x = e(x), y = e(y);
	if (x != y)
		p[x] = y, mg++;
}

template<class T>
void sweep(T& a, T& b) {
	auto it = b.begin();
	for (auto p : a) {
		while (it != b.end() && it->r <= p.l)
			++it;
		if (it != b.end() && p.r > it->l)
			spoji(p.x, it->x);
		
		while (it != b.end() && it->r <= p.r)
			++it;
		if (it != b.end() && p.r > it->l)
			spoji(p.x, it->x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	map<int, basic_string<int>> e;
	while (k--) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
	}
	iota(p, p+1000005, 0);

	basic_string<seg> ol;
	int h = 0;
	for (auto& p : e) {
		if (p.first != h+1) {
			int c = ps++;
			for (auto q : ol)
				spoji(q.x, c);
			ol = {{1, m+1, c}};
		}
		basic_string<seg> nu;
		int l = 1;
		sort(p.second.begin(), p.second.end());
		for (int x : p.second)
			if (x == l)
				l++;
			else
				nu += {l, x, ps++}, l = x+1;
		if (l <= m)
			nu += {l, m+1, ps++};
		sweep(ol, nu);
		sweep(nu, ol);
		swap(ol, nu);
		h = p.first;
	}
	if (h < n) {
		int c = ps++;
		for (auto p : ol)
			spoji(c, p.x);
	}
	cout << ps - mg << '\n';
}