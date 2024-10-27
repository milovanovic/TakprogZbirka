#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1000005], b[1000005], n, k, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=n; i>=-n; i--)
		if (count(a, a+n, i) >= k)
			b[e++] = i;
	cout << e << '\n';
	for (int i=0; i<e; i++)
		cout << b[i] << " \n"[i == e-1];
}