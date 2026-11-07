#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 1e6 + 48600;
int mp[N], nw[N];

struct Centroid {
  std::vector<std::vector<int>> g;
  std::vector<int> res, sub, resv;
  std::vector<bool> del;
  std::vector<int> s;
  int n, sz, centr;
  inline void dfs(int v, int p) {
    sub[v] = 1;
    for (auto to: g[v]) if (to != p && !del[to]) {
      dfs(to, v);
      sub[v] += sub[to];
    }
  }
  inline int cen(int v, int p) {
    for (auto to: g[v]) if (to != p && !del[to])
      if (sub[to] * 2 > sz) return cen(to, v);
    return v;
  }
  inline int get(int val) { return mp[val]- nw[val]; }
  inline void go(int v, int p, int val) {
    mp[val]++;
    for (auto to: g[v]) if (to != p && !del[to]) go(to, v, val ^ (1 << s[to]));
  }
  inline void clgo(int v, int p, int val) {
    mp[val] = 0;
    for (auto to: g[v]) if (to != p && !del[to]) clgo(to, v, val ^ (1 << s[to]));
  }
  inline void jk(int v, int p, int val) {
    nw[val]++;
    for (auto to: g[v]) if (to != p && !del[to]) jk(to, v, val ^ (1 << s[to]));
  }
  inline void cl(int v, int p, int val) {
    nw[val] = 0;
    for (auto to: g[v]) if (to != p && !del[to]) cl(to, v, val ^ (1 << s[to]));
  }
  inline void cn(int v, int p, int val) {
    resv[v] = get(val);
    if (val == (1 << s[centr])) res[centr] += 1;
    for (int i = 0; i < 20; ++i) {
      resv[v] += get(val ^ (1 << i));
      if ((val ^ (1 << i)) == (1 << s[centr])) res[centr] += 1;
    }
    for (auto to: g[v]) if (to != p && !del[to]) cn(to, v, val ^ (1 << s[to])), resv[v] += resv[to];
    res[v] += resv[v] * 2;
  }
  inline void dec(int v) {
    dfs(v, v);
    sz = sub[v];
    centr = v = cen(v, v);
    mp[1 << s[v]]++;
    for (auto to: g[v]) if (!del[to]) go(to, v, (1 << s[v]) ^ (1 << s[to]));
    for (auto to: g[v]) if (!del[to]) {
      jk(to, v, (1 << s[v]) ^ (1 << s[to]));
      cn(to, v, (1 << s[to]));
      cl(to, v, (1 << s[v]) ^ (1 << s[to]));
      res[v] += resv[to];
    }
    mp[1 << s[v]] = 0;
    for (auto to: g[v]) if (!del[to]) clgo(to, v, (1 << s[v]) ^ (1 << s[to]));
    del[v] = true;
    for (auto to: g[v]) if (!del[to]) {
      dec(to);
    }
  }
  Centroid(std::vector<std::vector<int>> g, std::vector<int> s) : g(g), n((int)g.size() - 1), s(s) {
    res.resize(n + 1);
    del.resize(n + 1);
    sub.resize(n + 1);
    resv.resize(n + 1);
    dec(1);
  }
};
  
signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::string s; std::cin >> s;
  std::vector<int> ts(n + 1);
  for (int i = 0; i < n; ++i) ts[i + 1] = s[i] - 'a';
  Centroid cen(g, ts);
  for (int i = 1; i <= n; ++i) std::cout << cen.res[i] / 2 + 1 << " \n"[i == n];
  return 0;
}
