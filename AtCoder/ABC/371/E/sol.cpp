/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  map<int, vector<int>> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]].emplace_back(i);
  }
  int64_t res = 0;
  for (auto [key, val]: m) {
    int64_t pl = 0;
    if (val.size() == 1) {
      int l = val[0], r = n - val[0] - 1;
      pl += l + r + 1 + l * r;
    } else
    for (int i = 0; i < val.size(); ++i) {
      int l = 0, r = n - val[i] - 1;
      if (i == 0) {
        l = val[i];
      } else {
        l = val[i] - val[i - 1] - 1;
      }
      pl += l + r + 1 + l * r;
    }
    res += pl;
  }
  cout << res << '\n';
}

