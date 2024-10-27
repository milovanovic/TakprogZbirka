#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ull a[88], sol, b[88];

ull pars() {
	ll x = 0;
	for (int i=0; i<n; i++)
		x = 10*x + a[i];
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			swap(a[i], a[j]);
			if (pars() > sol) {
				sol = pars();
				copy(a, a+n, b);
			}
			swap(a[i], a[j]);
		}
	}

	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
}