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
  vector<int> a(n), cn(100001);
  int res = 0, mx = 0;
  for (auto &u: a) cin >> u, mx = max(u, mx);
  for (int i = 2; i <= mx; ++i) {
    int vl = i, cnt = 0;
    for (int j = 2; j <= vl; ++j) {
      while (vl % j == 0) {
        vl /= j;
        cnt++;
      }
    }
    cn[i] = cnt;
  }
  for (int i = 0; i < n; ++i) {
    res ^= cn[a[i]];
  }
  if (res == 0) cout << "Bruno\n";
  else cout << "Anna\n";
}

