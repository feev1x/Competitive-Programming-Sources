/**
 *    author:  feev1x
 *    created: 24.11.2024 19:45:03
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int k, s, t; scanf("%d%d%d", &k, &s, &t);
  std::vector<i64> b;
  auto Mex = [](std::vector<i64> a) {
    int n = a.size();
    for (int i = 0, j = 0; j < n; ++i) {
      while (j < n && a[j] < i) {
        j++;
      }
      if (j >= n || a[j] > i) {
        return i;
      }
    }
    return n;
  };
  for (int i = 0; i < k; ++i) {
    int n, c; scanf("%d%d", &n, &c);
    std::vector<i64> a(n);
    for (auto &u: a) {
      scanf("%lld", &u);
    }
    std::sort(a.begin(), a.end());
    b.emplace_back(Mex(a));
  }
  std::sort(b.begin(), b.end());
  printf("%d\n", Mex(b));
  return 0;
}
