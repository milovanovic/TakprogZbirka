#include <bits/stdc++.h>
using namespace std;

#define cin blabla
#define cout blablabaklldf

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

ull read_ull_19(ifstream& ifs) {
	string s;
	ifs >> s;
	if (s.size() == 0 || s.size() > 19)
		exit(-1);
	ull z = 0;
	for (char x : s) {
		if ('0' <= x && x <= '9')
			z = 10*z + x - '0';
		else
			exit(-1);
	}
	return z;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	int t;
	inf >> t;
	while (t--) {
		ull a = read_ull_19(inf);
		ull b = read_ull_19(inf);

		string a1;
		sof >> a1;
		if (a1 == "-1") {
			string a2;
			ouf >> a2;
			if (a2 != "-1") {
				return -1;
			}
		} else {
			sof >> a1; // ignore both
			ull x = read_ull_19(ouf);
			ull y = read_ull_19(ouf);
			if (x*1.0*y < 5e18 && x*y == a && (x^y) == b) {
				// ok
			} else {
				return -1;
			}
		}
	}

	if (has_extra_tokens(ouf))
		return -1;
}
