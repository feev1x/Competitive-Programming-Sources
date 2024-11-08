/**
 *    author:  feev1x
 *    created: 07.11.2024 13:52:46
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

class SpTable {
  vector<vector<int>> sp;
  vector<int> lg;
  int n;
 public:
  SpTable(vector<int> a) {
    n = a.size();
    n--;
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
      }
    }
    debug(sp, a);
  }
  inline int calc(int l, int r) {
    int sz = r - l + 1;
    return max(sp[lg[sz]][l], sp[lg[sz]][r - (1 << lg[sz]) + 1]);
  }
};

const int add = 1e6 + 1;

signed main() {
  int n; scanf("%d", &n);
  vector<int> t(n + 1);
  vector<vector<int>> ps(5000001);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
  }
  int m; scanf("%d", &m);
  vector<int> s(m + 1);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &s[i]);
  }
  for (int i = 1; i <= m; ++i) {
    ps[s[i] + add].emplace_back(i);
  }
  SpTable sp(s);
  for (int i = 1; i + n - 1 <= m; ++i) {
    vector<int> res;
    res.emplace_back(i);
    int x = s[i] - t[1];
    int pos = 2, ls = i;
    while (res.size() < n) {
      if (ps.size() <= t[pos] + x + add) {
        res.clear();
        break;
      }
      auto it = upper_bound(ps[t[pos] + x + add].begin(), ps[t[pos] + x + add].end(), ls);
      if (it == ps[t[pos] + x + add].end()) {
        res.clear();
        break;
      }
      int nx = *it;
      if (ls + 1 != nx) {
        if (sp.calc(ls + 1, nx - 1) > x) {
          res.clear();
          break;
        }
      }
      res.emplace_back(nx);
      ls = nx;
      pos++;
    }
    if (res.size() == n) {
      printf("YES\n");
      for (auto u: res) {
        printf("%d ", u);
      }
      printf("\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}

