/**
 *    author:  feev1x
 *    created: 10.11.2024 12:37:01
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
  deque<int> l, r;
  auto Stabilize = [&]() {
    while (r.size() > l.size()) {
      l.emplace_back(r.front());
      r.pop_front();
    }
  };
  while (n--) {
    char c; scanf(" %c", &c);
    debug(c);
    if (c == '+') {
      int i; scanf("%d", &i);
      r.emplace_back(i);
    } else if (c == '*') {
      int i; scanf("%d", &i);
      r.emplace_front(i);
    } else {
      printf("%d\n", l.front());
      l.pop_front();
    }
    Stabilize();
  }
  return 0;
}
