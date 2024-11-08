/**
 *    author:  feev1x
 *    created: 07.11.2024 17:27:46
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

struct SpTable {
  vector<vector<int>> sp;
  vector<int> lg;
  int n;
  SpTable(vector<int> a) : n(a.size()) {
    lg.resize(n--);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1; 
    }
    sp.resize(lg[n] + 1, vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  inline int calc(int l, int r) {
    int sz = r - l + 1, i = lg[sz];
    return max(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

struct Square {
  int a, b, i;
};

bool comp(Square x, Square y) {
  return x.a < y.a;
}

signed main() {
  int n; scanf("%d", &n);
  vector<Square> ab(n + 1);
  vector<int> sm(n + 1), ans(n + 1), bb(n + 1), aa(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &ab[i].a, &ab[i].b);
    debug(ab[i].a, ab[i].b);
    ab[i].i = i;
  }
  sort(ab.begin() + 1, ab.end(), comp);
  for (int i = 1; i <= n; ++i) {
    aa[i] = ab[i].a;
    bb[i] = ab[i].b;
    sm[i] = ab[i].a + ab[i].b;
  }
  SpTable sp(sm);
  SpTable cc(bb);
  vector<int> suf(n + 1);
  suf[n] = ab[n].b;
  for (int i = n - 1; i >= 1; --i) {
    suf[i] = max(suf[i + 1], ab[i].b);
    debug(i, suf[i], ab[i].b);
  }
  auto Find = [&](int b, int i) {
    int l = 1, r = i - 1, ans = -1;
    while (l <= r) {
      int m = l + r >> 1;
      if (cc.calc(m, i - 1) >= b) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }
    return ans;
  };
  for (int i = 1; i <= n; ++i) {
    auto [a, b, ii] = ab[i];
    int res = (i == n ? 2e9 + 7 : max(0, b - suf[i + 1]));
    debug(b, suf);
    int j = Find(b, i);
    if (j != -1) {
      res = min(res, a - aa[j]);
    }
    debug(res);
    if (j == -1) {
      j = 1;
    } else {
      j++;
    }
    if (j < i) {
      res = min(res, (a + b) - sp.calc(j, i - 1));
    }
    debug(res, j, i, sm);
    ans[ii] = res;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}
