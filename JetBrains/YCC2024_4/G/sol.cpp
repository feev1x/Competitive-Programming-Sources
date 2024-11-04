/**
 *    author:  feev1x
 *    created: 29.10.2024 21:06:14
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
  int n, m, p; scanf("%d%d%d", &n, &m, &p);
  char s[n + 1]; scanf("%s", s);
  char op[m + 1]; scanf("%s", op);
  stack<int> st;
  vector<int> pr(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.emplace(i);
    } else {
      pr[i] = st.top();
      pr[st.top()] = i;
      st.pop();
    }
  }
  for (int 
  return 0;
}
