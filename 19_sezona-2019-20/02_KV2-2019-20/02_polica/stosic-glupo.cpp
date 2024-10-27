#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1000005], b[1000005];
basic_string<int> e[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> a[i];
		e[a[i]] += i;
	}

	for (int i=0; i<10; i++)
		if (e[i].size() > 4)
			e[i] = e[i].substr(0, 2) + e[i].substr(e[i].size()-2);

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int x : e[i]) {
				for (int y : e[j]) {
					if (x < y) {
						swap(a[x], a[y]);
						if (lexicographical_compare(b, b+n, a, a+n))
							copy(a, a+n, b);
						swap(a[x], a[y]);
					}
				}
			}
		}
	}

	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
}