/**
 *    author:  feev1x
 *    created: 02.12.2024 19:25:39
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("haybales.in", "r", stdin);
  std::freopen("haybales.out", "w", stdout);
  int n, q; scanf("%d%d", &n, &q);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  std::sort(a.begin(), a.end());
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    l = std::lower_bound(a.begin(), a.end(), l) - a.begin();
    r = std::upper_bound(a.begin(), a.end(), r) - a.begin();
    printf("%d\n", r - l);
  }
  return 0;
}
