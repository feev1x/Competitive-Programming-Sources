#include "Ali.h"
#include <bits/stdc++.h>

namespace {
constexpr int SZ = 1429;
std::vector<std::vector<int>> g;
std::vector<int> idx, ridx, idxt, ridxt, gr, gi, vl, rt;
int nw, nwt, root, n;
}

struct Dsu {
  std::vector<int> p, sz;
  int n;
  Dsu(int n) : n(n) {
    p.resize(n);
    sz.resize(n, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      sz[v] += sz[u];
      p[u] = v;
    }
  }
};

void Init(int N, std::vector<int> U, std::vector<int> V) {
  n = N;
  if (idx.empty()) {
    idx.resize(SZ * SZ);
    idxt.resize(1 << 25);
    nw = nwt = 0;
    for (int i = 0; i < SZ; ++i)
      for (int j = 0; j <= i; ++j)
        idx[i * SZ + j] = nw++, ridx.emplace_back(i * SZ + j);
    std::vector<std::vector<int>> gg(1);
    std::vector<int> pp(1), ssz(1, 1);
    std::string ss;
    auto Dfs = [&](auto &&self, int sum, int v, std::vector<std::vector<int>> &g, std::vector<int> &p, std::vector<int> &sz, std::string &s) -> void {
      if (sum == 0) {
        assert(v == 0);
        int val = 0;
        for (int i = 0; i < s.size(); ++i)
          val += (1 << i) * (s[i] - '0');
        assert(val < (1<<25));
        ridxt.emplace_back(val);
        idxt[val] = nwt++;
      }
      if (s.size() == 25) return;
      if (g[v].size() < 2 && (25 - s.size()) - 1 >= sum + 1) {
        g[v].emplace_back(g.size());
        int nv = g.size();
        g.emplace_back(std::vector<int>());
        s += "0";
        p.emplace_back(v);
        sz.emplace_back(1);
        int pr = v;
        bool flag = true;
        while (pr != 0) {
          sz[pr]++;
          if (sz[pr] > 6) flag = false;
          pr = p[pr];
        }
        sz[pr]++;
        if (flag) self(self, sum + 1, nv, g, p, sz, s);
        sz.pop_back();
        pr = v;
        while (pr != 0) {
          sz[pr]--;
          pr = p[pr];
        }
        sz[pr]--;
        s.pop_back();
        p.pop_back();
        g.pop_back();
        g[v].pop_back();
      }
      if (sum) {
        assert(v != 0);
        int nv = p[v];
        s += "1";
        self(self, sum - 1, nv, g, p, sz, s);
        s.pop_back();
      }
    }; Dfs(Dfs, 0, 0, gg, pp, ssz, ss);
  }
  std::vector<std::vector<int>>().swap(g);
  g.resize(n);
  for (int i = 0; i < U.size(); ++i) {
    g[U[i]].emplace_back(V[i]);
    g[V[i]].emplace_back(U[i]);
  }
  std::vector<int> sz(n);
  int nwg = 0;
  Dsu d(n);
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    sz[v] = 1;
    for (auto to: g[v]) if (to != p) {
      self(self, to, v);
      if (sz[to] <= 6) {
        d.unite(v, to);
        sz[v] += sz[to];
      }
    }
  };
  root = 0;
  while (g[root].size() > 2) root++;
  Dfs(Dfs, root, root);
  std::map<int, int> mp;
  gr.resize(n);
  gi.resize(n);
  for (int i = 0; i < n; ++i) {
    if (!mp.count(d.get(i))) mp[d.get(i)] = nwg++;
    gr[i] = mp[d.get(i)];
  }
  rt.assign(nwg, -1);
  vl.resize(nwg);
  for (int i = 0; i < n; ++i) 
    if (rt[gr[i]] == -1 || sz[rt[gr[i]]] < sz[i]) rt[gr[i]] = i;
  assert(nwg <= SZ);
  int ni = 0, pw = 0;
  auto Get = [&](auto &&self, int v, int p) -> void {
    gi[v] = ni++;
    for (auto to: g[v]) if (to != p && gr[to] == gr[v]) {
      pw++;
      self(self, to, v);
    };
    if (v != p) {
      vl[gr[v]] += (1 << pw++);
    }
  };
  for (int i = 0; i < nwg; ++i) {
    ni = 0, pw = 0;
    vl[i] = 0;
    Get(Get, rt[i], rt[i]);
  }
  for (int i = 0; i < n; ++i) SetID(i, gr[i] * 14 + gi[i]);
}

std::string SendA(std::string S) {
  int num = 0;
  for (int i = 0; i < 20; ++i) num += (1 << i) * (S[i] - '0');
  int x = ridx[num] / SZ, y = ridx[num] % SZ;
  std::string res;
  for (int i = 0; i < 11; ++i) res += char((idxt[vl[x]] >> i & 1) + '0');
  for (int i = 0; i < 11; ++i) res += char((idxt[vl[y]] >> i & 1) + '0');
  int U = -1, V, dis = 0;
  std::vector<int> par(n, -1);
  bool flag = false;
  auto Dfs = [&](auto &&self, int v) -> void {
    if (gr[v] == y) {
      V = v;
      flag = true;
      return;
    }
    for (auto to: g[v]) if (to != par[v]) {
      par[to] = v;
      self(self, to);
      if (flag) {
        if (U == -1) dis++;
        if (gr[v] == x && U == -1) U = v;
        return;
      }
    }
  }; Dfs(Dfs, rt[x]);
  if (U == -1) U = V;
  for (int i = 0; i < 14; ++i) res += char((dis >> i & 1) + '0');
  for (int i = 0; i < 4; ++i) res += char((gi[U] >> i & 1) + '0');
  for (int i = 0; i < 4; ++i) res += char((gi[V] >> i & 1) + '0');
  return res;
}
