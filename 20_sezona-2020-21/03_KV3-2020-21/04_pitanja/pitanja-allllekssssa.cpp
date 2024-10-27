#include<bits/stdc++.h>


using namespace std;


const long long maxA = 5e10;
const int maxN = 2e5;
const int bl = 40;

long long a[maxN + 10];
int n, q;
long long sqp[bl][maxN + 10];

int main()
{
	cin >> n;

	assert(n <= maxN);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		assert(a[i] <= maxA && a[i] > 0);
	}

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j < bl; j++)
		{
			sqp[j][i] = a[i];
			if (j <= i) {
				sqp[j][i] = sqp[j][i - j] + a[i];
			}

		}
	}

	cin >> q;

	assert(q <= maxN);

	while (q--)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);

		assert(x > 0 && x <= y && y <= n && (y - x) % k == 0 && k <= n);
		long long ans = 0;
		if (k < bl) {
			ans = sqp[k][y] - sqp[k][x] + a[x];
		} else
		{
			for (int i = x; i <= y; i += k)
				ans += a[i];
		}

		printf("%lld\n", ans);
	}

}