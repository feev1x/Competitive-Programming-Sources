/**
 *    author:  feev1x
 *    created: 18.11.2024 09:01:57
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, q, x; scanf("%d%d%d", &n, &q, &x);
  std::vector<long double> tp(q + 1);
  for (int i = 0; i < n; ++i) {
    int t, m, k; scanf("%d%d%d", &t, &m, &k);
    tp[t] += m * ((long double)k / 100.);
  }
  std::sort(tp.begin() + 1, tp.end(), std::greater<>());
  int cnt = 0;
  long double sum = 0;
  for (int i = 1; sum < x && i <= q; ++i) {
    sum += tp[i];
    cnt++;
  }
  if (sum < x) {
    printf("-1\n");
  } else {
    printf("%d\n", cnt);
  }
  return 0;
}
