/**
 *    author:  feev1x
 *    created: 07.12.2024 18:07:40
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15;

char S[MXSZ];

inline int dis(int x1, int y1, int x2, int y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main() {
  int h, w, d; scanf("%d%d%d", &h, &w, &d);
  std::vector<std::string> s(h);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  int res = 2;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') {
        continue;
      }
      for (int k = 0; k < h; ++k) {
        for (int l = 0; l < w; ++l) {
          if (k == i && l == j || s[k][l] == '#') {
            continue;
          }
          int ans = 0;
          for (int n = 0; n < h; ++n) {
            for (int m = 0; m < w; ++m) {
              if (s[n][m] == '#') {
                continue;
              }
              if (dis(n, m, i, j) <= d || dis(n, m, k, l) <= d) {
                ans++;
              }
            }
          }
          res = std::max(res, ans);
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
