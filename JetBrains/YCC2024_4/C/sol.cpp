/**
 *    author:  feev1x
 *    created: 29.10.2024 20:13:30
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main() {
  int n, k; scanf("%d%d", &n, &k);
  char s[n + 1]; scanf("%s", s);
  stack<int> st;
  string ans;
  int cs = 0, ce = 0, nd = k / 2;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')') {
      ans += ")";
      ce++;
    } else {
      if (cs >= nd) continue;
      ans += "(";
      cs++;
    }
    if (ans.size() == k) break;
  }
  printf("%s\n", ans.c_str());
  return 0;
}
