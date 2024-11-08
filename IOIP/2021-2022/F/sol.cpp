/**
 *    author:  feev1x
 *    created: 07.11.2024 12:02:39
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

const int mod = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

signed main() {
  int n, B; scanf("%d%d", &n, &B);
  vector<int> a(n * 2);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  vector<map<pair<int, int>, int>> dp(n);
  if (B - a[0] - a[1] >= 0) {
    dp[0][{B - a[0] - a[1], B}] += 1;
    dp[0][{B, B - a[0] - a[1]}] += 1;
  }
  if (B - a[0] >= 0 && B - a[0] >= 0) {
    dp[0][{B - a[1], B - a[0]}] += 1;
    dp[0][{B - a[0], B - a[1]}] += 1;
  }
  for (int i = 1; i < n; ++i) {
    int u = 2 * i, v = 2 * i + 1;
    for (auto [ey, val]: dp[i - 1]) {
      if (!val) continue;
      auto [k1, k2] = ey;
      if (k1 - a[u] - a[v] >= 0) {
        add_self(dp[i][{B, B}], val);
      }
      if (k2 - a[u] - a[v] >= 0) {
        add_self(dp[i][{B, B}], val);
      }
      if (k1 - a[v] >= 0 && k2 - a[u] >= 0) {
        add_self(dp[i][{B, B}], val);
      }
      if (k1 - a[u] >= 0 && k2 - a[v] >= 0) {
        add_self(dp[i][{B, B}], val);
      }
      if (k1 - a[u] >= 0) {
        if (B - a[v] >= 0) {
          add_self(dp[i][{B - a[v], B}], val);
          add_self(dp[i][{B, B - a[v]}], val);
        }
      }
      if (k1 - a[v] >= 0) {
        if (B - a[u] >= 0) {
          add_self(dp[i][{B - a[u], B}], val);
          add_self(dp[i][{B, B - a[u]}], val);
        }
      }
      if (k2 - a[u] >= 0) {
        if (B - a[v] >= 0) {
          add_self(dp[i][{B - a[v], B}], val);
          add_self(dp[i][{B, B - a[v]}], val);
        }
      }
      if (k2 - a[v] >= 0) {
        if (B - a[u] >= 0) {
          add_self(dp[i][{B - a[u], B}], val);
          add_self(dp[i][{B, B - a[u]}], val);
        }
      }
      if (B - a[u] >= 0 && B - a[v] >= 0) {
        add_self(dp[i][{B - a[u], B - a[v]}], val);
        add_self(dp[i][{B - a[v], B - a[u]}], val);
      }
      if (B - a[u] - a[v] >= 0) {
        add_self(dp[i][{B - a[u] - a[v], B}], val);
        add_self(dp[i][{B, B - a[u] - a[v]}], val);
      }
    }
  }
  int sum = 0;
  for (auto [key, val]: dp[n - 1]) {
    add_self(sum, val);
  }
  printf("%d\n", sum);
  return 0;
}
