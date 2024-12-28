/**
 *    author:  feev1x
 *    created: 28.12.2024 10:14:49
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    bool flag = false;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
      mx = std::max(mx, a[i]);
      if (a[i] != i) {
        flag = true;
      }
    }
    if (!flag) {
      i64 res = n;
      int st = 1;
      for (int i = 2; i < n; ++i) {
        if (i - st <= n - i) {
          res -= i - st;
          i += i - st - 1;
        } else {
          st = i;
        }
      }
      std::cout << res << '\n';
    } else if (mx <= 3) {
      std::set<int> st;
      std::set<std::pair<int, int>> s;
      for (int i = 2; i < n; ++i) {
        if (a[i] == (a[i - 1] + a[i + 1]) / 2.0) {
          st.emplace(i);
        }
      }
      for (int i = 1; i <= n; ++i) {
        s.emplace(i, a[i]);
      }
      while (st.size()) {
        int i = *st.begin();
        st.erase(st.begin());
        auto it = s.upper_bound({i, -1});
        auto it1 = it;
        assert(it->first == i);
        --it;
        ++it1;
        if (it != s.begin()) {
          int j = it->first;
          --it;
          if (a[j] == (a[it1->first] + a[it->first]) / 2.0) {
            st.emplace(j);
          }
          ++it;
        }
        if (++it1 != s.end()) {
          --it1;
          int j = it1->first;
          ++it1;
          if (a[j] == (a[it1->first] + a[it->first]) / 2.0) {
            st.emplace(j);
          }
        }
        s.erase({i, a[i]});
      }
      assert(s.size() >= 2);
      std::cout << s.size() << '\n';
    } else {
      std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
      for (int sz = 3; sz <= n; ++sz) {
        for (int l = 1; l + sz - 1 <= n; ++l) {
          int r = l + sz - 1;
          for (int k = r - 1; k > l; --k) {
            int sm = dp[l][k] + dp[k][r];
            if (sm == r - l - 2) {
              if (a[k] == (a[l] + a[r]) / 2.0) {
                dp[l][r] = r - l - 1;
              } else {
                dp[l][r] = std::max(dp[l][r], sm);
              }
            } else {
              dp[l][r] = std::max(dp[l][r], sm);
            }
          }
        }
      }
      std::cout << n - dp[1][n] << '\n';
    }
  }
  return 0;
}
