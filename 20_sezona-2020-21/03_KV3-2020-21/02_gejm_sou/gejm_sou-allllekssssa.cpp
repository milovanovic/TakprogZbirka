#include<bits/stdc++.h>


using namespace std;


const int maxA = 1e9;
const int maxN = 1e5;

int n;
int a[maxN + 10], b[maxN + 10];

int main()
{
	cin >> n;
	assert(n > 0 && n <= maxN);

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		assert(abs(a[i]) <= maxA && abs(b[i]) <= maxA);
		if (i == 1) continue;
		ans = ans + min(max(abs(a[i] - a[i - 1]), abs(b[i] - b[i - 1])), max(abs(a[i] - b[i - 1]), abs(b[i] - a[i - 1])));
	}

	cout << ans << endl;

}