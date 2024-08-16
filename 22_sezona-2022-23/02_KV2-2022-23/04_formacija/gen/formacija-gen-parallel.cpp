#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
vector<pair<int, int> > p;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}
set<pair<int, int> > s;
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int TestCase = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int maxup = atoi(argv[3]);

    int tUp = atoi(argv[4]);
    int tDown = atoi(argv[5]);

    int sorted = atoi(argv[6]);
    int maxx = atoi(argv[7]);

    int coll = atoi(argv[8]);

    int n = rnd.next(maxn-maxn/20, maxn);
    cout << n << endl;

    int up = rnd.next(maxup-maxup/20, maxup);
    int down = n - up;

    int lst = -maxx-1;
    for(int i = 1; i <= up; i++) {
      int x = rnd.wnext(lst+1, maxx-(up-i), tUp);
      p.push_back({x, 1});
      lst = x;
    }
    lst = -maxx-1;
    for(int i = 1; i <= down; i++) {
      int x = rnd.wnext(lst+1, maxx-(down-i), tDown);
      p.push_back({x, -1});
      s.insert({x, -1});
      lst = x;
    }
    if(coll) {
      int idx = rnd.next(0, up-1);
      pair<int, int> grnj = p[idx];
      if(s.find({-grnj.first, -1}) == s.end()) {
        p.pop_back();
        p.push_back({-grnj.first, -1});
      }
    }
    if(sorted) {
      sort(p.begin(), p.end(), cmp);
      shuffle(p.begin()+1, p.end());
    } else {
      shuffle(p.begin(), p.end());
    }
    for(auto x : p) {
      cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}
