/**
 *    author:  feev1x
 *    created: 30.11.2024 13:01:07
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::freopen("cbarn.in", "r", stdin);
  std::freopen("cbarn.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> c(n);
  for (auto &u: c) {
    scanf("%d", &u);
  }
  int res = INF;
  for (int k = 0; k < n; ++k) {
    int cnt = 0;
    std::multiset<int> st, ch;
    for (int i = 0; i < n; ++i) {
      ch.emplace(i);
    }
    for (int i = k; ch.size(); i = (i + 1) % n) {
      if (ch.find(i) == ch.end()) {
        std::multiset<int> new_st;
        for (auto u: st) {
          new_st.emplace(u + 1);
        }
        st.swap(new_st);
        continue;
      }
      for (int j = 0; j < c[i]; ++j) {
        st.emplace(0);
      }
      if (st.empty()) {
        continue;
      }
      ch.erase(i);
      cnt += *--st.end() * *--st.end();
      st.erase(--st.end());
      std::multiset<int> new_st;
      for (auto u: st) {
        new_st.emplace(u + 1);
      }
      st.swap(new_st);
    }
    res = std::min(res, cnt);
  }
  printf("%d\n", res);
  return 0;
}
