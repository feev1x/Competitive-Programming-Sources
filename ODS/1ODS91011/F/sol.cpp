/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int64_t> a(n), c(m);
  vector<int> b(m);
  set<pair<int64_t, int>> st;
  auto add = [&](int64_t u, int q) {
    if (st.upper_bound({u, 0})->first == u) {
      auto it = st.upper_bound({u, 0});
      int se = it->second;
      st.erase(it);
      st.emplace(u, se + q);
    } else {
      st.emplace(u, q);
    }
  };
  for (auto &u: a) {
    cin >> u;
    add(u, 1);
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> c[i];
    int cnt = 0, sum = 0;
    auto it = st.begin();
    while (sum < b[i] && it != st.end()) {
      if (it->first >= c[i]) break;
      if (b[i] <= sum + it->second) {
        int val1 = it->first;
        int val2 = it->second;
        st.erase(it);
        if (val2 > b[i] - sum) {
          st.emplace(val1, val2 - (b[i] - sum));
        }
        sum = b[i];
        break;
      }
      sum += it->second;
      cnt++;
      it++;
    }
    while (cnt--) {
      st.erase(st.begin());
    }
    add(c[i], sum);
  }
  int64_t res = 0;
  for (auto [val, k]: st) {
    res += val * k;
  }
  cout << res << '\n';
}

