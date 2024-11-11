/**
 *    author:  feev1x
 *    created: 10.11.2024 17:24:37
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

const int inf = 2e9 + 7;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  std::vector<int> d(n + 2, inf), ind(n + 2, -1), p(n + 2);
  d[0] = -inf;
  int res = 1;
  for (int i = 0; i < n; ++i) {
    int j = std::lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (d[j] > a[i]) {
      d[j] = a[i];
      ind[j] = i;
      p[i] = ind[j - 1];
      res = std::max(res, j);
    }
  }
  printf("%d\n", res);
  std::vector<int> lis;
  for (int v = ind[res]; v != -1; v = p[v]) {
    lis.emplace_back(a[v]);
  }
  std::reverse(lis.begin(), lis.end());
  for (int i = 0; i < res; ++i) {
    printf("%d%c", lis[i], " \n"[i == res - 1]);
  }
  return 0;
}
