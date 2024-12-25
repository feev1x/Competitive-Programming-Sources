/**
 *    author:  feev1x
 *    created: 22.12.2024 14:04:47
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  std::multiset<int> st;
  for (auto &u: a) {
    std::cin >> u;
    st.emplace(u);
  }
  int cnt = 0;
  while (!st.empty()) {
    auto it = st.begin();
    int ls;
    while (it != st.end()) {
      ls = *it;
      st.erase(it);
      it = st.upper_bound(ls + k);
    }
    cnt++;
  }
  std::cout << cnt << '\n';
  return 0;
}
