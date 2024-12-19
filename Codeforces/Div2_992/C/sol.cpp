/**
 *    author:  feev1x
 *    created: 08.12.2024 20:53:53
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {  
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; i64 k; scanf("%d%lld", &n, &k);
    if (n < 41 && (1ll << n - 1) < k) {
      printf("-1\n");
      continue;
    }
    k--;
    std::vector<int> p;
    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (n - i - 1 >= 41) {
        p.emplace_back(i);
        used[i] = true;
      } else {
        if (!(k >> (n - i - 1) & 1)) {
          p.emplace_back(i);
          used[i] = true;
        } else {
          k ^= 1ll << (n - i - 1);
        }
      }
    }
    for (int i = n; i >= 1; --i) {
      if (!used[i]) {
        p.emplace_back(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", p[i], " \n"[i + 1 == n]);
    }
  }
  return 0;
}
