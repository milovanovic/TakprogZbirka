#include <iostream>
using namespace std;

typedef unsigned long long ull;

bool rek(ull a, ull b, ull x, int i) {
	ull y = b ^ x;
	ull m = (1ull << i) - 1;
	if (((x*y) ^ a) & m)
		return false;
	if (i == 32)
		return false;
	if (x*1.0*y < 5e18 && x*y == a) {
		cout << x << ' ' << y << '\n';
		return true;
	}
	if (rek(a, b, x, i+1))
		return true;
	return rek(a, b, x|(1ull<<i), i+1);
}

ull read_ull_19(istream& ifs) {
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	if (t > 500)
		return 1;
	while (t--) {
		ull a = read_ull_19(cin);
		ull b = read_ull_19(cin);
		if (!rek(a, b, 0, 0))
			cout << "-1\n";
	}
}