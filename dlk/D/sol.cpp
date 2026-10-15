#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, q, t; std::cin >> n >> m >> q >> t;
  std::vector<int64_t> w(n + 1), a(m + 1), b(m + 1), c(m + 1), d(m + 1);
  std::vector<std::set<int>> g(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> w[i];
  for (int i = 1; i <= m; ++i) {
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    g[a[i]].emplace(i);
    g[b[i]].emplace(i);
    g[c[i]].emplace(i);
  }
  int ls = 0;
  if (n <= 50000 && m <= 50000 && q <= 50000 && t == 2) {
    int cnt = 0;
    std::vector<int> idx, new_idx;
    for (int i = 1; i <= m; ++i) idx.emplace_back(i);
    for (auto i: idx) {
      if (d[i] <= w[a[i]] + w[b[i]] + w[c[i]]) cnt++;
      else new_idx.emplace_back(i);
    }
    std::swap(idx, new_idx);
    std::vector<int>().swap(new_idx);
    std::cout << cnt << '\n';
    ls = cnt;
    while (q--) {
      int p, v; std::cin >> p >> v;
      if (t == 2) {
        p = (p + ls - 1) % n + 1;
      }
      w[p] += v;
      for (auto i: idx) {
        if (d[i] <= w[a[i]] + w[b[i]] + w[c[i]]) cnt++;
        else new_idx.emplace_back(i);
      }
      std::swap(idx, new_idx);
      std::vector<int>().swap(new_idx);
      std::cout << cnt << '\n';
      ls = cnt;
    }
  } else if (t == 1) {
    int sq = std::sqrt(q);
    std::vector<int> pos(m + 1, q + 1), p(q + 1), v(q + 1), add(q + 1);
    std::set<int> st;
    for (int i = 1; i <= m; ++i) {
      if (d[i] > w[a[i]] + w[b[i]] + w[c[i]]) st.emplace(i);
      else pos[i] = 0;
    }
    for (int i = 1; i <= q; ++i) {
      std::cin >> p[i] >> v[i];
      w[p[i]] += v[i];
      if (i % sq == 0 || i == q) {
        std::vector<int> del;
        for (auto j: st) {
          if (d[j] <= w[a[j]] + w[b[j]] + w[c[j]]) {
            int k = i;
            for (; k >= 1; --k) {
              w[p[k]] -= v[k];
              if (d[j] > w[a[j]] + w[b[j]] + w[c[j]]) {
                pos[j] = k;
                del.emplace_back(j);
                break;
              }
            }
            for (; k <= i; ++k) {
              w[p[k]] += v[k];
            }
          }
        }
        for (auto u: del) st.erase(u);
      }
    }
    for (int i = 1; i <= m; ++i) if (pos[i] <= q) add[pos[i]]++;
    int res = 0;
    for (int i = 0; i <= q; ++i) {
      res += add[i];
      std::cout << res << '\n';
    }
  } else {
    int cnt = 0;
    auto Add = [&](int i) {
      if (d[i] <= w[a[i]] + w[b[i]] + w[c[i]]) {
        cnt++;
        g[a[i]].erase(i);
        g[b[i]].erase(i);
        g[c[i]].erase(i);
      }
    };
    for (int i = 1; i <= m; ++i) {
      Add(i);
    }
    std::cout << cnt << '\n';
    ls = cnt;
    while (q--) {
      int p, v; std::cin >> p >> v;
      p = (p + ls - 1) % n + 1;
      if (w[p] >= 100) {
        std::cout << cnt << '\n';
        ls = cnt;
        continue;
      }
      w[p] += v;
      std::vector<int> ar;
      for (auto u: g[p]) ar.emplace_back(u);
      for (auto u: ar) Add(u);
      std::cout << cnt << '\n';
      ls = cnt;
    }
  }
  return 0;
}
