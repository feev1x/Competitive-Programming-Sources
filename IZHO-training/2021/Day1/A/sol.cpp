/**
 *    author:  feev1x
 *    created: 26.12.2024 09:17:12
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int s, t, n; std::cin >> n >> s >> t;
  std::vector<int> a(n);
  for (auto &u: a) {
    std::cin >> u;
  }
  a.emplace(a.begin(), 0); 
  int add = s > t ? -1 : 1;
  std::stack<std::pair<int, int>> st;
  std::vector<i64> cst(n + 1, INF);
  std::vector<int> sm(n + 1, t), sm1(n + 1);
  std::iota(sm1.begin(), sm1.end(), 0);
  std::vector<bool> used(n + 1);
  for (int i = t - add; s > t ? i <= n : i > 0; i -= add) {
    while (st.size() && st.top().first >= a[i]) {
      st.pop();
    }
    if (st.size()) {
      sm[i] = st.top().second;
    }
    st.emplace(a[i], i);
  }
  while (st.size()) {
    st.pop();
  }
  for (int i = s > t ? n : 1; s > t ? i > t : i < t; i += add) {
    while (st.size() && st.top().first >= a[i]) {
      st.pop();
    }
    if (st.size()) {
      sm1[i] = st.top().second;
    }
    st.emplace(a[i], i);
  }
  auto Dfs = [&](auto &&self, int i) {
    if (i <= 0 || i > n || i == t) {
      return 0ll;
    }
    if (used[i]) {
      return cst[i];
    }
    int j = sm[i], k = sm1[i];
    used[i] = true;
    return cst[i] = std::min(cst[i], std::min((i64)std::abs(i - j) * a[i] + self(self, j), (i64)std::abs(i - k) * a[i] + self(self, k)));
  };
  std::cout << Dfs(Dfs, s) << '\n';
  return 0;
}
