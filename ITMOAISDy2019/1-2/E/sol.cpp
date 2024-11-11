/**
 *    author:  feev1x
 *    created: 10.11.2024 12:45:31
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
  char *S; scanf("%m[^\n]", &S); 
  string s = S;
  free(S);
  stack<int> stk;
  for (int i = 0; i < s.size(); i += 2) {
    int u, v;
    switch(s[i]) {
      case '+':
        u = stk.top();
        stk.pop();
        v = stk.top();
        stk.pop();
        stk.emplace(u + v);
        break;
      case '-':
        u = stk.top();
        stk.pop();
        v = stk.top();
        stk.pop();
        stk.emplace(v - u);
        break;
      case '*':
        u = stk.top();
        stk.pop();
        v = stk.top();
        stk.pop();
        stk.emplace(u * v);
        break;
      default:
        stk.emplace(s[i] - '0');
        break;
    };
    debug(stk);
  }
  printf("%d\n", stk.top());
  return 0;
}
