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
  vector<int> h(n);
  for (auto &u: h) cin >> u;
  int64_t l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int64_t md = l + r >> 1;
    int64_t cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (abs(h[i] - h[i - 1]) > md) {
        cnt++;
      }
    }
    if (cnt == m) {
      ans = md;
      r = md - 1;
    } else if (cnt > m) {
      l = md + 1;      
    } else {
      r = md - 1;
    }
  }
  cout << ans << '\n';
}

