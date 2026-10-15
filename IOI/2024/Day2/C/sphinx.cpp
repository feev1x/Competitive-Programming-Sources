#include "sphinx.h"
#include <bits/stdc++.h>

struct Dsu {
  std::vector<int> sz, p;
  int n, cnt;
  Dsu(int n) : n(n) {
    sz.assign(n, 1);
    p.resize(n);
    std::iota(p.begin(), p.end(), 0);
    cnt = n;
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
      cnt--;
    }
  }
};

std::vector<int> find_colours(int N, std::vector<int> X, std::vector<int> Y) {
  std::vector<int> C(N);
  std::vector<std::vector<int>> g(N);
  for (int i = 0; i < X.size(); ++i) g[X[i]].emplace_back(Y[i]);
  for (int i = 0; i < X.size(); ++i) g[Y[i]].emplace_back(X[i]);
  Dsu dsu(N);
  for (int i = 0; i < X.size(); ++i) {
    std::vector<int> E(N, N);
    E[X[i]] = E[Y[i]] = -1;
    Dsu d(N);
    for (int j = 0; j < X.size(); ++j) {
      if (X[j] != X[i] && X[j] != Y[i] && Y[j] != X[i] && Y[j] != Y[i]) {
        d.unite(X[j], Y[j]);
      }
    }
    int c = d.cnt;
    int got = perform_experiment(E);
    if (got == c);
    else {
      dsu.unite(X[i], Y[i]);
    }
  }
  for (int i = 0; i < N; ++i) C[i] = dsu.get(i);
  return C;
  
}
