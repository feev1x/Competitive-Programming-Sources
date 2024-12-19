/**
 *    author:  feev1x
 *    created: 08.12.2024 21:57:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    bool flag = true;
    std::vector<int> a(n + 1);
    std::vector<bool> used(2 * n + 1);
    std::set<int> st1, st2;
    a[1] = 1;
    used[1] = true;
    for (int i = 2; i <= 2 * n; ++i) {
      if (i & 1) {
        st1.emplace(i);
      } else {
        st2.emplace(i);
      }
    }
    auto Dfs = [&](auto Dfs, int v, int p) -> void {
      for (auto to: g[v]) {
        if (to == p) {
          continue;
        }
        if (a[v] + 1 <= 2 * n && !used[a[v] + 1]) {
          st1.erase(a[v] + 1);
          st2.erase(a[v] + 1);
          used[a[v] + 1] = true;
          a[to] = a[v] + 1;
          Dfs(Dfs, to, v);
        } else if (a[v] - 1 > 0 && !used[a[v] - 1]) {
          st1.erase(a[v] - 1);
          st2.erase(a[v] - 1);
          used[a[v] - 1] = true;
          a[to] = a[v] - 1;
          Dfs(Dfs, to, v);
        } else {
          if (a[v] & 1) {
            if (st1.empty() || (std::abs(a[v] - *st1.begin()) == 2 && std::abs(a[v] - *--st1.end()) == 2)) {
              flag = false;
              return;
            }
            if (std::abs(a[v] - *st1.begin()) == 2) {
              a[to] = *--st1.end();
              st1.erase(--st1.end());
            } else {
              a[to] = *st1.begin();
              st1.erase(st1.begin());
            }
            used[a[to]] = true;
            Dfs(Dfs, to, v);
          } else {
            if (st2.empty() || (std::abs(a[v] - *st2.begin()) == 2 && std::abs(a[v] - *--st2.end()) == 2)) {
              flag = false;
              return;
            }
            if (std::abs(a[v] - *st2.begin()) == 2) {
              a[to] = *--st2.end();
              st2.erase(--st2.end());
            } else {
              a[to] = *st2.begin();
              st2.erase(st2.begin());
            }
            used[a[to]] = true;
            Dfs(Dfs, to, v);
          }
        }
        if (!flag) {
          return;
        }
      }
      if (!flag) {
        return;
      }
    };
    Dfs(Dfs, 1, 0);
    if (!flag) {
      printf("-1\n");
    } else {
      for (int i = 1; i <= n; ++i) {
        printf("%d%c", a[i], " \n"[i == n]);
      }
    }
  }
  return 0;
}
