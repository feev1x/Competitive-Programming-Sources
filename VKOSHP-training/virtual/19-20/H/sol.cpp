/**
 *    author:  feev1x
 *    created: 25.10.2024 09:17:30
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s;
  int m; cin >> m;
  vector<string> a(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      int ac = 0, wa = 0;
      int aci = 0, acj = 0, wai = 0, waj = 0;
      for (int k = 0; k < n; ++k) {
        if (a[i][k] == s[k]) {
          aci++;
        } else {
          wai++;
        }
        if (a[j][k] == s[k]) {
          acj++;
        } else {
          waj++;
        }
      }
      for (int k = 0; k < n; ++k) {
        if (a[i][k] == a[j][k]) {
          if (a[i][k] == s[k]) {
            ac++;
          } else {
            wa++;
          }
        }
      }
      if (wai / 2 < wa && waj / 2 < wa) {
        if (aci / 2 < ac && acj / 2 < ac) {
          ans.emplace_back(i, j);
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto [u, v]: ans) {
    cout << u << ' ' << v << '\n';
  }
  return 0;
}
