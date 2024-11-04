/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t l = 0, ls, d = 0;
  int n; cin >> n;
  int64_t res = 0;
  cin >> ls;
  for (int i = 1; i < n; ++i) {
    int u; cin >> u;
    if (d != u - ls) {
      int64_t r = i;
      res += (r - l) * (r - l + 1) / 2;
      res -= (r - l);
      l = i - 1;
      d = u - ls;
    }
    ls = u;
  }
  int64_t r = n;
  res += (r - l) * (r - l + 1) / 2;
  res -= (r - l);
  cout << res + n << '\n';
}

