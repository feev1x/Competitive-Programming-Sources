/**
 *    author:  feev1x
 *    created: 08.01.2025 11:02:02
**/
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

#define int i64

constexpr int MOD = 1e9 + 7;


inline int mul(int a, int b) {
  return (i128)a * b % MOD;
}

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub_self(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int u; std::cin >> u;
  auto F = [&](int n) {
    return (i128)n * (n + 1) / 2 % MOD;
  };
  if (u > 5000) {
    std::set<std::pair<i64, i64>> st;
    std::map<i64, i64> mp;
    int res = 0;
    while (u--) {
      int d, b; std::cin >> d >> b;
      if (b && st.empty()) {
        add_self(res, (F(b) + mul(d - 1, b)) % MOD);
        st.emplace(d, d + b - 1);
      } else if (st.size()) {
        auto it = st.upper_bound({d + 1, -1});
        int l, r;
        if (it == st.begin() || (--it)->second < d) {
          l = d, r = d - 1;
        } else {
          std::tie(l, r) = *it;
          b -= mp[d];
        }
        mp[d] += b;
        i64 sz = r - l + 1;
        sub_self(res, (F(sz) + mul(l - 1, sz)) % MOD);
        st.erase({l, r});
        it = st.upper_bound({l, r});
        while (st.size() && it != st.end() && it->first <= r + b) {
          sz = it->second - it->first + 1;
          b += sz;
          sub_self(res, (F(sz) + mul(it->first - 1, sz)) % MOD);
          st.erase(it);
          it = st.upper_bound({l, r});
        }
        st.emplace(l, r + b);
        sz = (r + b) - l + 1;
        add_self(res, (F(sz) + mul(l - 1, sz)) % MOD);
      }
      std::cout << res % MOD << '\n';
    }
  } else {
    std::map<int, int> mp;
    while (u--) {
      int d, b; std::cin >> d >> b;
      mp[d] = b;
      int res = 0, l = -1, r = -1;
      for (auto [key, val]: mp) {
        if (r < key) {
          if (r != -1) {
            add_self(res, (F(r - l + 1) + mul(l - 1, r - l + 1)) % MOD);
          }
          l = key, r = key + val - 1;
        } else {
          r += val;
        }
      }
      if (r != -1) {
        add_self(res, (F(r - l + 1) + mul(l - 1, r - l + 1)) % MOD);
      }
      std::cout << res << '\n';
    }
  }
  return 0;
}

