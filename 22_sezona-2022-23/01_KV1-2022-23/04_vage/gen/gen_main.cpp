#include "testlib.h"
#include <iostream>
using namespace std;
#define MAXN 200010
int d[MAXN];
int u[MAXN];
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int maxw = atoi(argv[3]);
    int MAXX = atoi(argv[4]);

    int n = rnd.next(maxn-maxn/20, maxn);
    int m = rnd.next(maxn-maxn/20, maxn);
    cout << n << ' ' << m << endl;

    for(int i = 1; i <= n; i++) {
      int w = rnd.next(-maxw, maxw);
      d[i] = rnd.wnext(0, MAXX, w);
      u[i] = rnd.wnext(d[i], MAXX, w);

      cout << d[i] << ' ' << u[i] << endl;
    }

    for(int i = 1; i <= m; i++) {
      int l, r, x;
      x = rnd.next(0, MAXX);
      l = rnd.next(1, 2*(n/5));
      r = rnd.next(3*(n/5), n);

      cout << l << ' ' << r << ' ' << x << endl;
    }
}
