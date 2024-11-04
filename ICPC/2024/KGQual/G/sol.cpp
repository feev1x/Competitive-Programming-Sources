/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int W; cin >> W;
  int n; cin >> n;
  vector<tuple<int, int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<1>(p[i]) >> get<0>(p[i]); 
    get<2>(p[i]) = i + 1;
  }
  sort(p.begin(), p.end());
  int64_t cnt = 0;
  for (auto [u, v, w]: p) {
    if (u > cnt) break;
    cnt += v;
  }
  if (cnt < W) {
    cout << -1 << '\n';
    return 0;
  }
  set<pair<int, int>> st;
  cnt = 0;
  int nw = 0;
  vector<int> ans;
  while (nw < n && cnt < W) {
    int u = get<0>(p[nw]); 
    int v = get<1>(p[nw]); 
    int w = get<2>(p[nw]); 
    if (cnt >= u) {
      st.emplace(make_pair(v, w));
      nw++;
    } else if (cnt < W && st.size() > 0) {
      auto it = --st.end();
      cnt += it->first;
      ans.emplace_back(it->second);
      st.erase(it);
    } else {
      break;
    }
  }
  while (cnt < W && !st.empty()) {
    auto it = --st.end();
    cnt += it->first;
    ans.emplace_back(it->second);
    st.erase(it);
  }
  if (cnt < W) {
    cout << -1 << '\n';
  } else {
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
  }
}

