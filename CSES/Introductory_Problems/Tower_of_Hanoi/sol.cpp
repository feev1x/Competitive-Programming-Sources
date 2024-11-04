/**
 *    author:  feev1x
 *    created: 04.11.2024 21:24:41
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int n; scanf("%d", &n);
  vector<pair<int, int>> ans;
  function<void(int, int, int, int)> Move = [&](int i, int from, int to, int sm) {
    if (i == 1) {
      ans.emplace_back(from, to);
      return;
    }
    Move(i - 1, from, sm, to);
    ans.emplace_back(from, to);
    Move(i - 1, sm, to, from);
  };
  Move(n, 1, 3, 2);
  printf("%zu\n", ans.size());
  for (auto [from, to]: ans) {
    printf("%d %d\n", from, to);
  }
  return 0;
}
