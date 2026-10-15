#include <bits/stdc++.h>

struct SpTable {
  std::vector<std::vector<int64_t>> sp;
  std::vector<int> lg;
  int n;
  SpTable(std::vector<int64_t> a) : n(a.size()) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
    sp.resize(lg[n] + 1, std::vector<int64_t>(n));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
  }
  inline int64_t get(int l, int r) {
    int i = lg[r - l + 1];
    return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> x(n), a(n - 1);
  std::vector<int64_t> p(n), val(n - 1), val2(n - 1);
  for (auto &u: x) std::cin >> u;
  for (int i = 0; i + 1 < n; ++i) a[i] = x[i + 1] - x[i], p[i + 1] = p[i] + a[i], val[i] = a[i] - p[i], val2[i] = a[i] + p[i + 1]; 
  SpTable sp(val), sp2(val2);
  int q; std::cin >> q;
  std::map<int, int64_t> mp;
  mp[0] = mp[n - 1] = p[n - 1];
  auto Dfs = [&](auto &&self, int i) -> int64_t {
    if (mp.count(i)) return mp[i];
    if (a[i - 1] <= a[i]) {
      int l = 0, r = i - 2, ans = -1;
      while (l <= r) {
        int m = l + r >> 1;
        if (sp2.get(m, i - 2) > p[i + 1]) l = m + 1, ans = m;
        else r = m - 1;
      }
      return mp[i] = self(self, ans + 1) + p[i] - p[ans + 1];
    }
    int l = i + 1, r = n - 2, ans = n - 1;
    while (l <= r) {
      int m = l + r >> 1;
      if (sp.get(i + 1, m) >= -p[i - 1]) r = m - 1, ans = m;
      else l = m + 1;
    }
    return mp[i] = self(self, ans) + p[ans] - p[i];
  };
  while (q--) {
    int y; std::cin >> y;
    int i = std::upper_bound(x.begin(), x.end(), y) - x.begin();
    if (i >= x.size() || i > 0 && std::abs(x[i] - y) >= std::abs(x[i - 1] - y)) std::cout << Dfs(Dfs, i - 1) + std::abs(x[i - 1] - y) << '\n';
    else std::cout << Dfs(Dfs, i) + std::abs(x[i] - y) << '\n';
  }
  return 0;
}
