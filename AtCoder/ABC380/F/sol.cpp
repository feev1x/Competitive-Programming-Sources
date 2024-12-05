/**
 *    author:  feev1x
 *    created: 19.11.2024 15:05:28
**/
#include <bits/stdc++.h>

using i64 = long long;

int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
  return res;
}

int main() {
  int n, m, l; scanf("%d%d%d", &n, &m, &l);  
  std::vector<int> a(n), b(m), c(l);
  std::vector<int> ob;
  for (auto &u: a) {
    scanf("%d", &u);
    ob.emplace_back(u);
  }
  for (auto &u: b) {
    scanf("%d", &u);
    ob.emplace_back(u);
  }
  for (auto &u: c) {
    scanf("%d", &u);
    ob.emplace_back(u);
  }
  std::sort(ob.begin(), ob.end());
  std::map<int, int> mp;
  for (int i = 0; i < ob.size(); ++i) {
    mp[ob[i]] = i + 1;
  }
  for (auto &u: a) {
    u = mp[u];
  }
  for (auto &u: b) {
    u = mp[u];
  }
  for (auto &u: c) {
    u = mp[u];
  }
  std::vector<std::array<bool, 2>> dp(binpow(3, n + m + l), std::array<bool, 2>{});
  std::function<bool(int, bool)> Dfs = [&](int cards, bool tak) {
    std::vector<int> A, B, C;
    int ind = n + m + l;
    int val = cards;
    while (cards > 0) {
      if (cards % 3 == 0) {
        C.emplace_back(ind--);
      } else if (cards % 3 == 1) {
        A.emplace_back(ind--);
      } else {
        B.emplace_back(ind--);
      }
      cards /= 3;
    }
    while (ind > 0) {
      C.emplace_back(ind--);
    }
    std::sort(C.begin(), C.end());
    if (tak) {
      for (auto u: A) {
        for (auto v: C) {
          if (v > u) break;
          if (Dfs(val - binpow(3, u - 1) + binpow(3, v - 1), false)) {
            return dp[val][tak] = true;
          }
        }
      }
      return dp[val][tak] = false;
    } else {
      for (auto u: B) {
        for (auto v: C) {
          if (v > u) break;
          if (!Dfs(val - binpow(3, u - 1) * 2 + binpow(3, v - 1) * 2, true)) {
            return dp[val][tak] = false;
          }
        }
      }
      return dp[val][tak] = true;
    }
  };
  int cards = 0;
  for (auto u: a) {
    printf("%d ", u);
    cards += binpow(3, u - 1);
  }
  printf("\n");
  for (auto u: b) {
    printf("%d ", u);
    cards += binpow(3, u - 1) * 2;
  }
  printf("\n");
  if (Dfs(cards, true)) {
    printf("Takahashi\n");
  } else {
    printf("Aoki\n");
  }
  return 0;
}
