/**
 *    author:  feev1x
 *    created: 13.11.2024 08:25:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<int> h(n);
  for (auto &u: h) {
    scanf("%d", &u);
  }
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int md = l + r >> 1;
    int cnt = 1;
    for (int i = 0; i + 1 < n; ++i) {
      if (abs(h[i] - h[i + 1]) > md) {
        cnt++;
      }
    }
    if (cnt == m) {
      ans = md;
      r = md - 1;
    } else if (cnt > m) {
      l = md + 1;
    } else {
      r = md - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
