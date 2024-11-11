/**
 *    author:  feev1x
 *    created: 10.11.2024 12:21:09
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
  deque<int> dq;
  vector<int> order(size_t(1e5 + 1));
  while (n--) {
    int type; scanf("%d", &type);
    switch(type) {
      case 1:
        int id; scanf("%d", &id);
        assert(!order[id]);
        order[id] = (dq.empty() ? 0 : order[dq.back()]) + 1;
        dq.emplace_back(id);
        break;
      case 2:
        dq.pop_front();
        break;
      case 3:
        dq.pop_back();
        break;
      case 4:
        int q; scanf("%d", &q);
        assert(order[q] > 0 && order[dq.front()] > 0);
        debug(order[q], order[dq.front()]);
        printf("%d\n", order[q] - order[dq.front()]);
        break;
      default:
        printf("%d\n", dq.front());
        break;
    };
  }
  return 0;
}
