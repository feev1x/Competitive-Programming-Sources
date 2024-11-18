/**
 *    author:  feev1x
 *    created: 17.11.2024 18:12:24
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  if (n == 3) {
    printf("2 2\n0 0\n3 0\n0 3\n0 1\n");
    return 0;
  }
  std::vector<std::pair<int, int>> ans;
  ans.emplace_back(2, 2);
  ans.emplace_back(0, 0);
  ans.emplace_back(3, 0);
  ans.emplace_back(0, 3);
  int d = -1, r = 3, l = -1, u = 3;
  int x = 0, y = 3;
  int cnt = 0;
  int mnx = 0, mny = 0;
  for (int i = 0; i < 2 * n - 6; i += 2, cnt++) {
    if (cnt & 1) {
      ans.emplace_back(x, u);
      y = u;
      ans.emplace_back(l, y);
      x = l;
      l--;
      u++;
    } else {
      ans.emplace_back(x, d);
      y = d;
      ans.emplace_back(r, y);
      x = r;
      r++;
      d--;
    }
  }
  for (auto [X, Y]: ans) {
    mnx = std::min(mnx, X);
    mny = std::min(mny, Y);
  }
  mnx = -mnx;
  mny = -mny;
  if (n & 1) {
    ans.emplace_back(-mnx, -mny);
  } else {
    ans.emplace_back(n - 1 - mnx, n - 1 - mny);
  }
  for (auto [X, Y]: ans) {
    printf("%d %d\n", X + mnx, Y + mny);
  }
  return 0;
}
