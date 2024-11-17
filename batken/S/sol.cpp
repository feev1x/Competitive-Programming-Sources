/**
 *    author:  feev1x
 *    created: 16.11.2024 12:04:09
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      pos[p[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == i || p[p[i]] == i) continue;
      int temp = p[p[i]], tmp = p[pos[i]];
      cnt++;
      std::swap(p[p[i]], p[pos[i]]);
      std::swap(pos[temp], pos[tmp]);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
