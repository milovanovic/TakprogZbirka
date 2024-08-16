#include "testlib.h"
#include <iostream>
#define MAXX 1000000000
using namespace std;

vector<int> v;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int p = atoi(argv[3]);

    int n = rnd.next(maxn-10000, maxn);
    int m = rnd.next(maxn-10000, maxn);
    cout << n << ' ' << m << endl;

    for(int i = 0; i < p; i++) v.push_back(rnd.next(0, MAXX));

    for(int i = 1; i <= n; i++) {
      int x = v[rnd.next(0, p-1)];
      cout << x << ' ' << x << endl;
    }

    for(int i = 1; i <= m; i++) {
      int tmp = rnd.next(1, 100);
      int l, r, x;
      if(tmp == 1) x = rnd.next(0, MAXX);
      else x = v[rnd.next(0, (int)v.size()-1)];

      l = rnd.next(1, 2*(n/5));
      r = rnd.next(3*(n/5), n);

      cout << l << ' ' << r << ' ' << x << endl;
    }
}
