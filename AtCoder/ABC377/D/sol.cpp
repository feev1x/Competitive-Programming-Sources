/**
 *    author:  feev1x
 *    created: 26.10.2024 18:10:06
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n, m; cin >> n >> m;
  int64_t res = 0;
  map<int, vector<int>> mp;
  multiset<int> st;
  for (int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    st.emplace(r);
    mp[l].emplace_back(r);
  }
  int r = 0, ls = 0;
  for (int l = 1; l <= m; ++l) {
    if (st.empty()) r = m;
    else r = *st.begin() - 1;
    res += (r - l + 1);
    for (auto u: mp[l]) {
      st.erase(st.find(u));
    }
  }
  cout << res << '\n';
  return 0;
}
