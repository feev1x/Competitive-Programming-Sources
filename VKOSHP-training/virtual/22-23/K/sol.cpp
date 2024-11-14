/**
 *    author:  feev1x
 *    created: 22.10.2024 20:22:28
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

using lv = vector<int64_t>;
using llv = vector<lv>;
using lllv = vector<llv>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto Modp = [&](int64_t a, int64_t b) {
    return (a + b) % mod;
  };
  auto Modm = [&](int64_t a, int64_t b) {
    return (a * b) % mod;
  };
  int n, m; cin >> n >> m;
  llv dp(n + 1, lv(m + 1)), cnt(n + 1, lv(m + 1));
  for (int h = 1; h <= n; ++h) {
    for (int w = 1; w <= m; ++w) {
      cnt[h][w] = 1;
      dp[h][w] = h * w;
      for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
          cnt[h][w] = Modp(cnt[h][w], Modm((h - i - 1), Modm((w - j - 1), cnt[i][j])));
          dp[h][w] = Modp(dp[h][w], Modm(Modm(h - i - 1, w - j - 1), Modp(dp[i][j], Modm(h, Modm(w, cnt[i][j])))));
        }
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}
