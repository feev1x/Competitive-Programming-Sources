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
    int n; cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v; cin >> u >> v;
      d[u]++;
      d[v]++;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (d[i] == 1) res += 3;
      else res += 2;
    }
    cout << res << '\n';
  }
}

