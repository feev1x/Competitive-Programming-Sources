/**
 *    author:  feev1x
 *    created: 26.12.2024 20:17:25
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, R; std::cin >> n >> R;
  int l[]{1600, 1200};
  int r[]{2800, 2400};
  for (int i = 0; i < n; ++i) {
    int d, a; std::cin >> d >> a; d--;
    if (l[d] <= R && R < r[d]) {
      R += a;
    }
  }
  std::cout << R << '\n';
  return 0;
}
