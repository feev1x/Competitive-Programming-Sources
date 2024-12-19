/**
 *    author:  feev1x
 *    created: 07.12.2024 18:02:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  int sum = 0, ls = 0;
  for (int i = 0; i < n; ++i) {
    int t, v; scanf("%d%d", &t, &v);
    int dif = t - ls;
    sum -= dif;
    if (sum < 0) {
      sum = 0;
    }
    sum += v;
    ls = t;
  }
  printf("%d\n", sum);
  return 0;
}
