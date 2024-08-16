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

const int maxn = 1e5;

signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	ofstream out;

	vs st = {"10","09","08","07","06","05"};

	for (string stt : st){

		out.open("../testcases/" + stt + ".in");

		int t = 5;
		out << t << '\n';

		for (int e = 0; e < t; ++e){
			int k = log2(maxn) - rand()%5;
			int n = 1<<k; --n;
			out << n << '\n';

			mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		    vector<int> permutation(n+1);

		    for (int i = 0; i < n+1; i++)
		        permutation[i] = i;

		    for (int i = 1; i < n+1; i++)
		        swap(permutation[i], permutation[uniform_int_distribution<int>(0, i)(rng)]);

		    for (int x : permutation)
		    	out << x << ' ';
		    out << '\n';

		}

		out.close();
	}
}