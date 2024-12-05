/**
 *    author:  feev1x
 *    created: 30.11.2024 18:30:13
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, x; scanf("%d%d", &n, &x);
  std::vector<double> p(n);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    int u; scanf("%d", &u);
    p[i] = (double)u / (double)100;
    res += p[i];
  }
  res = x / res;
  printf("%.7lf\n", res);
  return 0;
}
