#include<bits/stdc++.h>

using namespace std;

const int maxN = (int) 2e5;
const int maxA = (int) 1e9;

int n, q;
long long a[maxN + 10];
long long pref[maxN + 10];

long long sum(long long x)
{
	return x * (x + 1) / 2;
}

int main()
{
	scanf("%d", &n);
	assert(n <= maxN);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pref[i] = pref[i - 1] + a[i];
		assert(a[i] > a[i - 1] && a[i] <= maxA);
	}

	scanf("%d", &q);

	assert(q > 0 && q <= maxN);

	while (q--) {
		long long x;
		scanf("%lld", &x);
		assert(x > 0 && x <= maxA);

		int lo = 0;
		int ro = n + 1;

		while (lo < ro - 1)
		{
			int mid = lo + ro >> 1;
			if (a[mid] <= x + mid - 1) lo = mid; else ro = mid;
		}

		long long ans = sum(x + lo - 1) - sum(x - 1) - pref[lo];
		ans += pref[n] - pref[lo] - sum(x + n - 1) + sum(x + lo - 1);
		printf("%lld\n", ans);
	}
}
