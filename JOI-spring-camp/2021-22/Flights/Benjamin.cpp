#include "Benjamin.h"
#include <bits/stdc++.h>

namespace {
constexpr int SZ = 1429;
std::vector<int> idx, ridx, idxt, ridxt;
int nw, nwt, n, x, y;
}

std::string SendB(int N, int X, int Y) {
  x = X;
  y = Y;
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
  std::string res;
  int gx = x / 14, gy = y / 14;
  if (gx < gy) {
    std::swap(x, y);
    std::swap(gx, gy);
  }
  int val = idx[gx * SZ + gy];
  for (int i = 0; i < 20; ++i) res += char((val >> i & 1) + '0');
  return res;
}

int Answer(std::string T) {
  std::vector<std::vector<int>> gx(1), gy(1);
  std::vector<int> px(1), py(1);
  int vx = 0, vy = 0;
  for (int i = 0; i < 11; ++i) {
    vx += (1 << i) * (T[i] - '0');
    vy += (1 << i) * (T[i + 11] - '0');
  }
  vx = ridxt[vx], vy = ridxt[vy];
  int lx = __builtin_popcount(vx), ly = __builtin_popcount(vy);
  {
    int v = 0;
    for (int i = 0, c = 0; c < lx && i < 25; ++i) {
      if (vx >> i & 1) {
        c++;
        v = px[v];
      } else {
        gx[v].emplace_back(gx.size());
        int nv = gx.size();
        gx.emplace_back(std::vector<int>());
        px.emplace_back(v);
        v = nv;
      }
    }
    for (int i = 1; i < gx.size(); ++i) gx[i].emplace_back(px[i]);
  }
  {
    int v = 0;
    for (int i = 0, c = 0; c < ly && i < 25; ++i) {
      if (vy >> i & 1) {
        c++;
        v = py[v];
      } else {
        gy[v].emplace_back(gy.size());
        int nv = gy.size();
        gy.emplace_back(std::vector<int>());
        py.emplace_back(v);
        v = nv;
      }
    }
    for (int i = 1; i < gy.size(); ++i) gy[i].emplace_back(py[i]);
  }
  int res = 0;
  for (int i = 0; i < 14; ++i) res += (1 << i) * (T[i + 22] - '0');
  std::vector<int> dx(gx.size()), dy(gy.size());
  {
    auto Dfs = [&](auto &&self, int v, int p) -> void {
      for (auto to: gx[v]) if (to != p) {
        dx[to] = dx[v] + 1;
        self(self, to, v);
      }
    }; Dfs(Dfs, x % 14, x % 14);
  }
  {
    auto Dfs = [&](auto &&self, int v, int p) -> void {
      for (auto to: gy[v]) if (to != p) {
        dy[to] = dy[v] + 1;
        self(self, to, v);
      }
    }; Dfs(Dfs, y % 14, y % 14);
  }
  int U = 0, V = 0;
  for (int i = 0; i < 4; ++i) U += (1 << i) * (T[i + 36] - '0');
  for (int i = 0; i < 4; ++i) V += (1 << i) * (T[i + 40] - '0');
  if (x / 14 == y / 14) {
    return dx[y % 14];
  }
  return res + dx[U] + dy[V];
}
