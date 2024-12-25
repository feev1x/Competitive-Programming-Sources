/**
 *    author:  feev1x
 *    created: 23.12.2024 11:23:03
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, type; std::cin >> n >> m >> type;
  std::vector<std::string> a(n), b(n);
  for (auto &u: a) {
    std::cin >> u;
  }
  for (auto &u: b) {
    std::cin >> u;
  }
  int sz = INF, opt = -1;
  for (int mask = 0; mask < (1 << n / 2); ++mask) {
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
      if (mask >> i & 1) {
        reverse(a[i].begin(), a[i].end());
        reverse(a[n - i - 1].begin(), a[n - i - 1].end());
        ans++;
      }
    }
    for (int j = 0; j < (m + 1) / 2; ++j) {
      bool flag = true;
      for (int i = 0; i < n; ++i) {
        if (a[i][j] != b[i][j] || a[i][m - j - 1] != b[i][m - j - 1]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        continue;
      }
      if (j == m - j - 1) {
        goto end;
      }
      for (int i = 0; i < n; ++i) {
        if ((a[n - i - 1][j] != b[i][j] || a[n - i - 1][m - j - 1] != b[i][m - j - 1])) {
          goto end;
        }
      }
      ans++;
    }
    if (sz > ans) {
      sz = ans;
      opt = mask;
    }
end:
    for (int i = 0; i < n / 2; ++i) {
      if (mask >> i & 1) {
        reverse(a[i].begin(), a[i].end());
        reverse(a[n - i - 1].begin(), a[n - i - 1].end());
      }
    }
  }
  if (opt == -1) {
    std::cout << "-1\n";
    exit(0);
  }
  std::vector<int> C, R;
  for (int i = 0; i < n / 2; ++i) {
    if (opt >> i & 1) {
      reverse(a[i].begin(), a[i].end());
      reverse(a[n - i - 1].begin(), a[n - i - 1].end());
      C.emplace_back(i + 1);
    }
  }
  for (int j = 0; j < m / 2; ++j) {
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (a[i][j] != b[i][j] || a[i][m - j - 1] != b[i][m - j - 1]) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      R.emplace_back(j + 1);
    }
  }
  std::cout << sz << '\n';
  for (auto u: R) {
    std::cout << "C " << u << '\n';
  }
  for (auto u: C) {
    std::cout << "R " << u << '\n';
  }
  return 0;
}
