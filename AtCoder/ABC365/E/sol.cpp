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
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  vector<vector<int64_t>> rn(28);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 28; ++j) {
      if (a[i] & (1 << j)) {
        rn[j].emplace_back(i);
      }
    }  
  }
  int64_t res = 0;
  for (int64_t j = 0; j < 28; ++j) {
    if (rn[j].size() == 0) {
      continue;
    }
    if (rn[j].size() == 1) {
      int64_t l = rn[j][0], r = n - rn[j][0] - 1;
      res += (1ll << j) * (l * r + l + r);
    } else {
      int64_t l = 0, r;
      for (int i = 0; i < rn[j].size(); i += 2) {
        if (i == 0) {
          l += rn[j][i];
          r = rn[j][i + 1] - rn[j][i] - 1;
        } else if (i + 1 == rn[j].size()) {
          r = n - rn[j][i] - 1;
          l += rn[j][i] - rn[j][i - 1] - 1;
        } else {
          r = rn[j][i + 1] - rn[j][i] - 1;
          l += rn[j][i] - rn[j][i - 1] - 1;
        }
        res += (1ll << j) * (l * r + l + r);
        l++;
      }
      l = 0;
      for (int i = 1; i < rn[j].size(); i += 2) {
        if (i + 1 == rn[j].size()) {
          r = n - rn[j][i] - 1;
          l += rn[j][i] - rn[j][i - 1] - 1;
        } else {
          r = rn[j][i + 1] - rn[j][i] - 1;
          l += rn[j][i] - rn[j][i - 1] - 1;
        }
        res += (1ll << j) * (l * r + l + r);
        l++;
      }
    }
  }
  cout << res << '\n';
}

