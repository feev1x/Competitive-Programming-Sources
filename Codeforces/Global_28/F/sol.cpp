/**
 *    author:  feev1x
 *    created: 19.12.2024 22:15:35
**/
#include <bits/stdc++.h>

using i64 = long long;

struct SpTable {
  std::vector<std::vector<i64>> sp;
  std::vector<i64> lg;
  bool min;
  int n;
  SpTable(std::vector<i64> a, bool _min) : n(a.size()), min(_min) {
    lg.resize(n);
    n--;
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<i64>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        if (min) {
          sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
        } else {
          sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
        }
      }
    }
  };
  inline i64 get(int l, int r) {
    int i = lg[r - l + 1];
    if (min) {
      return std::min(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
    return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<i64> a(n + 1), b(n + 1);
    std::vector<int> rng(n + 5);
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      std::cin >> b[i];
    }
    SpTable max(a, false), min(b, true);
    std::set<std::tuple<i64, int, int>> st;
    auto Cost = [&](int l, int r) {
      i64 cnt = 0;
      i64 mx = max.get(l, r), mn = min.get(l, r);
      while (mx > 1) {
        mx = mx / mn;
        cnt++;
      }
      return cnt;
    };
    auto Calc = [&](int l1, int r1, int l, int r) {
      i64 mx = 0;
      if (l1 <= r1 && 1 <= l1 && r1 <= n && l <= r && 1 <= l && r <= n) {
        mx = std::max(mx, Cost(l, r) + Cost(l1, r1) - Cost(std::min(l, l1), std::max(r, r1)));
      }
      return mx;
    };
    i64 res = 0;
    for (int i = 1; i <= n; ++i) {
      st.emplace(std::max(Calc(i, i, i + 1, i + 1), Calc(i, i, i - 1, i - 1)), i, i);
      rng[i] = i;
      res += Cost(i, i);
    }
    while (std::get<0>(*--st.end()) > 0) {
      auto [cost, l, r] = *--st.end();
      st.erase(--st.end());
      res -= cost;
      if (r < n && cost == Calc(l, r, r + 1, rng[r + 1])) {
        int l1 = rng[r + 1] + 1, r1 = rng[l1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        r1 = l - 1;
        l1 = rng[r1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        l1 = r + 1, r1 = rng[l1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        int temp = rng[r + 1];
        rng[l] = rng[r + 1];
        rng[rng[r + 1]] = l;
        r = temp;
        st.emplace(std::max(Calc(l, r, rng[l - 1], l - 1), Calc(l, r, r + 1, rng[r + 1])), l, r);
        l1 = r + 1, r1 = rng[l1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.emplace(std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1);
        r1 = l - 1;
        l1 = rng[r1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.emplace(std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1);
      } else {
        int l1 = r + 1, r1 = rng[l1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        r1 = rng[l - 1] - 1;
        l1 = rng[r1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        r1 = l - 1;
        l1 = rng[r1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.erase({std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1});
        int temp = rng[l - 1];
        rng[r] = rng[l - 1];
        rng[rng[l - 1]] = r;
        l = temp;
        st.emplace(std::max(Calc(l, r, rng[l - 1], l - 1), Calc(l, r, r + 1, rng[r + 1])), l, r);
        l1 = r + 1, r1 = rng[l1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.emplace(std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1);
        r1 = l - 1;
        l1 = rng[r1];
        if (1 <= l1 && r1 <= n && l1 <= r1) st.emplace(std::max(Calc(l1, r1, rng[l1 - 1], l1 - 1), Calc(l1, r1, r1 + 1, rng[r1 + 1])), l1, r1);
      }
    }
    std::cout << res << '\n';
  }
  return 0;
}
