/**
 *    author:  feev1x
 *    created: 02.11.2024 18:01:01
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
  vector<int> a(4);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  sort(a.begin(), a.end());
  int cnt = 0;
  if (a[0] == a[1]) cnt++;
  else if (a[1] == a[2]) cnt++;
  else if (a[2] == a[3]) cnt++;
  if (a[0] == a[3] || a[0] == a[1] && a[2] == a[3]) cnt = 2;
  printf("%d\n", cnt);
  return 0;
}
