/**
 *    author:  feev1x
 *    created: 05.12.2024 09:49:37
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e5 + 5;
using pr = std::pair<int, int>;

char S[MXSZ];

struct SpTable {
  std::vector<std::vector<pr>> sp;
  std::vector<int> lg;
  int n;
  inline pr comb(pr a, pr b) {
    if (a > b) {
      return a;
    }
    return b;
  }
  SpTable(std::vector<int> a) : n(a.size() - 1) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<pr>(n + 1));
    for (int i = 1; i <= n; ++i) {
      sp[0][i] = {a[i], i};
    }
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = comb(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  inline int calc(int l, int r) {
    int log = lg[r - l + 1];
    return comb(sp[log][l], sp[log][r - (1 << log) + 1]).second;
  }
};

int main() {
  int n, q; scanf("%d%d", &n, &q);
  scanf("%s", S);
  std::string s = S;
  auto Calc = [&](char c) {
    std::vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
      p[i + 1] = p[i] + (s[i] == c);
    }
    return p;
  };
  auto p1 = Calc('1');
  auto p2 = Calc('2');
  std::vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '/') {
      a[i + 1] = std::min(p1[i], p2[n] - p2[i]) * 2 + 1;
    }
  }
  SpTable sp(a);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    int i = sp.calc(l, r);
    if (a[i] == 0) {
      printf("0\n");
    } else {
      printf("%d\n", std::min(p1[i] - p1[l - 1], p2[r] - p2[i]) * 2 + 1);
    }
  }
  return 0;
}
