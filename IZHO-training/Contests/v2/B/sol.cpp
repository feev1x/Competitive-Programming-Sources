/**
 *    author:  feev1x
 *    created: 06.01.2025 10:11:02
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

inline void pr(int x) {
  for (int i = 9; i >= 0; --i) {
    std::cout << (x >> i & 1);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt, n; std::cin >> tt >> n;
  auto ShiftR = [&](int x) {
    x <<= 1;
    if (x & (1 << n)) {
      x ^= (1 << n) ^ 1;
    }
    return x;
  };
  auto Bin = [&](std::string s) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        res |= (1 << i);
      }
    }
    return res;
  };
  std::vector<int> val(1 << n, -1);
  for (int i = 0; i < 1 << n; ++i) {
    if (val[i] == -1) {
      int j = i;
      while (val[j] == -1) {
        val[j] = i;
        j = ShiftR(j);
      }
    }
  }
  std::vector<std::vector<bool>> dp(3 * n + 1, std::vector<bool>(1 << n));
  dp[0][val[0]] = true;
  int change = 0;
  for (int i = 1; i <= 3 * n; ++i) {
    change ^= 1 << (i - 1) % n;
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (dp[i - 1][val[mask]]) {
        dp[i][val[change ^ mask]] = true;
      }
    }
  }
  while (tt--) {
    std::string l, s; std::cin >> l >> s;
    int sw = Bin(s), lig = Bin(l);
    int cur = 0;
    for (int i = 0; i <= 3 * n; ++i) {
      if (dp[i][val[cur ^ lig]]) {
        std::cout << i << '\n';
        break;
      }
      cur ^= sw;
      sw = ShiftR(sw);
    }
  }
  return 0;
}
