/**
 *    author:  feev1x
 *    created: 28.10.2024 21:37:35
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n + 1), p(n + 1), suf(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }
  for (int i = n, j = 1; i >= 1; --i, ++j) {
    suf[i] = a[i] * j + suf[i + 1];
  }
  vector<int> dom(n + 2);
  for (int i = 1; i <= n; ++i) {
    dom[i] = dom[i - 1] + suf[i];
  }
  int q; cin >> q;
  while (q--) {
    auto Fr = [&](int num) {
      int64_t l = 1, r = n, ans = 0;
      while (l <= r) {
        int64_t m = l + r >> 1;
        int64_t sm = (n * (n + 1) / 2) - ((n - m) * (n - m + 1) / 2);
        if (sm >= num) {
          r = m - 1;
          ans = m;
        } else {
          l = m + 1;
        }
        debug(l, r, m, ans);
      }
      return ans;
    };
    auto Sc = [&](int fr, int num) {
      int64_t l = fr, r = n, ans = 0; 
      while (l <= r) {
        int64_t m = l + r >> 1;
        int64_t sm = n * (n + 1) / 2 - (n - fr + 2) * (n - fr + 1) / 2;
        sm += m - fr + 1;
        if (sm >= num) {
          r = m - 1;
          ans = m;
        } else {
          l = m + 1;
        }
      }
      return ans;
    };
    function<int64_t(int)> Sum = [&](int num) {
      if (num == 0) return int64_t(0ll);
      int64_t res = 0;
      int64_t ans = Fr(num);
      res += dom[ans - 1];
      int64_t ans1 = Sc(ans, num);
      res += suf[ans] - suf[ans1 + 1] - (p[ans1] - p[ans - 1]) * (n - ans1);
      debug(res, num, ans, ans1);
      debug(p, suf, dom);
      return res;
    };
    int l, r; cin >> l >> r;
    cout << Sum(r) - Sum(l - 1) << '\n';
  }
  return 0;
}
