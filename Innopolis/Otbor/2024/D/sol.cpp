/**
 *    author:  feev1x
 *    created: 24.11.2024 16:37:58
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  double al; scanf("%lf", &al);
  std::vector<i64> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &l[i], &r[i]);
  }
  int res = 0;
  int bit = 0, st = 1;
  std::vector<int> sl(1 << n), sr(1 << n), mn(1 << n);
  sl[1] = l[0], sr[1] = r[0], mn[1] = r[0];
  mn[0] = 2e9;
  int mx = (1 << n) - 1;
  for (int mask = 1; mask < 1 << n; ++mask) {
    if (mask >= st * 2) {
      bit++;
      st <<= 1;
      mn[st] = r[bit];
    }
    mn[mask] = std::min(mn[st], mn[mask ^ st]);
  }
  bit = 0, st = 1;
  for (int mask = 1; mask < 1 << n; ++mask) {
    if (mask >= st * 2) {
      bit++;
      st <<= 1;
      sl[st] = l[bit], sr[st] = r[bit];
    }
    int suml = sl[st] + sl[mask ^ st], sumr = sr[st] + sr[mask ^ st];
    int mnn = mn[~mask & mx];
    if (suml > m) {
      suml = m + 1;
    }
    if (sumr > m) {
      sumr = m + 1;
    }
    sl[mask] = suml, sr[mask] = sumr;
    if (sumr <= m && m - suml < mnn) {
      res++;
    }
  }
  printf("%d\n", res);
  return 0;
}
