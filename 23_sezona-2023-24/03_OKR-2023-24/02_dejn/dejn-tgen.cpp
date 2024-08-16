#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

signed main()
{
	ofstream in;
	ofstream out;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


	//vs str = {"03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22"};

	vs str = {"10", "11", "12", "13", "14", "15"};

	for (auto st : str){
		in.open("../testcases/" + st + ".in");
		out.open("../testcases/" + st + ".out");

		int t = 5;
		in << t << '\n';

		int n = 1e5;

		//prvi test primer --------------------------------------------------------
		in << n << '\n';

		for (int i = 0; i < n; ++i){
			int x = uniform_int_distribution<int>(1, 1e5)(rng);

			int zn = uniform_int_distribution<int>(1, 20)(rng);
			if (zn % 2)
				x *= -1;

			in << x << ' ';
		}
		in << '\n';

		//drugi test primer------------------------------------------------------

		in << n << '\n';

		vi a;
		for (int i = 0; i < n; ++i){
			int x = uniform_int_distribution<int>(1, 1e5)(rng);
			a.push_back(x);
		}
		sort(a.begin(), a.end());

		for (int i = 0; i < n; ++i)
			if (i % 2) a[i] *= -1;

		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());

		for (int x : a)
			in << x << ' ';
		in << '\n';


		//treci test primer---------------------------------------------------------

		n = 1e5-1;
		in << n << '\n';

		a = {};
		for (int i = 0; i < n; ++i){
			int x = uniform_int_distribution<int>(1, 1e5)(rng);
			a.push_back(x);
		}
		sort(a.begin(), a.end());

		int c = uniform_int_distribution<int>(0,100)(rng)%2;

		for (int i = 0; i < n; ++i)
			if (i % 2 == c) a[i] *= -1;

		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());

		for (int x : a)
			in << x << ' ';
		in << '\n';

		//cetvrti test primer--------------------------------------

		n = 1e5;
		a = {};
		in << n << '\n';


		for (int x : {1e5-100, 1e5, 1e5-200, 1e5-5})
		for (int i = 0; i < n/4; ++i){
			if (i % 2) x *= -1;
			a.push_back(x);
		}

		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());

		c = uniform_int_distribution<int>(0,100)(rng)%2;

		if (c)
			a[10] *= -1;

		for (int x : a)
			in << x << ' ';
		in << '\n';

		//peti test primer ----------------------------------------------


		in << n << '\n';

		a = {};
		for (int i = 0; i < n; ++i){
			int x = uniform_int_distribution<int>(1, 1e5)(rng);
			a.push_back(x);
		}
		sort(a.begin(), a.end());

		for (int i = 0; i < n; ++i)
			if (i % 2) a[i] *= -1;

		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());
		random_shuffle(a.begin(), a.end());

		for (int x : a)
			in << x << ' ';
		in << '\n';

		in.close();
		out.close();
	}
}