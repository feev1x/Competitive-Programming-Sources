/**
 *    author:  feev1x
 *    created: 13.11.2024 08:30:28
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  int nw = 0;
  for (int i = 0; i < n; ++i) {
    int r, g, d; scanf("%d%d%d", &r, &g, &d);
    nw += a[i];
    int nxg = (nw + d) % (r + g);
    std::cerr << nxg << ' ' << nw << '\n';
    if (nxg >= g) {
      nw += (r + g) - nxg;
    }
  }
  printf("%d\n", nw);
  return 0;
}
