/**
 *    author:  feev1x
 *    created: 15.12.2024 21:50:35
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> r(n + 1), sz(n + 1);
    std::vector<bool> cyc(n + 1), used(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
    }
    std::map<int, bool> us;
    for (int i = 1; i <= n; ++i) {
      if (used[i]) {
        continue;
      }
      us[i] = true;
      int u = r[i];
      bool flag = false;
      while (true) {
        if (us[u]) {
          flag = true;
          break;
        } else if (used[u]) {
          break;
        }
        us[u] = true;
        used[u] = true;
        u = r[u];
      }
      us.clear();
      if (flag) {
        for (int v = u; !cyc[v]; v = r[v]) {
          cyc[v] = true;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      used[i] = false;
    }
    int res = 0;
    auto Dfs = [&](auto &&Dfs, int v) -> int {
      if (cyc[v]) {
        return 0;
      }
      if (used[v]) {
        return sz[v];
      }
      used[v] = true;
      return sz[v] = Dfs(Dfs, r[v]) + 1;
    };
    for (int i = 1; i <= n; ++i) {
      res = std::max(res, Dfs(Dfs, i));
    }
    printf("%d\n", res + 2);
  }
  return 0;
}
