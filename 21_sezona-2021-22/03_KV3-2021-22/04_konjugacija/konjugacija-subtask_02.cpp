#include<cstdlib>
#include<cstdio>

const int MAX_N = 150000;

int N;

int m[105][105];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		m[x][y]++;
	}

	long long sol = 0LL;
	for (int l1 = 0; l1 <= 100; l1++)
	{
		for (int r1 = l1; r1 <= 100; r1++)
		{
			for (int l2 = 0; l2 <= 100; l2++)
			{
				for (int r2 = l2; r2 <= 100; r2++)
				{
					if ((l1 == l2) && (r1 == r2))
					{
						sol = sol + (m[l1][r1] * (m[l1][r1] - 1));
					}
					else
					{
						if ((2 * l2 <= l1 + r1) && (l1 + r1 <= 2 * r2) &&
							(2 * l1 <= l2 + r2) && (l2 + r2 <= 2 * r1))
							sol = sol + m[l1][r1] * m[l2][r2];
					}
				}
			}
		}
	}
	
	sol = sol / 2;

	printf("%lld\n", sol);

	return 0;
}