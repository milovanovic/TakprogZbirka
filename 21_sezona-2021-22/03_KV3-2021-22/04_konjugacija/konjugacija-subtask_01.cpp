#include<cstdlib>
#include<cstdio>

const int MAX_N = 150000;

int N;
int a[MAX_N + 10], b[MAX_N + 10];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}

	long long sol = 0LL;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if ((2 * a[j] <= a[i] + b[i]) && (a[i] + b[i] <= 2 * b[j]) &&
				(2 * a[i] <= a[j] + b[j]) && (a[j] + b[j] <= 2 * b[i]))
				sol++;
		}
	}

	printf("%lld\n", sol);

	return 0;
}