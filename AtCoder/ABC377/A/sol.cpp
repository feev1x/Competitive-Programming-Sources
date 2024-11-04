/**
 *    author:  feev1x
 *    created: 26.10.2024 18:00:24
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
  string s; cin >> s;
  sort(s.begin(), s.end());
  if (s == "ABC") cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
