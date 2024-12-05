/**
 *    author:  feev1x
 *    created: 04.12.2024 13:43:52
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 54;
using mat = std::vector<std::vector<int>>;

char S[MXSZ];

int main() {
  std::freopen("cownomics.in", "r", stdin);
  std::freopen("cownomics.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  mat ap(n, std::vector(m, 0));
  mat pa(n, std::vector(m, 0));
  for (int i = 0; i < n; ++i) {
    scanf("%s", S);
    for (int j = 0; j < m; ++j) {
      switch(S[j]) {
        case 'A': ap[i][j] = 0; break;
        case 'C': ap[i][j] = 1; break;
        case 'G': ap[i][j] = 2; break;
        default: ap[i][j] = 3; break;
      };
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", S);
    for (int j = 0; j < m; ++j) {
      switch(S[j]) {
        case 'A': pa[i][j] = 0; break;
        case 'C': pa[i][j] = 1; break;
        case 'G': pa[i][j] = 2; break;
        default: pa[i][j] = 3; break;
      };
    }
  }
  std::vector<bool> mp(64);
  auto Check = [&](const int &p1, const int &p2, const int &p3) {
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      mp[ap[i][p1] * 16 + ap[i][p2] * 4 + ap[i][p3]] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (mp[pa[i][p1] * 16 + pa[i][p2] * 4 + pa[i][p3]]) {
        flag = false;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      mp[ap[i][p1] * 16 + ap[i][p2] * 4 + ap[i][p3]] = false;
    }
    return flag;
  };
  int cnt{};
  for (int p1 = 0; p1 < m; ++p1) {
    for (int p2 = p1 + 1; p2 < m; ++p2) {
      for (int p3 = p2 + 1; p3 < m; ++p3) {
        if (Check(p1, p2, p3)) {
          cnt++;
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
