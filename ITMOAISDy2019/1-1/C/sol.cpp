/**
 *    author:  feev1x
 *    created: 08.11.2024 17:20:37
**/
#include "bits/stdc++.h"
using namespace std;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

signed main() {
  int n; scanf("%d", &n);
  vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  ll res = 0;
  ordered_set st;
  for (int i = 0; i < n; ++i) {
    res += int(st.size()) - st.order_of_key(a[i]);
    st.insert(a[i]);
  }
  printf("%lld\n", res);
  return 0;
}
