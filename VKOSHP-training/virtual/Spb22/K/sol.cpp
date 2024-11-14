/**
 *    author:  feev1x
 *    created: 23.10.2024 14:28:49
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
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  int64_t k = 1e18;
  for (int i = 0; i < n - 1; i += 2) {
    int64_t mx = min(s[i].size(), s[i + 1].size());
    for (int j = 0; j < min(s[i].size(), s[i + 1].size()); ++j) {
      if (s[i][j] != s[i + 1][j]) {
        mx = j;
        break;
      }
    }
    k = min(k, mx);
  }
  cout << k << '\n';
  return 0;
}
