#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;


const int MAX_N = 300100;

int n, m, k;
int r[MAX_N]; // r[i] - redni broj takmicara koji sedi za racunarom i
bool mark[MAX_N];
vector<int> relevant;

int main()
{

	scanf("%d%d%d", &n, &m, &k);

	relevant.clear();
	for (int i = 1; i <= n; i++)
	{
		r[i] = i;
		mark[i] = false;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		int tmp = r[a]; r[a] = r[b]; r[b] = tmp;

		if (!mark[a])
		{
			mark[a] = true;
			relevant.push_back(a);
		}
		if (!mark[b])
		{
			mark[b] = true;
			relevant.push_back(b);
		}

		bool ok = true;
		for (int j = 0; j < relevant.size(); j++)
		{
			if (abs(relevant[j] - r[ relevant[j] ]) > k)
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
} // O(n + m^2)