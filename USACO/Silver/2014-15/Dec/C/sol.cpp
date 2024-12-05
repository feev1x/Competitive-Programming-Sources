/**
 *    author:  feev1x
 *    created: 23.11.2024 14:02:51
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("cowjog.in", "r", stdin);
  std::freopen("cowjog.out", "w", stdout);
  int n, t; scanf("%d%d", &n, &t);
  std::vector<int> pos(n), v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &pos[i], &v[i]);
  }
  int cnt = 1;
  int nwpos = -1, nwv = -1;
  for (int i = n - 1; i > 0; --i) {
    if (nwpos == -1) {
      nwpos = pos[i], nwv = v[i];
    }
    if (v[i - 1] <= nwv) {
      cnt++;
      nwpos = nwv = -1;
      continue;
    }
    if ((nwpos - pos[i - 1]) / (double)(v[i - 1] - nwv) > t) {
      cnt++;
      nwpos = nwv = -1;
      continue;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
