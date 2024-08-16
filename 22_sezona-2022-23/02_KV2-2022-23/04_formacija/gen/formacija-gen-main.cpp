#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#define fi first
#define se second
using namespace std;

long long crossProduct(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return (long long)(b.fi-a.fi)*(c.se-b.se) - (long long)(b.se-a.se)*(c.fi-b.fi);
}

bool collinear(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return crossProduct(a, b, c) == 0;
}
bool leftTurn(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return crossProduct(a, b, c) > 0;
}

int quadrant(pair<int, int> a) {
  if(a.fi > 0) {
    if(a.se >= 0) return 0;
    if(a.se <  0) return 3;
  } else if(a.fi < 0) {
    if(a.se >  0) return 1;
    if(a.se <= 0) return 2;
  } else {
    if(a.se >  0) return 1;
    if(a.se <  0) return 3;
  }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
  int kA = quadrant(a), kB = quadrant(b);
  if(kA != kB) return kA < kB;
  return leftTurn({0,0}, a, b);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    vector<int> xs, ys, xs1, xs2, ys1, ys2;
    vector<int> xdif, ydif;
    vector<pair<int, int> > p, v, pt;
    set<pair<int, int> > s;
    s.insert({0,0});
    int TestCase = atoi(argv[1]);
    int maxn = atoi(argv[2]);
    int maxcon = atoi(argv[3]);

    int tX = atoi(argv[4]);
    int tY = atoi(argv[5]);

    int maxx = atoi(argv[6]);

    int n = rnd.next(maxn-maxn/20, maxn);
    cout << n << endl;

    int con = rnd.next(maxcon-maxcon/20, maxcon);

    int lst = -maxx-1;
    for(int i = 1; i <= con; i++) {
      int X = rnd.wnext(lst+1, maxx-(con-i), tX);
      xs.push_back(X);
      lst = X;
    }
    lst = -maxx-1;
    for(int i = 1; i <= con; i++) {
      int Y = rnd.wnext(lst+1, maxx-(con-i), tY);
      ys.push_back(Y);
      lst = Y;
    }
    sort(xs.begin(), xs.end());
    xs1.push_back(xs[0]);
    xs2.push_back(xs[0]);
    for(int i = 1; i < (int)xs.size()-1; i++) {
      int pr = rnd.next(0, 1);
      if(pr == 0) xs1.push_back(xs[i]);
      if(pr == 1) xs2.push_back(xs[i]);
    }
    xs1.push_back(xs.back());
    xs2.push_back(xs.back());

    sort(ys.begin(), ys.end());
    ys1.push_back(ys[0]);
    ys2.push_back(ys[0]);
    for(int i = 1; i < (int)ys.size()-1; i++) {
      int pr = rnd.next(0, 1);
      if(pr == 0) ys1.push_back(ys[i]);
      if(pr == 1) ys2.push_back(ys[i]);
    }
    ys1.push_back(ys.back());
    ys2.push_back(ys.back());

    for(int i = 1; i < (int)xs1.size(); i++) {
      xdif.push_back(xs1[i]-xs1[i-1]);
    }
    for(int i = 0; i < (int)xs2.size()-1; i++) {
      xdif.push_back(xs2[i]-xs2[i+1]);
    }

    for(int i = 1; i < (int)ys1.size(); i++) {
      ydif.push_back(ys1[i]-ys1[i-1]);
    }
    for(int i = 0; i < (int)ys2.size()-1; i++) {
      ydif.push_back(ys2[i]-ys2[i+1]);
    }

    shuffle(ydif.begin(), ydif.end());
    for(int i = 0; i < (int)xdif.size(); i++) {
      v.push_back({xdif[i], ydif[i]});
    }
    sort(v.begin(), v.end(), cmp);
    ///cmp fali

    pair<int, int> pnt = {0, 0};
    int minx = maxx, miny = maxx;
    for(auto V : v) {
      pnt.fi += V.fi;
      pnt.se += V.se;
      pt.push_back(pnt);

      minx = min(minx, pnt.fi);
      miny = min(miny, pnt.se);
    }
    int dx = minx-xs[0], dy = miny-ys[0];
    for(int i = 0; i < (int)pt.size(); i++) {
      pair<int, int> tr = {pt[i].fi-dx, pt[i].se-dy};
      if(s.find(tr) == s.end()) {
        s.insert(tr);
        p.push_back(tr);
      }
    }

    while((int)p.size() < n) {
      int X = rnd.next(-maxx, maxx);
      int Y = rnd.next(-maxx, maxx);
      if(s.find({X, Y}) == s.end()) {
        s.insert({X, Y});
        p.push_back({X, Y});
      }
    }
    shuffle(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
      cout << p[i].first << ' ' << p[i].second << endl;
    }
    return 0;
}
