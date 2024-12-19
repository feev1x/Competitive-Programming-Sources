/**
 *    author:  feev1x
 *    created: 05.12.2024 20:37:50
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; scanf("%d%d", &n, &m);
    int mx = 0, cnt = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      scanf("%s", S);
      std::string s = S;
      if (flag && (int)s.size() + mx <= m) {
        mx += (int)s.size();
        cnt++;
      } else {
        flag = false;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
