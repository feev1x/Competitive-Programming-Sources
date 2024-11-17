/**
 *    author:  feev1x
 *    created: 16.11.2024 12:11:24
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    std::set<i64> st;
    i64 sum = 0, res = 0;
    for (int i = 1; i <= n; ++i) {
      st.emplace(sum);
      sum += a[i];
      if (st.find(sum) != st.end()) {
        std::set<i64>().swap(st);
        res++;
        sum = 0;
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
