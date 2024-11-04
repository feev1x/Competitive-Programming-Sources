/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    vector<int> v(3);
    for (auto &u: v) cin >> u;
    sort(v.begin(), v.end());
    if (v[2] <= v[1] + v[0]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

