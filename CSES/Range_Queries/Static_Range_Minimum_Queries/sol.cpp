/**
 *    author:  feev1x
 *    created: 04.11.2024 22:45:51
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
  SpTable(vector<int> a) : n(a.size()) {
    n--;
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  inline int calc(int l, int r) {
    int sz = r - l + 1;
    return min(sp[lg[sz]][l], sp[lg[sz]][r - (1 << lg[sz]) + 1]);
  }
};

signed main() {
  int n, q; scanf("%d%d", &n, &q);
  vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  a.emplace(a.begin(), 0);
  SpTable sp(a);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    printf("%d\n", sp.calc(l, r));
  }
  return 0;
}
