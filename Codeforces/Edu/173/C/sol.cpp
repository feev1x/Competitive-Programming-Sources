/**
 *    author:  feev1x
 *    created: 24.12.2024 20:55:27
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<i64> a(n), p(n + 1);
    int pos = -1;
    for (auto &u: a) {
      std::cin >> u;
    }
    for (int i = 0; i < n; ++i) {
      p[i + 1] = a[i] + p[i];
      if (std::abs(a[i]) != 1) {
        pos = i;
      }
    }
    if (pos == -1) {
      pos = 0;
    }
    std::multiset<i64> sl, sr;
    i64 l = INF, r = -INF;
    for (int i = 0; i < pos; ++i) {
      sr.emplace(p[i + 1]);
    }
    sl.emplace(0);
    for (int i = 0; i < pos; ++i) {
      sr.erase(sr.find(p[i + 1]));
      if (sr.size()) {
        l = std::min(l, *sr.begin() - p[i]);
        r = std::max(r, *--sr.end() - p[i]);
      }
      if (sl.size()) {
        l = std::min(l, p[i + 1] - *--sl.end());
        r = std::max(r, p[i + 1] - *sl.begin());
      }
      sl.emplace(p[i + 1]);
    }
    std::multiset<i64>().swap(sl);
    sl.emplace(p[pos + 1]);
    for (int i = pos + 1; i < n; ++i) {
      sr.emplace(p[i + 1]);
    }
    for (int i = pos + 1; i < n; ++i) {
      sr.erase(sr.find(p[i + 1]));
      if (sr.size()) {
        l = std::min(l, *sr.begin() - p[i]);
        r = std::max(r, *--sr.end() - p[i]);
      }
      if (sl.size()) {
        l = std::min(l, p[i + 1] - *--sl.end());
        r = std::max(r, p[i + 1] - *sl.begin());
      }
      sl.emplace(p[i + 1]);
    }
    std::set<i64> st;
    for (i64 i = l; i <= r; ++i) {
      st.emplace(i);
    }
    std::multiset<i64>().swap(sl);
    sl.emplace(0);
    l = INF, r = -INF;
    for (int i = 0; i < pos; ++i) {
      sl.emplace(p[i + 1]);
    }
    for (int i = pos + 1; i < n; ++i) {
      sr.emplace(p[i + 1]);
    }
    if (sr.size()) {
      i64 ppos = p[pos];
      if (sl.size()) {
        ppos = std::max(ppos, *--sl.end());
      }
      l = std::min(l, *sr.begin() - ppos);
      ppos = p[pos];
      if (sl.size()) {
        ppos = std::min(ppos, *sl.begin());
      }
      r = std::max(r, *--sr.end() - ppos);
    }
    if (sl.size()) {
      i64 ppos = p[pos + 1];
      if (sr.size()) {
        ppos = std::min(ppos, *sr.begin());
      }
      l = std::min(l, ppos - *--sl.end());
      ppos = p[pos + 1];
      if (sr.size()) {
        ppos = std::max(ppos, *--sr.end());
      }
      r = std::max(r, ppos - *sl.begin());
    }
    for (i64 i = l; i <= r; ++i) {
      st.emplace(i);
    }
    st.emplace(0);
    std::cout << st.size() << '\n';
    for (auto u: st) {
      std::cout << u << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
