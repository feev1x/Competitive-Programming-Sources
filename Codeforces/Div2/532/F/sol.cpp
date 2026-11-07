#include <bits/stdc++.h>

constexpr int N = 20;
  
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  int q; std::cin >> q;
  std::vector<int> l(q), r(q), ans(q);
  std::vector<std::vector<int>> qq(n);
  for (int i = 0; i < q; ++i) {
    std::cin >> l[i] >> r[i]; --l[i];
    qq[--r[i]].emplace_back(i);
  }
  std::array<int, N> bas{}, pos{};
  for (int i = 0; i < n; ++i) {
    int x = a[i], id = i;
    for (int j = N - 1; j >= 0; --j) {
      if (!(x >> j & 1)) continue;
      if (!bas[j]) {
        bas[j] = x;
        pos[j] = id;
        break;
      }
      if (pos[j] < id) {
        std::swap(bas[j], x);
        std::swap(pos[j], id);
      }
      x ^= bas[j];
    }
    for (auto j: qq[i]) {
      x = 0;
      for (int b = N - 1; b >= 0; --b) if (pos[b] >= l[j]) x = std::max(x, x ^ bas[b]);
      ans[j] = x;
    }
  }
  for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
  return 0;
}
