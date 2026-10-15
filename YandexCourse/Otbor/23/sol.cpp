#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void solve() {
  int n, s; std::cin >> n >> s;
  std::vector<std::pair<int, int>> pr(n);
  for (int i = 0; i < n; ++i) std::cin >> pr[i].first;
  for (int i = 0; i < n; ++i) std::cin >> pr[i].second;
  std::sort(pr.begin(), pr.end());
  std::multiset<int> st;
  int64_t res = INF, sum = 0;
  for (int i = 0; i < n; ++i) {
    if (st.size() < s) {
      st.emplace(pr[i].second);
      sum += pr[i].second;
    } else if (*st.rbegin() > pr[i].second) {
      sum -= *st.rbegin();
      st.erase(--st.end());
      st.emplace(pr[i].second);
      sum += pr[i].second;
    }
    if (st.size() == s) res = std::min(res, sum * pr[i].first);
  }
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
