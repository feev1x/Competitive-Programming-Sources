#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; ++i) {
    int a, b; std::cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  if (m == n - 1) {
    std::vector<bool> col(n + 1);
    std::vector<int> bal(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
      bal[v] = (col[v] ? 1 : -1);
      for (auto to: g[v]) if (to != p) {
        col[to] = !col[v]; 
        self(self, to, v);
        bal[v] += bal[to];
      }
    }; Dfs(Dfs, 1, 1);
    if (bal[1]) {
      std::cout << "-1\n";
      return 0;
    }
    int64_t res = 0;
    for (int i = 1; i <= n; ++i) res += std::abs(bal[i]);
    std::cout << res << '\n';
  } else {
    std::vector<int> cyc, par(n + 1);
    std::vector<bool> used(n + 1), iscyc(n + 1);
    auto Cyc = [&](auto &&self, int v, int p) -> void {
      used[v] = true;
      for (auto to: g[v]) if (to != p) {
        par[to] = v;
        if (used[to]) {
          int u = v;
          while (u != to) {
            iscyc[u] = true;
            cyc.emplace_back(u);
            u = par[u];
          }
          iscyc[to] = true;
          cyc.emplace_back(to);
          return;
        }
        self(self, to, v);
        if (cyc.size()) return;
      }
    }; Cyc(Cyc, 1, 1);
    assert(cyc.size());
    int64_t sum = 0;
    std::vector<bool> col(n + 1);
    std::vector<int> bal(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
      bal[v] = (col[v] ? 1 : -1);
      for (auto to: g[v]) if (!iscyc[to] && to != p) {
        col[to] = !col[v]; 
        self(self, to, v);
        bal[v] += bal[to];
      }
      sum += std::abs(bal[v]);
    };
    std::vector<int> a;
    int64_t res = 0;
    for (int i = 0; i < (int)cyc.size(); ++i) {
      col[cyc[i]] = (i & 1);
      sum = 0;
      Dfs(Dfs, cyc[i], cyc[i]);
      sum -= std::abs(bal[cyc[i]]);
      res += sum;
      a.emplace_back(bal[cyc[i]]);
    }
    if ((int)(a.size()) & 1) {
      int64_t sum_a = 0;
      std::vector<int64_t> x(a.size());
      for (int i = 0; i < (int)a.size(); ++i) {
        sum_a += a[i];
      }
      sum_a -= 2 * a[0];
      if (sum_a & 1) {
        std::cout << "-1\n";
        return 0;
      }
      x[0] = sum_a / 2;
      res += std::abs(x[0]);
      for (int i = 1; i < (int)a.size(); ++i) x[i] = x[i - 1] - a[i], res += std::abs(x[i]);
      std::cout << res << '\n';
    } else {
      if (std::accumulate(a.begin(), a.end(), 0LL) == 0) {
        std::vector<int> x(a.size()), vls;
        for (int i = 1; i < (int)a.size(); ++i) {
          x[i] = x[i - 1] - a[i];
          vls.emplace_back(-x[i]);
        }
        int cn = 0, cp = 0;
        for (auto u: vls) {
          if (u > 0) cp++;
          if (u < 0) cn++;
        }
        if (cp > cn) {
          std::vector<int> new_vls;
          for (auto u: vls) if (u > 0) new_vls.emplace_back(u);
          std::swap(new_vls, vls);
          std::sort(vls.begin(), vls.end());
          for (int i = 0; i < (int)vls.size(); ++i) {
            if ((int)vls.size() - i < (int)x.size() - (int)vls.size() + i) break;
            x[0] = vls[i];
          }
        } else {
          std::vector<int> new_vls;
          for (auto u: vls) if (u < 0) new_vls.emplace_back(u);
          std::swap(new_vls, vls);
          std::sort(vls.begin(), vls.end(), std::greater<>());
          for (int i = 0; i < (int)vls.size(); ++i) {
            if ((int)vls.size() - i < (int)x.size() - (int)vls.size() + i) break;
            x[0] = vls[i];
          }
        }
        res += std::abs(x[0]);
        for (int i = 1; i < (int)a.size(); ++i) x[i] = x[i - 1] - a[i], res += std::abs(x[i]);
        std::cout << res << '\n';
      } else {
        std::cout << "-1\n";
        return 0;
      }
    }
  }
  return 0;
}
