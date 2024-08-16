#include "testlib.h"
#include <iostream>
using namespace std;
#define MAXX 1000000000
vector<int> v;
set<int> s;
vector<pair<int, int> > p;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int maxw = atoi(argv[3]);

    int n = rnd.next(maxn-maxn/20, maxn);
    int m = rnd.next(maxn-maxn/20, maxn);
    cout << n << ' ' << m << endl;

    for(int i = 1; i <= 2*n; i++) {
      while(1) {
        int w = rnd.next(-maxw, maxw);
        int x = rnd.wnext(0, MAXX, w);
        if(s.find(x) == s.end()) {
          s.insert(x);
          break;
        }
      }
    }
    for(auto x : s) v.push_back(x);

    for(int i = 0; i < 2*n; i+=2) {
      p.push_back({v[i], v[i+1]});
    }
    shuffle(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
      cout << p[i].first << ' ' << p[i].second << endl;
    }

    for(int i = 1; i <= m; i++) {
      int tmp = rnd.next(1, 100);
      int l, r, x;
      if(tmp <= 60) {
        x = rnd.next(0, MAXX);
      } else {
        int idx = rnd.next(0, n-1);

        x = rnd.next(p[idx].first, p[idx].second);
      }
      l = rnd.next(1, 2*(n/5));
      r = rnd.next(3*(n/5), n);

      cout << l << ' ' << r << ' ' << x << endl;
    }
}
