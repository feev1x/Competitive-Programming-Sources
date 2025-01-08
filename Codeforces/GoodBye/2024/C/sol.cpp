/**
 *    author:  feev1x
 *    created: 28.12.2024 20:54:13
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, k; std::cin >> n >> k;
    i64 cnt = 0, sum_m = (n + 1) / 2, cnt_seg = 1;
    while (n >= k) {
      bool flag = false;
      if (n & 1) {
        cnt += sum_m;
        flag = true;
      }
      n >>= 1;
      sum_m *= 2;
      if (!flag && n % 2 == 1) {
        sum_m += cnt_seg;
      } else if (flag && n % 2 == 0) {
        sum_m -= cnt_seg;
      }
      cnt_seg *= 2;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
