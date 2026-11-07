#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline bool chmax(int &a, int b) { return (a < b ? a = b, true : false); }
  
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::vector dp(n + 1, std::vector<int>(k + 1, -INF));
  std::vector opt(n + 1, std::vector<int>(k + 1));
  int L = 1, R = 0, ans = 0;
  auto Add = [&](int i) {
    if (!cnt[a[i]]++) ++ans;
  };
  auto Del = [&](int i) {
    if (!--cnt[a[i]]) --ans;
  };
  auto C = [&](int l, int r) {
    while (R < r) Add(++R);
    while (L > l) Add(--L);
    while (R > r) Del(R--);
    while (L < l) Del(L++);
    return ans;
  };
  dp[0][0] = 0;
  for (int j = 1; j <= k; ++j) {
    auto Cook = [&](auto &&self, int l, int r, int ql, int qr) -> void {
      if (l > r) return;
      qr = std::min(qr, r - 1);
      int m = l + r >> 1;
      for (int op = ql; op <= std::min(m - 1, qr); ++op)
        if (chmax(dp[m][j], dp[op][j - 1] + C(op + 1, m))) opt[m][j] = op;
      self(self, l, m - 1, ql, opt[m][j]);
      self(self, m + 1, r, opt[m][j], qr);
    }; Cook(Cook, 1, n, 0, n - 1);
  }
  std::cout << dp[n][k] << '\n';
  return 0;
}
