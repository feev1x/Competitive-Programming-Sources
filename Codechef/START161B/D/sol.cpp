/**
 *    author:  feev1x
 *    created: 20.11.2024 20:53:41
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

inline void min_self(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 2; i < n; ++i) {
      if (a[i - 1] == 2 && a[i + 1] == 2 && a[i] == 3) {
        a[i] = 1;
      }
    }
    std::vector<std::pair<int, int>> seg;
    int l = -1, r = -1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 2) {
        if (r - l + 1 > 2) {
          seg.emplace_back(l, r);
        }
        l = -1, r = -1;
      } else {
        if (l == -1) {
          l = i;
        }
        r = i;
      }
    }
    if (r - l + 1 > 2) {
      seg.emplace_back(l, r);
    }
    for (auto [ll, rr]: seg) {
      bool flag = false;
      for (int i = ll; i <= rr; ++i) {
        if (a[i] == 1) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        continue;
      }
      bool ls = a[ll] == 3;
      for (int i = ll + 1; i <= rr; ++i) {
        if (a[i] == 3) {
          if (ls) {
            a[i] = 1;
          }
          ls = true;
        } else {
          ls = false;
        }
      }
    }
    printf("%d\n", std::accumulate(a.begin(), a.end(), 0));
  }
  return 0;
}

