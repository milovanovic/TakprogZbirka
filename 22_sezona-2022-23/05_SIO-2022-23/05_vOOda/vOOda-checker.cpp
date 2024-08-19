#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>

#define maxN 3003
#define maxM 3003
#define maxP 16

using namespace std;

int n, m, cnt[maxN][maxN], deg[maxN][maxM];
string s[maxN];

bool checkAndUpdate(int x, int y) {
	if (cnt[x][y] == 2) return false;
	cnt[x][y]++;
	if (cnt[x][y] == 2) return true;

	return false;
}

void add(int x, int y) {
	cnt[x][y] = 2;
	if (x > 0 && s[x - 1][y] == '.') {
		if (checkAndUpdate(x - 1, y)) add(x - 1, y);
	}
	if (x < n - 1 && s[x + 1][y] == '.') {
		if (checkAndUpdate(x + 1, y)) add(x + 1, y);
	}
	if (y > 0 && s[x][y - 1] == '.') {
		if (checkAndUpdate(x, y - 1)) add(x, y - 1);
	}
	if (y < m - 1 && s[x][y + 1] == '.') {
		if (checkAndUpdate(x, y + 1)) add(x, y + 1);
	}
}

int points[maxP], P;
int x, y, total;

int main(int argc, char* argv[])
{
	ifstream outFile(argv[1]);
	ifstream solFile(argv[2]);
	ifstream inFile(argv[3]);

	inFile >> n >> m;

	for (int i = 0; i < n; i++) {
		inFile >> s[i];
	}

	solFile >> P;

	for (int i = 0; i < P; i++) {
		solFile >> points[i];
	}

	outFile >> total;

	if (total < 0 || total > points[0]) {
		return -1; // mora ovako jer kad vratis 0 petlja ispise 1
	}

	long long last = 0, dif;

	for (int i = 0; i < total; i++) {
		outFile >> dif;

		if (dif <= 0) {
			return -1; // mora ovako jer kad vratis 0 petlja ispise 1
		}
		if (dif > m*n) {
			return -1; // mora ovako jer kad vratis 0 petlja ispise 1
		}

		last += dif;

		x = (last - 1) / m;
		y = (last - 1) % m;

		if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#') {
			return -1; // mora ovako jer kad vratis 0 petlja ispise 1
		}

		if(cnt[x][y]!=2) add(x, y);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') continue;
			if (cnt[i][j] != 2) {
				return -1; // mora ovako jer kad vratis 0 petlja ispise 1
			}
		}
	}

	int p = 0;
	while (p < P && total <= points[p]) {
		p++;
	}

	return p;
}
