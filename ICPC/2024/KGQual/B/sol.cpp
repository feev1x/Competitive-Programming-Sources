/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int64_t nw = 0;
  int64_t res = 1e18;
  for (int i = 0; i < n; ++i) {
    int u; cin >> u;
    nw += u;
    res = min(res, min(nw, int64_t(0)));
  }
  cout << abs(res) << '\n';
}

