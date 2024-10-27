#include <cstdlib>
#include <cstdio>

const int MAX_N = 300100;

int n, m, k;
int r[MAX_N]; // r[i] - redni broj takmicara koji sedi za racunarom i

int main()
{
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++) r[i] = i;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		int tmp = r[a]; r[a] = r[b]; r[b] = tmp;

		bool ok = true;
		for (int j = 1; j <= n; j++)
		{
			if (abs(j - r[j]) > k)
			{
				ok = false;
				break;
			}
		}

		if (ok)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
} // O(n * m)