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
    vector<int> p(n);
    for (auto &u: p) cin >> u;
    vector<int> p1 = p;
    sort(p1.begin(), p1.end());
    int k = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (p1[i] != p[i]) {
        k = p1[i] + p1[0];
        break;
      }
    }
    cout << k << '\n';
  }
}

