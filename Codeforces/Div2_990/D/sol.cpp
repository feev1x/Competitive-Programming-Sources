/**
 *    author:  feev1x
 *    created: 03.12.2024 14:08:24
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e15;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::deque<i64> dq;
    std::multiset<i64> st;
    for (int i = 0; i < n; ++i) {
      i64 u; scanf("%lld", &u);
      dq.emplace_back(u);
      st.emplace(u);
    }
    std::vector<i64> b;
    std::multiset<i64> tmp;
    while (b.size() < n) {
      if (dq.empty()) {
        while (tmp.size()) {
          dq.emplace_back(*tmp.begin());
          tmp.erase(tmp.begin());
        }
      }
      if (*st.begin() == dq.front()) {
        st.erase(st.begin());
        b.emplace_back(dq.front());
      } else {
        st.erase(st.find(dq.front()));
        st.emplace(dq.front() + 1);
        tmp.emplace(dq.front() + 1);
      }
      dq.pop_front();
    }
    for (auto u: b) {
      printf("%lld ", u);
    }
    printf("\n");
  }
  return 0;
}
