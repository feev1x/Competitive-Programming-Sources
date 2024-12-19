/**
 *    author:  feev1x
 *    created: 11.12.2024 09:53:34
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m, s; scanf("%d%d%d", &n, &m, &s);
  std::vector<std::vector<int>> g(n + 1);
  while (m--) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
  }
  std::queue<int> q;
  std::vector<int> comp(n + 1), p(n + 1, -1);
  for (auto to: g[s]) {
    comp[to] = to;
    p[to] = s;
    q.emplace(to);
  }
  int f = -1, p1 = -1, p2 = -1;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (auto to: g[v]) {
      if (to == s) {
        continue;
      }
      if (!comp[to]) {
        comp[to] = comp[v];
        p[to] = v;
        q.emplace(to);
      } else if (comp[to] != comp[v]) {
        f = to;
        p1 = p[f];
        p2 = v;
        p[f] = v;
        goto end;
      }
    }
  }
end:
  if (f == -1) {
    printf("Impossible\n");
    exit(0);
  }
  std::vector<int> ans1, ans2;
  for (int v = p1; v != -1; v = p[v]) {
    ans1.emplace_back(v);
  }
  for (int v = p2; v != -1; v = p[v]) {
    ans2.emplace_back(v);
  }
  std::reverse(ans1.begin(), ans1.end());
  std::reverse(ans2.begin(), ans2.end());
  ans1.emplace_back(f);
  ans2.emplace_back(f);
  printf("Possible\n");
  auto Print = [](std::vector<int> ans) {
    printf("%d\n", (int)ans.size());
    for (auto u: ans) {
      printf("%d ", u);
    }
    printf("\n");
  };
  Print(ans1);
  Print(ans2);
  return 0;
}
