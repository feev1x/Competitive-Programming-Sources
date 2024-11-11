/**
 *    author:  feev1x
 *    created: 08.11.2024 17:25:52
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
  priority_queue<int> pq;
  while (n--) {
    int type; scanf("%d", &type);
    if (type == 0) {
      int u; scanf("%d", &u);
      pq.emplace(u);
    } else {
      printf("%d\n", pq.top());
      pq.pop();
    }
  }
  return 0;
}
