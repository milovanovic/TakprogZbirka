#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k, m1=0, p1=0, nu=0;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x == -1)
			m1++;
		else if (x == 0)
			nu++;
		else if (x == 1)
			p1++;
	}

	cout << (m1 >= k) + (nu >= k) + (p1 >= k) << '\n';
	if (m1 >= k)
		cout << "-1 ";
	if (nu >= k)
		cout << "0 ";
	if (p1 >= k)
		cout << "1 ";
}