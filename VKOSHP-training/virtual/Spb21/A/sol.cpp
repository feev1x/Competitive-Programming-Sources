/**
 *    author:  feev1x
 *    created: 14.11.2024 09:00:54
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  if (k > std::min(n, m)) {
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  for (int i = 0; i < n; ++i) {
    std::string s;
    for (int j = 0; j < m; ++j) {
      if (i == j && k) {
        s += "*";
        k--;
      } else {
        s += ".";
      }
    }
    printf("%s\n", s.c_str());
  }
  return 0;
}
