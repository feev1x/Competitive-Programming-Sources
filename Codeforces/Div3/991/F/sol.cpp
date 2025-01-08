/**
 *    author:  feev1x
 *    created: 05.12.2024 21:50:53
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

struct SpTable {
  std::vector<std::vector<int>> sp;
  std::vector<int> lg;
  std::function<int(int, int)> Fun;
  int n;
  SpTable(std::vector<int> a, std::function<int(int, int)> _Fun) : n(a.size() - 1), Fun(_Fun) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = Fun(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  inline int calc(int l, int r) {
    int i = lg[r - l + 1];
    return Fun(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, q; scanf("%d%d", &n, &q);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
      a[i] = std::abs(a[i] - a[i + 1]);
    }
    auto Fun = [](int a, int b) -> int {
      return std::gcd(a, b);
    };
    SpTable sp(a, Fun);
    while (q--) {
      int l, r; scanf("%d%d", &l, &r); r--;
      if (l > r) {
        printf("0 ");
        continue;
      }
      int gcd = sp.calc(l, r);
      printf("%d ", gcd);
    }
    printf("\n");
  }
  return 0;
}
