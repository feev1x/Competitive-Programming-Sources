#include <bits/stdc++.h>
  
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> p(n + 1), pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
    pos[p[i]] = i;
  }
  std::set<std::pair<int, int>> st;
  std::vector<std::vector<int>> g(n + 1), out(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (i - k > 0) st.erase({p[i - k], i - k});
    st.emplace(p[i], i);
    auto it = st.lower_bound({p[i], i});
    if (it != st.begin()) {
      --it;
      {
        g[i].emplace_back(it->second);
        out[it->second].emplace_back(i);
      }
      ++it;
    }
    if (++it != st.end()) g[it->second].emplace_back(i), out[i].emplace_back(it->second);
  }
  std::vector<int> res, ans(n + 1);
  {
    std::set<std::pair<int, int>> st;
    for (int i = 1; i <= n; ++i) st.emplace((int)g[i].size(), i);
    while (st.size()) {
      int v = st.begin()->second;
      st.erase(st.begin());
      assert(!g[v].size());
      res.emplace_back(v);
      for (auto to: out[v]) {
        st.erase({(int)g[to].size(), to});
        g[to].pop_back();
        st.emplace((int)g[to].size(), to);
      }
    }
  }
  for (int i = 0; i < n; ++i) ans[res[i]] = i + 1;
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << '\n';
  return 0;
}
