/**
 *    author:  feev1x
 *    created: 28.11.2024 19:33:20
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("superbull.in", "r", stdin);
  std::freopen("superbull.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  std::vector<int> d(n);
  std::vector<bool> used(n);
  i64 res = 0;
  int _ = n;
  while (_--) {
    int v = -1;
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      if (v == -1 || d[i] > d[v]) {
        v = i;
      }
    }
    assert(v != -1);
    res += d[v];
    used[v] = true;
    for (int i = 0; i < n; ++i) {
      d[i] = std::max(d[i], a[i] ^ a[v]);
    }
  }
  printf("%lld\n", res);
  return 0;
}
