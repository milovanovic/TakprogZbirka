#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[12], b[12], p[12], q[12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i] >> b[i], a[i]--, b[i]--;
	iota(p, p+n, 0);
	int w = 131321;
	do {
		iota(q, q+n, 0);
		do {
			int z = 0;
			for (int i=0; i<n; i++)
				z += abs(i - a[p[i]]) + abs(i - b[q[i]]);
			w = min(w, z);
		} while (next_permutation(q, q+n));
	} while (next_permutation(p, p+n));
	cout << w << '\n';
}