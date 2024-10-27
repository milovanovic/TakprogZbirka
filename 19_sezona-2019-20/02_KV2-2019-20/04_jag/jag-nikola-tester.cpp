#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX_N = 100100;

vector<int> adj[MAX_N];
int du[MAX_N], dv[MAX_N];
int n, d;
int Au, Av, Auv, Bu, Bv, Buv;

int BFS(int start, int dist[])
{
	queue<int> q;
	bool mark[MAX_N];
	for (int i = 1; i <= n; i++)
		mark[i] = false;
	
	q.push(start);
	mark[start] = true;
	dist[start] = 0;

	int last = 0;

	while (!q.empty()) 
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)adj[u].size(); i++)
		{
			int v = adj[u][i];
			if (!mark[v])
			{
				q.push(v);
				mark[v] = true;
				dist[v] = dist[u] + 1;
				last = v;
			}
		}
	}

	return last;
}

int solve()
{
	if (Au + Av + Auv >= 3)
	{
		if ((Au == 1 && Av == 1 && Auv == 1) || (Au == 1 && Auv == 0) || (Av == 1 && Auv == 0))
		{
			if (n % 2 == 1)
				return d;
			else
				return d - 1;
		}
		return d;
	}
		
	if (n % 2 == 1)
		return d - 1;

	if ((Bu == 1 && Bv == 1 && Buv <= 1) || (Bu == 1 && Buv == 0) || (Bv == 1 && Buv == 0))
		return d - 2;
	else
		return d - 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int u = BFS(1, du);
	int v = BFS(u, du);
	BFS(v, dv);
	d = du[v];

	for (int i = 1; i <= n; i++)
	{
		if (du[i] == d && dv[i] < d) Av++;
		if (du[i] < d && dv[i] == d) Au++;
		if (du[i] == d && dv[i] == d) Auv++;

		if (du[i] == d - 1 && dv[i] < d - 1) Bv++;
		if (du[i] < d - 1 && dv[i] == d - 1) Bu++;
		if (du[i] == d - 1 && dv[i] == d - 1) Buv++;
	}

	printf("%d\n", solve());

	return 0;
}