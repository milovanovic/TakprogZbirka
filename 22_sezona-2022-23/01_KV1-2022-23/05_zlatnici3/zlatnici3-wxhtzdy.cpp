#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int L = 19;
  vector<int> pv(n);
  vector<vector<int>> pr(L, vector<int>(n));
  vector<int> dfn(n);
  vector<int> dfo(n);
  vector<int> dep(n);
  int T = -1;
  function<void(int, int)> Dfs = [&](int v, int par) {
    pv[v] = par;
    dfn[v] = ++T;
    for (int u : g[v]) {
      if (u == par) {
        continue;
      }
      dep[u] = dep[v] + 1;
      Dfs(u, v);
    }
    dfo[v] = T;
  };
  Dfs(0, 0);
  auto IsAnc = [&](int x, int y) {
    return dfn[x] <= dfn[y] && dfo[y] <= dfo[x];
  };
  auto LCA = [&](int x, int y) {
    if (IsAnc(x, y)) {
      return x;
    }
    for (int i = L - 1; i >= 0; i--) {
      if (!IsAnc(pr[i][x], y)) {
        x = pr[i][x];
      }
    }
    return pv[x];
  };
  pr[0] = pv;
  for (int j = 1; j < L; j++) {
    for (int i = 0; i < n; i++) {
      pr[j][i] = pr[j - 1][pr[j - 1][i]];
    }
  }
  fenwick<long long> fenw(n);
  for (int i = 0; i < n; i++) {
    fenw.modify(dfn[i], +a[i]);
  }
  long long total = accumulate(a.begin(), a.end(), 0LL);
  auto GetSum = [&](int x) {
    return fenw.get(dfo[x]) - fenw.get(dfn[x] - 1);
  };
  auto GoUp = [&](int x, int k) {
    for (int i = L - 1; i >= 0; i--) {
      if (k >> i & 1) {
        x = pr[i][x];
      }
    }
    return x;
  };
  int idx = 0;
  for (int i = 1; i < n; i++) {
    //debug(i, GetSum(i));
    if (GetSum(i) < GetSum(idx) && GetSum(i) * 2 >= total) {
      idx = i;
    }
  }
  if (GetSum(idx) * 2 == total) {
    idx = min(idx, pv[idx]);
  }
  cout << idx + 1 << '\n';
  int q;
  cin >> q;
  while (q--) {
    int z, b;
    cin >> z >> b;
    --b;
    total += z;
    fenw.modify(dfn[b], +z);
    if (IsAnc(idx, b)) {
      idx = b;
      for (int i = L - 1; i >= 0; i--) {
        if (GetSum(pr[i][idx]) * 2 < total) {
          idx = pr[i][idx];
        }
      }
      if (GetSum(idx) * 2 < total) {
        idx = pv[idx];
      }
    } else if (IsAnc(b, idx)) {
      for (int i = L - 1; i >= 0; i--) {
        if (GetSum(pr[i][idx]) * 2 < total) {
          idx = pr[i][idx];
        }
      }
      if (GetSum(idx) * 2 < total) {
        idx = pv[idx];
      }
    } else {
      int x = LCA(idx, b);
      int y = GoUp(x, dep[idx] - dep[x] - 1);
      if (GetSum(y) * 2 < total) {
        idx = b;
      }
      for (int i = L - 1; i >= 0; i--) {
        if (GetSum(pr[i][idx]) * 2 < total) {
          idx = pr[i][idx];
        }
      }
      if (GetSum(idx) * 2 < total) {
        idx = pv[idx];
      }
    }
    if (GetSum(idx) * 2 == total) {
      idx = min(idx, pv[idx]);
    }
    cout << idx + 1 << '\n';
  }
  return 0;
}
