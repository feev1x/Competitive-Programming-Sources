/**
 *    author:  feev1x
 *    created: 10.11.2024 11:51:46
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
  int u;
  int cnt = 0;
  stack<int> stk, stk1;
  bool flag = false;
  while (scanf(" %d", &u) == 1) {
    if (stk.size() < 2) {
      if (!stk.empty()) {
        stk1.emplace(stk.top());
      }
      stk.emplace(u);
      flag = false;
      continue;
    }
    if (u != stk.top() && flag) {
      int v = stk.top();
      while (!stk.empty() && stk.top() == v) {
        stk.pop();
        cnt++;
        if (!stk1.empty()) {
          stk1.pop();
        }
      }
      flag = false;
    }
    if (u == stk.top() && u == stk1.top()) {
      flag = true;
      stk.emplace(u);
      stk1.emplace(u);
    } else {
      stk1.emplace(stk.top());
      stk.emplace(u);
      flag = false;
    }
    debug(stk);
  }
  if (flag) {
    int v = stk.top();
    while (!stk.empty() && stk.top() == v) {
      stk.pop();
      cnt++;
      if (!stk1.empty()) {
        stk1.pop();
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
