/**
 *    author:  feev1x
 *    created: 08.12.2024 21:12:00
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  int cnt = 0, mx = 0;
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 1);
  for (int i = 0; i < n; ++i) {
    mx += (i + 1) * (n - i);
  }
  do {
    int sum = 0;
    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        int mn = n + 1;
        for (int i = l; i <= r; ++i) {
          mn = std::min(mn, a[i]);
        }
        sum += mn;
      }
    }
    assert(sum <= mx);
    if (sum == mx) {
      for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
      }
      printf("\n");
    }
  } while (std::next_permutation(a.begin(), a.end()));
  return 0;
}
