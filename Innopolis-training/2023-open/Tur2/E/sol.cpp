/**
 *    author:  feev1x
 *    created: 19.11.2024 13:22:14
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<std::array<int, 16>> anc1(2 * n + 1), anc2(2 * n + 1);
  std::vector<std::vector<int>> g1(2 * n + 1);
  std::vector<std::vector<int>> g2(2 * n + 1);
  for (int i = 1; i <= 2 * n - 2; ++i) {
    int u; scanf("%d", &u);
    anc1[i][0] = u;
    g1[u].emplace_back(i);
    g1[i].emplace_back(u);
  }
  for (int i = 1; i <= 2 * n - 2; ++i) {
    int u; scanf("%d", &u);
    anc2[i][0] = u;
    g2[u].emplace_back(i);
    g2[i].emplace_back(u);
  }
  anc1[2 * n - 1][0] = 2 * n - 1;
  anc2[2 * n - 1][0] = 2 * n - 1;
  for (int j = 1; j < 16; ++j) {
    for (int i = 1; i <= 2 * n - 1; ++i) {
      anc1[i][j] = anc1[anc1[i][j - 1]][j - 1];
      anc2[i][j] = anc2[anc2[i][j - 1]][j - 1];
    }
  }
  std::vector<int> dep1(2 * n + 1), tin1(2 * n + 1), tout1(2 * n + 1), cnt1(2 * n + 1);
  std::vector<int> dep2(2 * n + 1), tin2(2 * n + 1), tout2(2 * n + 1), cnt2(2 * n + 1);
  int tm = 1;
  dep1[0] = -1;
  std::function<void(int, int)> Dfs1 = [&](int v, int p) {
    dep1[v] = dep1[p] + 1;
    tin1[v] = tm++;
    cnt1[v]++;
    for (auto to: g1[v]) {
      if (to == p) {
        continue;
      }
      Dfs1(to, v);
      cnt1[v] += cnt1[to];
    }
    tout1[v] = tm++;
  };
  std::function<void(int, int)> Dfs2 = [&](int v, int p) {
    dep2[v] = dep2[p] + 1;
    tin2[v] = tm++;
    cnt2[v]++;
    for (auto to: g2[v]) {
      if (to == p) {
        continue;
      }
      Dfs2(to, v);
      cnt2[v] += cnt2[to];
    }
    tout2[v] = tm++;
  };
  Dfs1(2 * n - 1, 0);
  Dfs2(2 * n - 1, 0);
  std::vector used1(2 * n + 1, std::vector<bool>(2 * n + 1));
  std::vector lca1(2 * n + 1, std::vector<bool>(2 * n + 1));
  std::vector used2(2 * n + 1, std::vector<bool>(2 * n + 1));
  std::vector lca2(2 * n + 1, std::vector<bool>(2 * n + 1));
  auto Lca1 = [&](int u, int v) {
    if (used1[u][v]) {
      return lca1[u][v];
    }
    used1[u][v] = used1[v][u] = true;
    if (dep1[u] < dep1[v]) {
      std::swap(u, v);
    }
    for (int i = 15; i >= 0; --i) {
      int anc = anc1[u][i];
      if (tin1[anc] <= tin1[v] && tout1[v] <= tout1[anc]) {
        continue;
      }
      u = anc;
    }
    return anc1[u][0];
  };
  auto Lca2 = [&](int u, int v) {
    if (used2[u][v]) {
      return lca2[u][v];
    }
    used2[u][v] = used2[v][u] = true;
    if (dep2[u] < dep2[v]) {
      std::swap(u, v);
    }
    for (int i = 15; i >= 0; --i) {
      int anc = anc2[u][i];
      if (tin2[anc] <= tin2[v] && tout2[v] <= tout2[anc]) {
        continue;
      }
      u = anc;
    }
    return anc2[u][0];
  };
  i64 cnt = 0;
  for (int A = 1; A <= n; ++A) {
    for (int B = A + 1; B <= n; ++B) {
      int lab = Lca1(A, B);
      int lab2 = Lca2(A, B);
      if (lab == lac) {
        if (lab2 != lac2) {
          cnt++;
        }
      } else if (lab == lbc) {
        if (lab2 != lbc2) {
          cnt++;
        }
      } else {
        if (lbc2 != lac2) {
          cnt++;
        }
      }      
    }
  }
  printf("%lld\n", cnt);
  return 0;
}
