/**
 *    author:  feev1x
 *    created: 04.12.2024 12:32:31
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("maxcross.in", "r", stdin);
  std::freopen("maxcross.out", "w", stdout);
  int n, k, b; scanf("%d%d%d", &n, &k, &b);
  std::vector<bool> blocked(n + 1);
  for (int i = 0; i < b; ++i) {
    int u; scanf("%d", &u);
    blocked[u] = true;
  }
  std::vector<int> pref(n + 1);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + blocked[i];
  }
  int res = b;
  for (int i = 1; i + k - 1 <= n; ++i) {
    int j = i + k - 1;
    res = std::min(res, pref[j] - pref[i - 1]);
  }
  printf("%d\n", res);
  return 0;
}
