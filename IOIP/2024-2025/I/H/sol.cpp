/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

int64_t dis(int64_t x, int64_t y, int64_t x1, int64_t y1) {
  return abs(x - x1) + abs(y - y1);
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int64_t> x(3), y(3);
  for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  cout << (x.back() - x.front()) + (y.back() - y.front()) << '\n';
}

