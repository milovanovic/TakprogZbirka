#include<bits/stdc++.h>


using namespace std;

const int maxN = 1e5;
const int maxK = 1e9;

int a[maxN + 10];
long long pref[maxN + 10];
int n, k;

void solve()
{
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pref[i] = pref[i - 1] + a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (pref[i] > k) break;

		int l  = i;
		int r =  n + 1;

		while (l < r - 1)
		{
			int mid = r + l >> 1;

			if (pref[mid] - pref[i] > k) r = mid; else l = mid;
		}

		long long val = pref[l] - pref[i];
		if (val <= pref[i]) {
			printf("da\n");
			return;
		}
	}

	printf("ne\n");
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		solve();
}