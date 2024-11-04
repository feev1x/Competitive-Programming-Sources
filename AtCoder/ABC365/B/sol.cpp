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
  int mx = 0, mx2 = 0;
  int pos = -1, pos2 = -1;
  for (int i = 0; i < n; ++i) {
    int u; cin >> u;
    if (u >= mx) {
      mx2 = mx;
      pos2 = pos;
      pos = i;
      mx = u;
    } else if (u > mx2) {
      mx2 = u;
      pos2 = i;
    }
  }
  cout << pos2 + 1 << '\n';
}

