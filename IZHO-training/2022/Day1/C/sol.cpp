/**
 *    author:  feev1x
 *    created: 28.12.2024 14:42:53
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, std::map<int, bool>> mp;
    for (auto &u: a) {
      std::cin >> u;
    }
    std::sort(a.begin(), a.end());
    if (k == 1) {
      int mn = 2e9;
      for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = 31; j >= 0; --j) {
          if (a[i] >> j & 1) {
            num ^= 1 << j;
          }
          if (!mp[num][j]) {
            num ^= 1 << j;
          }
        }
        if (i) {
          mn = std::min(mn, num ^ a[i]);
        }
        num = a[i];
        for (int i = 0; i < 32; ++i) {
          mp[num][i] = true;
          if (num >> i & 1) {
            num ^= 1 << i;
          }
        }
      }
      std::cout << mn << '\n';
      for (int i = 0; i < n; ++i) {
        std::cout << 1 << " \n"[i == n - 1];
      }
    } else {
      int res = -1;
      std::vector<int> c;
      for (int mask = 0; mask < (1 << n); ++mask) {
        int cnt = __builtin_popcount(mask);
        for (int mask1 = 0; mask1 < (1 << cnt); ++mask1) {
          for (int mask2 = 0; mask2 < (1 << (n - cnt)); ++mask2) {
            std::vector<int> nc(n);
            std::array<std::vector<int>, 5> ar;
            int c1 = 0, c0 = 0;
            for (int i = 0; i < n; ++i) {
              if (mask >> i & 1) {
                nc[i] = 1 + (mask1 >> c1 & 1);
                c1++;
              } else {
                nc[i] = 3 + (mask2 >> c0 & 1);
                c0++;
              }
              if (nc[i] > k) {
                nc[i] = 1;
              }
              ar[nc[i]].emplace_back(a[i]);
            }
            int ans = 2e9;
            for (auto u: ar) {
              if (u.size() < 2) {
                continue;
              }
              for (int i = 0; i < u.size(); ++i) {
                for (int j = i + 1; j < u.size(); ++j) {
                  ans = std::min(ans, u[i] ^ u[j]);
                }
              }
            }
            if (ans == 2e9) {
              ans = -1;
            }
            if (res < ans) {
              res = ans;
              c = nc;
            }
          }
        }
      }
      std::cout << res << '\n';
      for (auto u: c) {
        std::cout << u << ' ';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
