/**
 *    author:  feev1x
 *    created: 24.11.2024 10:03:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  int sum = 0;
  for (auto &u: a) {
    scanf("%d", &u);
    sum += u;
  }
  for (int i = 0; i < n; ++i) {
    if ((sum - a[i]) % k == 0) {
      printf("Yes\n");
      exit(0);
    }
  }
  printf("No\n");
  return 0;
}
