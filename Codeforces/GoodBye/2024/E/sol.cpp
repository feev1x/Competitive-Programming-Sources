/**
 *    author:  feev1x
 *    created: 28.12.2024 22:40:17
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v; std::cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    i64 res = 0;
    std::vector<int> dep(n + 1), mndep(n + 1, n + n);
    std::map<int, int> cnt;
    auto Calc = [&](auto &&self, int v, int p) -> void {
      dep[v] = dep[p] + 1;
      for (auto to: g[v]) {
        if (to == p) {
          continue;
        }
        self(self, to, v);
        mndep[v] = std::min(mndep[v], mndep[to]);
      }
      if (g[v].size() == 1) {
        mndep[v] = dep[v];
      }
    };
    Calc(Calc, 1, 0);
    auto Dfs = [&](auto &&self, int v, int p, int mnd) -> void {
      mnd++;
      if (v != 1)
        g[v].erase(std::find(g[v].begin(), g[v].end(), p));
      if (v != 1 || g[v].size() == 1) {
        cnt[std::min(mndep[v] - dep[v], mnd)]++;
      } else {
        cnt[mndep[v] - dep[v]]++;
      }
      if (v == 1 && g[v].size() > 1) {
        mnd = 2e9;
      }
      std::vector<int> a, suf;
      for (auto to: g[v]) {
        a.emplace_back(mndep[to] - dep[v]);
        suf.emplace_back(mndep[to] - dep[v]);
      }
      for (int i = (int)suf.size() - 2; i >= 0; --i) {
        suf[i] = std::min(suf[i], suf[i + 1]);
      }
      int mn = mnd;
      for (int i = 0; i < a.size(); ++i) {
        self(self, g[v][i], v, std::min(mn, i + 1 < suf.size() ? suf[i + 1] : 20000000));
        mn = std::min(mn, a[i]);
      }
    };
    Dfs(Dfs, 1, 0, -1);
    i64 vll = 0;
    for (auto [key, val]: cnt) {
      if (key == 0) {
        vll = val;
      }
      res += (i64)val * (val - 1) / 2;
    }
    std::cout << (n * (n - 1) / 2) - res - vll * (n - vll) << '\n';
  }
  return 0;
}
