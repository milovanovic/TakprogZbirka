/*
	Simulacija u O(n * h).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

vector<vector<bool> > M;
int n, h;

vector<vector<int> > Index;
bool invertDiretion[1 << 20];
int blockBegins[1 << 20];
int blockEnds[1 << 20];

vector<int> ret;

void simulate(int r, int c) {
	if (r == n) {
		ret[c]++;
		return;
	}
	if (M[r][c]) {
		simulate(r + 1, c);
		return;
	}
	int dir;
	if ((r + 1) % 2 == 1)
		dir = -1;
	else
		dir = 1;
	int idx = Index[r][c];
	bool &inv = invertDiretion[idx];
	if (inv)
		dir *= -1;
	inv ^= 1;
	int newc;
	if (dir == -1) {
		if (blockBegins[idx] == 0)
			newc = blockEnds[idx] + 1;
		else
			newc = blockBegins[idx] - 1;
	}
	else {
		if (blockEnds[idx] == h - 1)
			newc = blockBegins[idx] - 1;
		else
			newc = blockEnds[idx] + 1;
	}
	simulate(r + 1, newc);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	
	cin >> n >> h;
	M.resize(n);
	Index.resize(n);
	int a;
	FOR (i, n) {
		M[i].clear();
		M[i].resize(h);
		FOR (j, h) {
			cin >> a;
			M[i][j] = a == 1;
		}
	}
	
	FOR (i, 1 << 20)
		blockBegins[i] = -2;
	int blockIdx = 0;
	FOR (i, n) {
		Index[i].resize(h);
		FOR (j, h)
			if (!M[i][j]) {
				if (!j || M[i][j - 1])
					blockIdx++;
				Index[i][j] = blockIdx;
				if (blockBegins[blockIdx] == -2)
					blockBegins[blockIdx] = j;
				blockEnds[blockIdx] = j;
			}
			else
				Index[i][j] = -1;
	}
	
	SET(invertDiretion, 0);
	ret.clear();
	ret.resize(h, 0);
	
	FOR (i, h)
		simulate(0, i);
	for (auto &v : ret)
		cout << v << " ";
	cout << endl;
	return 0;
}
