#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#define fi first
#define se second
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    vector<pair<int, int> > p;
    int TestCase = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int tX = atoi(argv[3]);
    int maxx = atoi(argv[4]);

    int n = rnd.next(maxn-maxn/20, maxn);
    cout << n << endl;


    int lst = -maxx-1;
    for(int i = 1; i <= n; i++) {
      int X = rnd.wnext(lst+1, maxx-(n-i), tX);
      if(X == 0) continue;
      p.push_back({X, X});
      lst = X;
    }

    shuffle(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
      cout << p[i].first << ' ' << p[i].second << endl;
    }
    return 0;
}
