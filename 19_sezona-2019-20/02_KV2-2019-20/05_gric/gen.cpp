#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const char up[] = "bhaaueauerua";
const int mx = 100000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t, seed;
	cin >> t >> seed;

	mt19937 eng(seed);

	while (t--) {
		string fn;
		cin >> fn;
		ofstream fout(fn);
		int w, h, r, q;
		cin >> w >> h >> r >> q;
		// check
		if (w < 1 || h < 1 || r < 1 || q < 1)
			throw up;
		if (w > mx || h > mx || r > mx || q > mx)
			throw up;

		fout << w << ' ' << h << ' ' << r << ' ' << q << '\n';

		ld alpha, beta, spread, ask_prob;
		int after;
		cin >> alpha >> beta >> spread >> ask_prob >> after;

		bernoulli_distribution ask(ask_prob);
		normal_distribution<ld> nd(0, 1);
		uniform_int_distribution<int> uid(0, w);

		for (int i=0; i<q; i++) {
			bool ask_cond;
			if (after)
				ask_cond = i >= q * ask_prob;
			else
				ask_cond = ask(eng);

			if (ask_cond) {
				int x = uid(eng);
				fout << "2 " << x << '\n';
			} else {
				int x = uid(eng);
				int y = (alpha*(q-1-i)/(q-1) + beta*i/(q-1) + nd(eng)*spread)
					* r + h;
				y = clamp(y, h, h+r);
				fout << "1 " << x << ' ' << y << '\n';
			}
		}
	}
}