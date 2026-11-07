#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
  int n, m; std::cin >> n >> m;
  std::string s, t; std::cin >> s >> t;
  {
    int x = -n - m;
    std::vector<int> ps, ds;
    for (int i = 0; i < m; ++i) if (t[i] == 'W') x = i + 1, ps.emplace_back(i);
    ps.emplace_back(n + m + 5);
    for (int i = 0; i + 1 < ps.size(); ++i) ds.emplace_back(ps[i + 1] - ps[i]);
    std::sort(ds.begin(), ds.end());
    std::vector<int> p(ds.size() + 1);
    for (int i = 0; i < ds.size(); ++i) p[i + 1] = p[i] + ds[i];
    int ls = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') ls = i + 1;
      else {
        if (ls == -1) {
          int dx = std::upper_bound(ds.begin(), ds.end(), i) - ds.begin();
          std::cout << 1LL + p[dx] + ((int)ds.size() - dx) * (i + 1) << ' ';
        } else {
          int mn = ls, mx = std::max(ls + m, x + i);
          std::cout << mx - mn + 1 << ' ';
        }
      }
    }
    std::cout << '\n';
  }
  {
    std::swap(n, m);
    std::swap(s, t);
    int x = -n - m;
    std::vector<int> ps, ds;
    for (int i = 0; i < m; ++i) if (t[i] == 'W') x = i + 1, ps.emplace_back(i);
    ps.emplace_back(n + m + 5);
    for (int i = 0; i + 1 < ps.size(); ++i) ds.emplace_back(ps[i + 1] - ps[i]);
    std::sort(ds.begin(), ds.end());
    std::vector<int> p(ds.size() + 1);
    for (int i = 0; i < ds.size(); ++i) p[i + 1] = p[i] + ds[i];
    int ls = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') ls = i + 1;
      else {
        if (ls == -1) {
          int dx = std::upper_bound(ds.begin(), ds.end(), i) - ds.begin();
          std::cout << 1LL + p[dx] + ((int)ds.size() - dx) * (i + 1) << ' ';
        } else {
          int mn = ls, mx = std::max(ls + m, x + i);
          std::cout << mx - mn + 1 << ' ';
        }
      }
    }
    std::cout << '\n';
  }
}


signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
