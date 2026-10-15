#include <bits/stdc++.h>

struct Segtree {
  std::vector<std::vector<int>> t, p;
  int n;
  Segtree
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<int> l(n), r(n), qa(q), qb(q), qc(q), qd(q), ans(q);
  for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i];
  for (int i = 0; i < q; ++i) std::cin >> qa[i] >> qb[i] >> qc[i] >> qd[i];
  
  for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
  return 0;
}
