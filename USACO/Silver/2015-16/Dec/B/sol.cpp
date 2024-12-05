/**
 *    author:  feev1x
 *    created: 29.11.2024 22:52:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("highcard.in", "r", stdin);
  std::freopen("highcard.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<bool> used(2 * n + 1);
  for (int i = 0; i < n; ++i) {
    int u; scanf("%d", &u);
    used[u] = true;
  }
  int cnt = 0, q = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (used[i]) {
      q++;
    } else if (q) {
      q--;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
