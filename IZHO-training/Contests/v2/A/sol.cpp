/**
 *    author:  feev1x
 *    created: 06.01.2025 09:51:56
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, Q; std::cin >> n >> Q;  
  std::string s; std::cin >> s;
  std::string bt; std::cin >> bt;
  std::vector<std::vector<int>> adj(n), adj1(n);
  std::vector<int> pref(n), pref1(n);
  pref[0] = bt[0] == '1';
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + (bt[i] == '1');
    pref1[i] = pref[i - 1];
  }
  int L = 0, R = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (s[i] == 'L') {
      L++;
    } else {
      if (L - 1 != R) {
        adj[L - 1].emplace_back(R);
      }
      R++;
    }
  }
  L = n - 1, R = n - 1;
  for (int i = 2 * n - 1; i >= 0; --i) {
    if (s[i] == 'L') {
      if (R + 1 != L) {
        adj1[R + 1].emplace_back(L);
      }
      L--;
    } else if (s[i] == 'R') {
      R--;
    }
  }
  std::vector<std::array<i64, 19>> anc(n), anc1(n), sum(n), sum1(n);
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    anc[v][0] = p;
    if (p != -1) {
      sum[v][0] = pref[p];
    }
    for (int i = 1; i < 19; ++i) {
      if (anc[v][i - 1] != -1 && anc[anc[v][i - 1]][i - 1] != -1) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
        sum[v][i] = sum[anc[v][i - 1]][i - 1] + sum[v][i - 1];
      } else {
        anc[v][i] = -1;
      }
    }
    for (auto to: adj[v]) {
      self(self, to, v);
    }
  };
  Dfs(Dfs, n - 1, -1);
  auto Dfs1 = [&](auto &&self, int v, int p) -> void {
    anc1[v][0] = p;
    if (p != -1) {
      sum1[v][0] = pref1[p];
    }
    for (int i = 1; i < 19; ++i) {
      if (anc1[v][i - 1] != -1 && anc1[anc1[v][i - 1]][i - 1] != -1) {
        anc1[v][i] = anc1[anc1[v][i - 1]][i - 1];
        sum1[v][i] = sum1[anc1[v][i - 1]][i - 1] + sum1[v][i - 1];
      } else {
        anc1[v][i] = -1;
      }
    }
    for (auto to: adj1[v]) {
      self(self, to, v);
    }
  };
  Dfs1(Dfs1, 0, -1);
  auto Jumpr = [&](int a, int j) {
    i64 res = 0;
    int cnt = 0;
    for (int i = 18; i >= 0; --i) {
      if (cnt + (1 << i) <= j) {
        res += sum[a][i];
        cnt += 1 << i;
        a = anc[a][i];
        assert(a != -1);
      }
    }
    return res;
  };
  auto Jumpl = [&](int a, int j) {
    i64 res = 0;
    int cnt = 0;
    for (int i = 18; i >= 0; --i) {
      if (cnt + (1 << i) <= j) {
        res += sum1[a][i];
        cnt += 1 << i;
        a = anc1[a][i];
        assert(a != -1);
      }
    }
    return res;
  };
  while (Q--) {
    int a, b; std::cin >> a >> b; a--, b--;
    if (a > b) {
      std::swap(a, b);
    }
    int Dis = 0;
    int u = a;
    for (int i = 18; i >= 0; --i) {
      if (anc[u][i] < b && anc[u][i] != -1) {
        Dis += 1 << i;
        u = anc[u][i];
      }
    }
    Dis++;
    std::cout << Dis << ' ' << bt[a] - '0' + bt[b] - '0' + Jumpr(a, Dis - 1) - Jumpl(b, Dis - 1) << '\n';
  }
  return 0;
}
