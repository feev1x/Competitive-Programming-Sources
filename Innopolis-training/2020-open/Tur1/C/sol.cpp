/**
 *    author:  feev1x
 *    created: 22.11.2024 09:37:38
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXK = 3e4 + 5;

using bs = std::bitset<MXK>;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> x(2 * n);
  for (auto &u: x) {
    scanf("%d", &u);
  }
  int cnt = 0;
  std::vector<int> kn;
  std::vector<std::pair<int, int>> seg;
  for (int i = 1; i < 2 * n; i += 2) {
    cnt += x[i] - x[i - 1];
    if (i + 1 < 2 * n) {
      kn.emplace_back(x[i + 1] - x[i]);
      seg.emplace_back(i - 1, i + 2);
    }
  }
  if (cnt > k) {
    printf("No\n");
    exit(0);
  }
  std::vector<bs> dp(kn.size() + 1);
  dp[0][0] = true;
  for (int i = 0; i < kn.size(); ++i) {
    dp[i + 1] = dp[i];
    dp[i + 1] |= dp[i] << kn[i];
  }
  if (dp[kn.size()][k - cnt]) {
    printf("Yes\n");
    std::vector<std::pair<int, int>> res;
    auto Add = [&](int &l, int &r) {
      if ((r - l + 1) & 1) {
        return;
      }
      if (l <= 0 || l > 2 * n || r <= 0 || r > 2 * n) {
        return;
      }
      int o_l = l - 1;
      while (l < r) {
        res.emplace_back(l++, r--);
      }
      r = o_l;
      l = o_l - 1;
    };
    int L = 2 * n - 1, R = 2 * n;
    for (int i = kn.size() - 1, j = k - cnt, l = 2 * n - 1, r = 2 * n; i >= 0; --i) {
      if (!dp[i][j]) {
        l = seg[i].first + 1;
        j -= kn[i];
      } else {
        Add(l, r);
      }
      L = l, R = r;
    }
    Add(L, R);
    for (auto [l, r]: res) {
      printf("%d %d\n", l, r);
    }
  } else {
    printf("No\n");
  }
  return 0;
}
