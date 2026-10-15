#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
  int n, m; std::cin >> n >> m;
  std::vector<int> a(n), ans(m + 1);
  std::map<int, int> mp;
  for (auto &u: a) std::cin >> u, mp[u]++;
  std::sort(a.begin(), a.end());
  for (int i = 1; i <= m; ++i) {
    int cnt = std::upper_bound(a.begin(), a.end(), i) - std::lower_bound(a.begin(), a.end(), i);
    ans[0] = std::max(ans[0], cnt);
    for (int j = 1; (1 << j - 1) * i < m; ++j) {
      cnt += (std::lower_bound(a.begin(), a.end(), ((1 << j - 1) + 1) * i) - std::upper_bound(a.begin(), a.end(), (1 << j - 1) * i)) * (1 << j - 1);
      for (int k = (1 << j - 1) + 1; k < (1 << j); ++k) {
        cnt += (std::lower_bound(a.begin(), a.end(), (k + 1) * i) - std::lower_bound(a.begin(), a.end(), k * i)) * k;
      }
      cnt += (std::upper_bound(a.begin(), a.end(), (1 << j) * i) - std::lower_bound(a.begin(), a.end(), (1 << j) * i)) * (1 << j);
      ans[j] = std::max(ans[j], cnt + (int)(a.end() - std::upper_bound(a.begin(), a.end(), (1 << j) * i)) * ((1 << j) - 1));
    }
  }
  for (int i = 1; i <= m; ++i) ans[i] = std::max(ans[i], ans[i - 1]), std::cout << ans[i] << " \n"[i == m];
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
