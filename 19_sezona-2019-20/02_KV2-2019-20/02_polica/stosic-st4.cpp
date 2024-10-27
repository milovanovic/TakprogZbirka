#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1005], b[1005];

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
			if (lexicographical_compare(b, b+n, a, a+n))
				copy(a, a+n, b);
			swap(a[i], a[j]);
		}
	}

	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
}