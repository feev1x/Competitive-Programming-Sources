/**
 *    author:  feev1x
 *    created: 04.12.2024 13:43:52
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 54;
using smat = std::vector<std::string>;

char S[MXSZ];

int main() {
  std::freopen("cownomics.in", "r", stdin);
  std::freopen("cownomics.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  smat sp(n);
  smat pl(n);
  for (auto &u: sp) {
    scanf("%s", S);
    u = S;
  }
  for (auto &u: pl) {
    scanf("%s", S);
    u = S;
  }
  auto Fun = [](smat s, int i, int p1, int p2, int p3) {
    int str = 0;
    str += s[i][p1];
    str += s[i][p2];
    str += s[i][p3];
    return str;
  };
  int cnt{};
  std::vector<bool> mp(2000001);
  for (int p1 = 0; p1 < m; ++p1) {
    for (int p2 = p1 + 1; p2 < m; ++p2) {
      for (int p3 = p2 + 1; p3 < m; ++p3) {
        for (int i = 0; i < n; ++i) {
          mp[Fun(sp, i, p1, p2, p3)] = true;
        }
        cnt++;
        for (int i = 0; i < n; ++i) {
          if (mp[Fun(pl, i, p1, p2, p3)]) {
            cnt--;
            break;
          }
        }
        for (int i = 0; i < n; ++i) {
          mp[Fun(sp, i, p1, p2, p3)] = false;
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
