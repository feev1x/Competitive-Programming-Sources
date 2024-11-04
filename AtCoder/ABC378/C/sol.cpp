/**
 *    author:  feev1x
 *    created: 02.11.2024 18:13:45
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
  vector<int> a(n), b(n);
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    auto it = st.upper_bound({a[i], i});
    if (it == st.begin()) {
      b[i] = -1;
      printf("-1%c", " \n"[i == n - 1]);
      st.emplace(a[i], i);
      continue;
    }
    --it;
    if (it->first == a[i]) {
      b[i] = it->second + 1;
    } else {
      b[i] = -1;
    }
    st.emplace(a[i], i);
    printf("%d%c", b[i], " \n"[i == n - 1]); 
  }
  return 0;
}
