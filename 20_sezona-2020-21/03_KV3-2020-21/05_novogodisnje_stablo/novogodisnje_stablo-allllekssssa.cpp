#include<bits/stdc++.h>


using namespace std;


#define pb push_back
#define piii pair<pair<int ,int>, int>

const int maxN = 2e5;
const int sz = 1 << 18;

vector<int> v[maxN + 10];
int n, q, tim;
int tree[2 * sz], lazy[2 * sz];
int treec[2 * sz];
int par[maxN + 10], in[maxN + 10], out[maxN + 10], b[maxN + 10];

void dfs(int x, int pred)
{
	in[x] = ++tim;
	par[x] = pred;

	for (auto i : v[x])
		if (i != pred) dfs(i, x);

	out[x] = tim;
}

void push(int node)
{
	if (node >= sz)
	{
		if (lazy[node]) {
			tree[node] = 0;
			lazy[node] = 0;
		}

		return;
	}

	if (treec[node])
	{
		treec[2 * node] = treec[node];
		treec[2 * node + 1] = treec[node];
		treec[node] = 0;
	}

	if (lazy[node])
	{
		tree[node] =  0;
		lazy[2 * node] = 1;
		lazy[2 * node + 1] = 1;
		tree[2 * node] = 0;
		tree[2 * node + 1] = 0;
		lazy[node] = 0;
	}

	return;
}

void set_range(int node, int tl, int tr, int l, int r, int col)
{
	push(node);

	if (tl > r || tr < l) return;

	if (tl >= l && tr <= r) {
		treec[node] = col;
		lazy[node]  = 1;
		tree[node] =  0;
		return;
	}

	int mid = tl  + tr >> 1;

	set_range(2 * node, tl, mid, l, r , col);
	set_range(2 * node + 1, mid + 1, tr, l , r, col);

	tree[node] = tree[2 * node ] + tree[2 * node + 1];
}

int get_col(int x)
{
	x += sz - 1;

	int cl = treec[x];

	while (x > 0)
	{
		if (treec[x]) cl = treec[x];
		x /= 2;
	}

	return cl;
}

void set_one(int node, int tl, int tr, int x)
{
	push(node);

	if (tl == tr)
	{
		tree[node] = 1;
		lazy[node] = 0;

		return;
	}

	int mid = tl + tr >> 1;

	if (mid >= x) set_one(2 * node, tl, mid, x); else
		set_one(2 * node + 1, mid + 1, tr, x);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
	cin >> n >> q;

	assert(n <= maxN && n > 0 && q > 0 && q <= maxN);


	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		assert(b[i] > 0 && b[i] <= n);
	}

	dfs(1, 0);

	//tree_check
	for (int i = 1; i <= n; i++)
		assert(in[i]  > 0);


	tree[sz] = 1;

	for (int i = 1; i <= n; i++)
		treec[sz + in[i] - 1] = b[i];

	for (int i = 2; i <= n; i++)
		if (b[i] != b[par[i]]) {
			tree[sz - 1 + in[i]] = 1;
		}

	for (int i = sz - 1; i > 0; i--)
		tree[i] = tree[2 * i] + tree[2 * i + 1];

	while (q--)
	{
		int u, c;
		scanf("%d%d", &u, &c);
		assert(u > 0 && u <= n && c > 0 && c <= n);
		set_range(1, 1, sz, in[u], out[u], c);

		if (u == 1 || (get_col(in[u]) != get_col(in[par[u]])))
		{
			set_one(1, 1, sz, in[u]);
		}

		int ans = tree[1];

		printf("%d\n", ans);
	}
}
