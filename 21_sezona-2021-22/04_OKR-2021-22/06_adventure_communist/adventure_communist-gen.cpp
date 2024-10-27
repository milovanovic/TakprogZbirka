#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

const int maxN = 1000005;
const int maxA = 1000000000;
const int mod = 1000000007;

int n, t;
long long a[maxN], k[maxN], c;

mt19937 mt(54268);

const string test = "testcases/";

long long modPow(long long a, long long p) {
	if (p == 0) return 1;

	long long ans, tmp = modPow(a, p / 2);
	ans = tmp * tmp;
	ans %= mod;

	if (p % 2) {
		ans *= a;
		ans %= mod;
	}

	return ans%mod;
}

long long solve() {
	long long p = 1, ans = (a[0] * modPow(c,t))%mod;

	for (int i = 1; i < n; i++) {
		p *= k[i];
		p %= mod;
		p *= (t - i + 1);
		p %= mod;

		long long tmp = a[i] * p;
		tmp %= mod;

		tmp *= modPow(c, t - i);
		tmp %= mod;

		ans += tmp;
		ans %= mod;
	}

	if (ans < 0) ans += mod;
	return ans;
}

void subtask0(string input, string output) {
	ofstream out_in(input), out_out(output);

	out_in << "3 3 2" << endl;
	out_in << "1 1 1" << endl;
	out_in << "1 1 1";

	out_out << "32";
}

void makeTest(int subtask, string input, string output) {
	ofstream out_in(input), out_out(output);

	switch (subtask) {
	case 1:
		n = 2000;
		break;
	case 2:
		n = 100;
		break;
	case 3:
		n = 200000;
		break;
	case 4:
		n = 1000;
		break;
	case 5:
		n = 200000;
		break;
	}

	int e8 = 100000000;

	if (subtask == 1) t = 2000;
	else t = 9 * e8 + mt() % e8;

	if (subtask != 3) c = 1 + mt() % (maxA - 1);
	else c = 1;

	out_in << n << " " << t << " " << c << endl;

	for (int i = 0; i < n; i++) {
		a[i] = mt() % maxA;
		k[i] = mt() % maxA;
	}

	for (int i = 0; i < n; i++) {
		out_in << a[i];
		if (i != n - 1) out_in << " ";
	}
	out_in << endl;

	for (int i = 0; i < n; i++) {
		out_in << k[i];
		if (i != n - 1) out_in << " ";
	}

	out_out << solve();
}

int subtask_cnt[] = {2, 6, 10, 14, 20};

int main() {
	
	subtask0(test + "1.in", test + "1.out");

	for (int i = 2; i < 2 + subtask_cnt[4]; i++) {
		string input = to_string(i) + ".in";
		string output = to_string(i) + ".out";

		if (i >= 2 && i < 2 + subtask_cnt[0]) {
			makeTest(1, test + input, test + output);
		}

		if (i >= 2 + subtask_cnt[0] && i < 2 + subtask_cnt[1]) {
			makeTest(2, test + input, test + output);
		}

		if (i >= 2 + subtask_cnt[1] && i < 2 + subtask_cnt[2]) {
			makeTest(3, test + input, test + output);
		}

		if (i >= 2 + subtask_cnt[2] && i < 2 + subtask_cnt[3]) {
			makeTest(4, test + input, test + output);
		}

		if (i >= 2 + subtask_cnt[3] && i < 2 + subtask_cnt[4]) {
			makeTest(5, test + input, test + output);
		}
	}
	return 0;
}