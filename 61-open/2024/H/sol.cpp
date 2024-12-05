/**
 *    author:  feev1x
 *    created: 24.11.2024 12:18:57
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  inline i64 dis(const Point &a) {
    return std::abs(x - a.x) + std::abs(y - a.y);
  }
};

struct Dsu {
  std::vector<int> p, sz;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n + 1);
    sz.assign(n + 1, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        std::swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
      return true;
    }
    return false;
  }
};

struct Edge {
  int u, v; i64 w;
  Edge() : u(0), v(0), w(0) {}
  Edge(int _u, int _v, i64 _w) : u(_u), v(_v), w(_w) {}
  inline bool operator>(const Edge &a) {
    return w > a.w;
  }
  inline bool operator<(const Edge &a) {
    return w < a.w;
  }
};

int main() {
  int n, m; scanf("%d%d", &n, &m);
  int k; scanf("%d", &k);
  std::vector<Point> p(k);
  for (auto &[x, y]: p) {
    scanf("%d %d", &x, &y);
  }
  if (k & 1) {
    printf("0\n");
    exit(0);
  }
  std::vector<Edge> e;
  std::vector<std::set<std::pair<int, int>>> g(k);
  i64 sum = 0;
  std::vector<int> d(k);
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      sum += p[i].dis(p[j]);
      int w = p[i].dis(p[j]);
      d[i]++, d[j]++;
      g[i].emplace(j, w);
      g[j].emplace(i, w);
      e.emplace_back(i, j, p[i].dis(p[j]));
    }
  }
  std::sort(e.begin(), e.end(), std::greater<>());
  for (auto [u, v, w]: e) {
    if (d[u] > 1 && d[v] > 1) {
      g[u].erase({v, w});
      g[v].erase({u, w});
      d[u]--, d[v]--;
      sum -= w;
    }
  }
  auto Ans = [&](int v1, int v2, int v3, int u1, int u2, int u3) {
    i64 res = std::min(p[v1].dis(p[u1]) - p[u2].dis(p[u1]), p[v1].dis(p[u3]) +  - p[u2].dis(p[u3])) - p[v2].dis(p[v1]);
    res = std::min(res, std::min(p[v3].dis(p[u1]) + - p[u2].dis(p[u1]), p[v3].dis(p[u3]) - p[u2].dis(p[u3])) - p[v2].dis(p[v3]));
    return res;
  };
  for (int i = 0; i < k; ++i) {
    if (d[i] == 1) continue;
    int v1 = g[i].begin()->first, v2 = (++g[i].begin())->first;
    i64 cost = int(INFINITY), opt = -1;
    for (int j = i + 1; j < k; ++j) {
      if (d[j] == 1) continue;
      int u1 = g[j].begin()->first, u2 = (++g[j].begin())->first;
      i64 ans = Ans(v1, i, v2, u1, j, u2);
      if (ans < cost) {
        cost = ans;
        opt = j;
      }
    }
    assert(opt != -1);
    d[opt]--, d[i]--;
    sum += cost;
  }
  printf("%lld\n", sum);
  return 0;
}
