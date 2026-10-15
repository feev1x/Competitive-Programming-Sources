#include "obstacles.h"
#include <bits/stdc++.h>

struct Dsu {
  std::vector<int> p, sz;
  int n;
  Dsu() {}
  Dsu(int n) : n(n) {
    p.resize(n);
    sz.assign(n, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

Dsu d;

struct SpTable {
  std::vector<std::vector<int>> sp;
  std::vector<int> lg;
  int n;
  SpTable(std::vector<int> a) : n(a.size()) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    sp.resize(lg[n] + 1, std::vector<int>(n));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
  }
  inline int get(int l, int r) {
    int i = lg[r - l + 1];
    return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

struct SpTable2 {
  std::vector<std::vector<int>> sp;
  std::vector<int> lg;
  int n;
  SpTable2(std::vector<int> a) : n(a.size()) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    sp.resize(lg[n] + 1, std::vector<int>(n));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
  }
  inline int get(int l, int r) {
    int i = lg[r - l + 1];
    return std::min(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

void initialize(std::vector<int> T, std::vector<int> H) {
  int n = T.size(), m = H.size();
  d = Dsu(m);
  SpTable sp(H);
  SpTable2 sp2(H);
  std::vector<std::pair<int, int>> pr;
  int mn = 1e9;
  for (int i = 0; i < n; ++i) {
    mn = std::min(mn, T[i]);
    if (pr.empty() || pr.back().first < T[i]) {
      pr.emplace_back(T[i], mn);
      mn = 1e9;
    }
  }
  for (int i = (int)pr.size() - 1; i > 0; --i) {
    if (pr[i].second > pr[i - 1].second) {
      pr[i].second = pr[i - 1].second;
      pr[i - 1].first = pr[i].first;
    }
  }
  pr.erase(std::unique(pr.begin(), pr.end()), pr.end());
  std::vector<int> id(m);
  for (int i = 0; i < m; ++i) {
    int l = 0, r = pr.size() - 1, ans = pr.size();
    while (l <= r) {
      int mid = l + r >> 1;
      if (pr[mid].first > H[i]) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    id[i] = ans;
  }
  std::vector<std::pair<int, int>> lr(m);
  auto Get = [&](int i, int nw) {
    int L, R;
    {
      int l = 0, r = lr[i].first, ans = i;
      while (l <= r) {
        int mid = l + r >> 1;
        if (sp.get(mid, i) < pr[nw].first) r = mid - 1, ans = mid;
        else l = mid + 1;
      }
      L = ans;
    }
    int l = lr[i].second, r = m - 1, ans = i;
    while (l <= r) {
      int mid = l + r >> 1;
      if (sp.get(i, mid) < pr[nw].first) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    R = ans;
    return std::pair<int, int>{L, R};
  };
  std::set<std::pair<int, int>> st;
  std::vector<std::pair<int, int>> mxr(m, {-1, -1});
  std::vector<std::vector<int>> idx(pr.size() + 1);
  auto Add = [&](int i) {
    int mn = pr.size();
    if (lr[i].first > 0) mn = std::min(mn, id[lr[i].first - 1]);
    if (lr[i].second + 1 < m) mn = std::min(mn, id[lr[i].second + 1]);
    if (mxr[lr[i].first].first == lr[i].second) {
      int sg = mxr[lr[i].first].second;
      d.unite(sg, i);
      i = d.get(i);
      mxr[lr[i].first] = {lr[i].second, i};
      return;
    }
    mxr[lr[i].first] = {lr[i].second, i};
    idx[mn].emplace_back(i);
  };
  for (int i = 0; i < m; ++i) {
    lr[i] = {i, i};
    Add(i);
  }
  int nw = 0;
  for (auto [t, mn]: pr) {
    for (auto i: idx[nw]) {
      i = d.get(i);
      if (sp2.get(lr[i].first, lr[i].second) < mn) lr[i] = Get(i, nw), Add(i);
    }
    nw++;
  }
}

bool can_reach(int L, int R, int S, int D) {
  return d.get(S) == d.get(D);
}
