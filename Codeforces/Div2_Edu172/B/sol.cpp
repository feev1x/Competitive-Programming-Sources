/**
 *    author:  feev1x
 *    created: 02.12.2024 20:49:31
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      cnt[u]++;
    }
    std::vector<int> cc(n + 1);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      cc[cnt[i]]++;
      if (cnt[i] > 1) {
        res++;
      }
    }
    res += ((cc[1] + 1) / 2) * 2;
    printf("%d\n", res);
  }
  return 0;
}
