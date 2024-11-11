/**
 *    author:  feev1x
 *    created: 10.11.2024 11:45:32
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
  stack<int> stk;
  multiset<int> st;
  while (n--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int x; scanf("%d", &x);
      st.emplace(x);
      stk.emplace(x);
    } else if (type == 2) {
      st.erase(st.find(stk.top()));
      stk.pop();
    } else {
      printf("%d\n", *st.begin());
    }
  }
  return 0;
}
