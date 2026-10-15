#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<std::pair<int, int>> qq(q);
  std::vector<bool> tv(n + 1), del(n + 1);
  for (auto &[t, v]: qq) {
    std::cin >> t;
    if (t == 1) {
      std::cin >> v;
      tv[v] = !tv[v];
      continue;
    }
    char c; std::cin >> c;
    v = int(c);
  }
  std::reverse(qq.begin(), qq.end());
  std::set<int> tile, notile;
  for (int i = 1; i <= n; ++i) {
    if (tv[i]) tile.emplace(i);
    else notile.emplace(i);
  }
  std::string s(n + 1, 'a');
  for (auto [t, v]: qq) {
    if (t == 1) {
      if (del[v]) continue;
      if (tv[v]) tile.erase(v), notile.emplace(v);
      else notile.erase(v), tile.emplace(v);
      tv[v] = !tv[v];
      continue;
    }
    for (auto u: notile) {
      del[u] = true;
      s[u] = char(v);
    }
    std::set<int>().swap(notile);
  }
  for (int i = 1; i <= n; ++i) std::cout << s[i];
  std::cout << '\n';
  return 0;
}
