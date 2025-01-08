/**
 *    author:  feev1x
 *    created: 02.01.2025 17:52:41
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

struct Dsu {
  std::vector<int> p, sz;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
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
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int L, m, q; std::cin >> L >> m >> q;
  std::vector<std::pair<int, int>> e;
  std::vector<int> cmp;
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    cmp.emplace_back(u);
    cmp.emplace_back(v);
    e.emplace_back(u, v);
  }
  std::sort(cmp.begin(), cmp.end());
  cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
  std::map<int, int> val;
  std::sort(e.begin(), e.end());
  std::vector<std::vector<int>> g(cmp.size());
  for (int i = 0; i < cmp.size(); ++i) {
    val[cmp[i]] = i;
  }
  for (auto &[a, b]: e) {
    a = val[a], b = val[b];
  }
  Dsu d(cmp.size());
  if (m == 0) {
    while (q--) {
      int x, y; std::cin >> x >> y;
      if (x > y) {
        std::swap(x, y);
      }
      std::cout << std::min(y - x, x + L - y) << '\n';
    }
  } else if (m <= 1000 && q <= 1000) {
    std::vector<std::vector<int>> g(cmp.size());
    for (auto [a, b]: e) {
      g[a].emplace_back(b);
      g[b].emplace_back(a);
      for (int i = 0; i < m; ++i) {
        if (a == e[i].first || b == e[i].second) {
          continue;
        }
        if (e[i].first < a && a < e[i].second && e[i].second < b) {
          g[a].emplace_back(e[i].first);
          g[a].emplace_back(e[i].second);
          g[b].emplace_back(e[i].first);
          g[b].emplace_back(e[i].second);
        } else if (e[i].first < b && b < e[i].second && e[i].first > a) {
          g[a].emplace_back(e[i].first);
          g[a].emplace_back(e[i].second);
          g[b].emplace_back(e[i].first);
          g[b].emplace_back(e[i].second);
        }
      }
    }
    std::vector<std::vector<int>> dis(cmp.size());
    int L_ = L;
    L = cmp.size();
    for (int u = 0; u < L; ++u) {
      dis[u].assign(L, INF);
      dis[u][u] = 0;
      std::set<std::pair<int, int>> st;
      st.emplace(0, u);
      while (st.size()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for (auto to: g[v]) {
          assert(dis[u][to] >= dis[u][v]);
          if (dis[u][to] > dis[u][v]) {
            st.erase({dis[u][to], to});
            dis[u][to] = dis[u][v];
            st.emplace(dis[u][to], to);
          }
        }
        if (v + 1 < L && dis[u][v + 1] > dis[u][v] + (cmp[v + 1] - cmp[v])) {
          st.erase({dis[u][v + 1], v + 1});
          dis[u][v + 1] = dis[u][v] + (cmp[v + 1] - cmp[v]);
          st.emplace(dis[u][v + 1], v + 1);
        } else if (v + 1 == L && dis[u][0] > dis[u][v] + (cmp[v] - cmp[0])) {
          st.erase({dis[u][0], 0});
          dis[u][0] = dis[u][v] + (cmp[v] - cmp[0]);
          st.emplace(dis[u][0], 0);
        }
        if (v > 0 && dis[u][v - 1] > dis[u][v] + (cmp[v] - cmp[v - 1])) {
          st.erase({dis[u][v - 1], v - 1});
          dis[u][v - 1] = dis[u][v] + (cmp[v] - cmp[v - 1]);
          st.emplace(dis[u][v - 1], v - 1);
        } else if (v == 0 & dis[u][L - 1] > dis[u][v] + (cmp[L - 1] - cmp[v])) {
          st.erase({dis[u][L - 1], L - 1});
          dis[u][L - 1] = dis[u][v] + (cmp[L - 1] - cmp[v]);
          st.emplace(dis[u][L - 1], L - 1);
        }
      }
    }
    L = L_;
    while (q--) {
      int x, y; std::cin >> x >> y;
      int min = std::min(std::abs(x - y), L - std::abs(x - y));
      int r = std::upper_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
      r %= (int)cmp.size();
      int l = (r - 1) + (int)cmp.size();
      l %= (int)cmp.size();
      int ds = std::min(std::abs(x - cmp[l]), L - std::abs(x - cmp[l]));
      for (int i = 0; i < cmp.size(); ++i) {
        min = std::min(min, std::min(std::abs(cmp[i] - y), L - std::abs(cmp[i] - y)) + dis[l][i] + ds);
      }
      ds = std::min(std::abs(x - cmp[r]), L - std::abs(x - cmp[r]));
      for (int i = 0; i < cmp.size(); ++i) {
        min = std::min(min, std::min(std::abs(cmp[i] - y), L - std::abs(cmp[i] - y)) + dis[r][i] + ds);
      }
      std::cout << min << '\n';
    }
  } else {
    while (q--) {
      int x, y; std::cin >> x >> y;
      if (val.count(x) && val.count(y) && d.get(val[x]) == d.get(val[y])) {
        std::cout << 0 << '\n';
      } else {
        std::cout << 1 << '\n';
      }
    }
  }
  return 0;
}
