/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 2));
    for (int i = 0; i < min(n, m); ++i) {
      a[i][i] = 3;
    }
    for (int i = min(n, m); i < max(n, m); ++i) {
      if (n > m)
        a[i][0] = 3;
      else
        a[0][i] = 3;
    }
    for (auto u: a) {
      for (auto v: u) {
        cout << v << ' ';
      }
      cout << '\n';
    }
  }
}

