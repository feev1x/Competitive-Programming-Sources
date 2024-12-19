/**
 *    author:  feev1x
 *    created: 15.12.2024 20:47:41
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    i64 k, l1, r1, l2, r2; scanf("%lld%lld%lld%lld%lld", &k, &l1, &r1, &l2, &r2);
    i64 cnt = 0, u = 1;
    while (u <= r2 / l1) {
      if (l1 * u > r2) {
        u *= k;
        continue;
      }
      i64 l = std::max(l1, (l2 + u - 1) / u), r = std::min(r1, r2 / u);
      if (l > r) {
        u *= k;
        continue;
      }
      cnt += r - l + 1;
      u *= k;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
