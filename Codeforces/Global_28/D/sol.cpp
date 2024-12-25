/**
 *    author:  feev1x
 *    created: 19.12.2024 21:05:04
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    i64 n, m, kev, cnt = 0; std::cin >> n >> m >> kev;
    std::vector<i64> a(n - 1), b(m);
    for (auto &u: a) { 
      std::cin >> u;
      if (u > kev) {
        cnt++;
      }
    }
    std::sort(a.begin(), a.end());
    a.emplace(a.begin(), -1);
    for (auto &u: b) {
      std::cin >> u;
    }
    std::sort(b.begin(), b.end());
    b.emplace(b.begin(), -1);
    int j = m + 1, p = 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > kev) {
        p = i;
        break;
      }
    }
    for (int i = 1; i <= m; ++i) {
      if (b[i] > kev) {
        j = i;
        break;
      }
    }
    i64 rang = cnt + 1;
    for (int k = 1; k <= m; ++k) {
      if (rang == 1 || j == m + 1) {
        std::cout << m / k << ' ';
        continue;
      }
      i64 ans = 0;
      i64 os = m % k;
      i64 str = j;
      if (os > m - j + 1) {
        os -= m - j + 1;
      } else {
        os = 0;
      }
      for (int nw = str + m % k; nw <= m; nw += k) {
        ans += n - (std::lower_bound(a.begin(), a.end(), b[nw]) - a.begin()) + 1;
        if (nw + k <= m) {
          os = nw + k - m;
        }
      }
      str -= os;
      ans += (str - 1) / k;
      std::cout << ans << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
