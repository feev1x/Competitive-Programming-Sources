/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int64_t m; cin >> n >> m;
  vector<int64_t> a(n);
  int64_t sum = 0;
  for (auto &u: a) cin >> u, sum += u;
  if (sum <= m) {
    cout << "infinite\n";
    return 0;
  }
  int64_t l = 0, r = m, ans = 0;
  while (l <= r) {
    int64_t md = l + r >> 1;
    sum = 0;
    for (auto u: a) {
      sum += min(md, u);
    }
    if (sum <= m) {
      l = md + 1;
      ans = md;
    } else {
      r = md - 1;
    }
  }
  cout << ans << '\n';
}

