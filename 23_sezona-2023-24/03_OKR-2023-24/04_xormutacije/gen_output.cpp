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
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	ifstream in;
	ofstream out;
		

	vs str = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22"};

	for (auto st : str){
		in.open("../testcases/" + st + ".in");
		out.open("../testcases/" + st +".out");
			

		int t;
		in >> t;

		for (int e = 0; e < t; ++e){
			int n;
			in >> n;

			//cout << "E " << n << '\n';

			vi a(n+1);
			for (int i = 0; i <= n; ++i){
				in >> a[i];
			//	cout << a[i] << ' ';
			}

			vi res(n+1,0);
			int sol = 0;
			while(n){
				int k = log2(n);

				int m = 1<<k, suprotan = m-1;
				for (int i = m; i <= n; --suprotan, ++i){
					res[i] = suprotan;
					res[suprotan] = i;
					sol += (i^suprotan) * 2;
				}

				n=suprotan;
			}


			out << sol << '\n';
			
			/*for (int x : res)
				out << x << ' ';
			out << '\n';*/
		}
		in.close();
			out.close();
	}
}