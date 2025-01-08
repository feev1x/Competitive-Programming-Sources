/**
 *    author:  feev1x
 *    created: 15.11.2024 19:53:39
**/
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using i64 = long long;

struct Dsu {
  std::vector<int> p, sz, mx;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n + 1);
    sz.assign(n + 1, 1);
    mx.assign(n + 1, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline void ang(int i, int val) {
    mx[i] = val;
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        std::swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
      mx[v] = std::max(mx[v], mx[u]);
    }
  }
};

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n + 1);
    std::set<std::pair<int, int>> r;
    Dsu d(n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      d.ang(i, a[i]);
      r.emplace(a[i], i);
    }
    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
      r.erase({a[i], i});
      if (used[i]) continue;
      int l = -1;
      while (!r.empty()) {
        auto [u, ind] = *r.begin();
        if (u >= a[i]) {
          break;
        }
        r.erase(r.begin());
        if (ind < i) continue;
        used[ind] = true;
        d.unite(i, ind);
        if (ind > l) {
          l = ind;
        }
      }
      if (l > i) {
        r.emplace(a[l], l);
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", d.mx[d.get(i)]);
    }
    printf("\n");
  }
  return 0;
}

