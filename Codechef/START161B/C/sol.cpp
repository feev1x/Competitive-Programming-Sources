/**
 *    author:  feev1x
 *    created: 20.11.2024 20:44:01
**/
#include <bits/stdc++.h>

using i64 = long long;

struct SpTable {
  std::vector<std::vector<int>> sp;
  std::vector<int> lg;
  std::function<int(int, int)> fun;
  int n;
  bool mn;
  SpTable(std::vector<int> a, bool _mn) : n(a.size() - 1), mn(_mn) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    fun = [&](int a, int b) {
      if (a > b) {
        return mn ? b : a;
      }
      return mn ? a : b;
    };
    sp.resize(lg[n] + 1, std::vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = fun(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  };
  inline int calc(int l, int r) {
    int sz = r - l + 1;
    return fun(sp[lg[sz]][l], sp[lg[sz]][r - (1 << lg[sz]) + 1]);
  }
};

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    std::vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    a.emplace(a.begin(), 0);
    SpTable mn(a, true), mx(a, false);
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
      int m = l + r >> 1;
      int cnt = 0;
      int i = 1;
      while (i <= n) {
        int l1 = i, r1 = n, ans1 = -1;
        while (l1 <= r1) {
          int m1 = l1 + r1 >> 1;
          int mn_r = mn.calc(i, m1);
          int mx_r = mx.calc(i, m1);
          int mid = mx_r + mn_r >> 1;
          if (mx_r - mid > m) {
            r1 = m1 - 1;
          } else {
            l1 = m1 + 1;
            ans1 = m1;
          }
        }
        assert(ans1 != -1);
        cnt++;
        i = ans1 + 1;
      }
      cnt--;
      if (cnt > k) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
