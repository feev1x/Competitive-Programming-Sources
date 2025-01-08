/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m; cin >> m;
  vector<int> d;
  while (m > 0) {
    d.emplace_back(m % 3);
    m /= 3;
  }
  vector<int> ans;
  for (int i = 0; i < d.size(); ++i) {
    for (int j = 0; j < d[i]; ++j) {
      ans.emplace_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto u: ans) cout << u << ' ';
  cout << '\n';
}

