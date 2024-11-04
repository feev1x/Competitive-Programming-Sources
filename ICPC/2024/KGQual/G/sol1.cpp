/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  int64_t w; cin >> w;
  int n; cin >> n;
  vector<tuple<int64_t, int64_t, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<1>(p[i]) >> get<0>(p[i]); 
  }
  sort(p.begin(), p.end());
  int64_t cnt = 0;
  for (auto [u, v, w]: p) {
    if (u > cnt) break;
    cnt += v;
  }
  if (cnt < w) {
    cout << -1 << '\n';
    return 0;
  }
  cout << "HEHEH";
}
