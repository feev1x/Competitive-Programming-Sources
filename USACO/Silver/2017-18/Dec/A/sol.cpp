/**
 *    author:  feev1x
 *    created: 05.12.2024 15:59:19
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9, EPS = 1e-15;

int main() {
  std::freopen("homework.in", "r", stdin);
  std::freopen("homework.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> a(n + 1), suf_sum(n + 2), suf_mn(n + 2, INF);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i > 0; --i) {
    suf_sum[i] = suf_sum[i + 1] + a[i];
    suf_mn[i] = std::min(suf_mn[i + 1], a[i]);
  }
  long double mx = 0;
  for (int i = 2; i < n; ++i) {
    mx = std::max(mx, (suf_sum[i] - suf_mn[i]) * (long double)(n - i));
  }
  for (int k = 1; k <= n - 2; ++k) {
    if ((suf_sum[k + 1] - suf_mn[k + 1]) / (long double)(n - k - 1) - mx <= EPS) {
      printf("%d\n", k);
    }
  }
  return 0;
}
