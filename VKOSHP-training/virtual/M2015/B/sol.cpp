/**
 *    author:  feev1x
 *    created: 13.11.2024 09:44:11
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("b.in", "r", stdin);
  std::freopen("b.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> s(n);
  for (auto &u: s) {
    scanf("%d", &u);
  }
  int l = -1, r = -1, res = 0;
  std::vector<std::pair<int, int>> rng;
  for (int i = 1; i + 1 < n; ++i) {
    if (s[i - 1] == 1 && s[i + 1] == 1 && s[i] == 0) {
      if (l == -1) {
        l = i;
        r = i;
      } else {
        r = i;
      }
    } else if (s[i - 1] == 0 && s[i + 1] == 0 && s[i] == 1) {
      if (l == -1) {
        l = i;
        r = i;
      } else {
        r = i;
      }
    } else {
      if (l != -1) {
        rng.emplace_back(l, r);
        res = std::max(res, (r - l + 2) / 2);
        l = -1;
        r = -1;
      }
    }
  }
  if (l != -1) {
    rng.emplace_back(l, r);
    res = std::max(res, (r - l + 2) / 2);
  }
  printf("%d\n", res);
  for (auto [l, r]: rng) {
    if ((r - l + 1) & 1) {
      for (int i = l; i <= r; ++i) {
        s[i] = s[l - 1];
      }
    } else {
      for (int i = l; i <= (l + (r - l + 1) / 2 - 1); ++i) {
        s[i] = s[l - 1];
      }
      for (int i = l + (r - l + 1) / 2; i <= r; ++i) {
        s[i] = s[r + 1];
      }
    }
  }
  for (auto u: s) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
