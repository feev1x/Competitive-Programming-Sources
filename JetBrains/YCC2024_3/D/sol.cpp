/**
 *    author:  feev1x
 *    created: 29.10.2024 14:14:35
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
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  a--, b--;
  if (s[a] == s[b]) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
  }
  return 0;
}
