#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

struct Dsu {
  std::vector<int64_t> p, cap;
  int n;
  Dsu(std::vector<int64_t> c) : n(c.size() - 1) {
    p.resize(n + 1);
    cap = c;
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return cap[v] > 0 ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    if (u > v) std::swap(u, v);
    p[u] = v;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<int64_t> c(n + 1);
  std::stack<int> stk;
  for (int i = 1; i <= n; ++i) std::cin >> c[i];
  c.emplace_back(INF);
  Dsu d(c);
  for (int i = n; i >= 1; --i) {
    while (stk.size() && c[stk.top()] <= c[i]) stk.pop();
    if (stk.size()) d.unite(i, stk.top());
    else d.unite(i, n + 1);
    stk.emplace(i);
  }
  while (q--) {
    char ch; std::cin >> ch;
    if (ch == '+') {
      int l, x; std::cin >> l >> x;
      while (x > 0) {
        if (x > d.cap[l]) {
          x -= d.cap[l];
          d.cap[l] = 0;
          l = d.get(l);
        } else {
          d.cap[l] -= x;
          x = 0;
        }
      }
    } else {
      int l; std::cin >> l;
      std::cout << c[l] - d.cap[l] << '\n';
    }
  }
  return 0;
}
