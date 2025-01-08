/**
 *    author:  feev1x
 *    created: 04.01.2025 20:39:57
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &u: a) {
      std::cin >> u;
    }
    std::sort(a.begin(), a.end());
    std::multiset<int> st;
    int sz = 0;
    for (int i = 0; i < n; ++i) {
      if (!i || a[i] != a[i - 1]) {
        if (sz) {
          st.emplace(sz);
          sz = 0;
        }
        sz++;
      } else {
        sz++;
      }
    }
    if (sz) {
      st.emplace(sz);
      sz = 0;
    }
    while (st.size() > 1 && *st.begin() <= k) {
      int nm = *st.begin();
      st.erase(st.begin());
      k -= nm;
      nm += *--st.end();
      st.erase(--st.end());
      st.emplace(nm);
    }
    std::cout << st.size() << '\n';
  }
  return 0;
}
