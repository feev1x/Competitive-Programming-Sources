/**
 *    author:  feev1x
 *    created: 11.12.2024 09:02:39
**/
#include <bits/stdc++.h>

using i64 = long long;

inline int dis(int x1, int y1, int x2, int y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main() {
  std::vector<int> x(3), y(3);
  int mx = -1e9, my = -1e9;
  int mx1 = 1e9, my1 = 1e9;
  for (int i = 0; i < 3; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    mx = std::max(mx, x[i]);
    my = std::max(my, y[i]);
    mx1 = std::min(mx1, x[i]);
    my1 = std::min(my1, y[i]);
  }
  std::vector<std::tuple<int, int, int, int>> ans;
  if (mx == mx1) {
    ans.emplace_back(mx, my, mx, my1);
  } else if (my == my1) {
    ans.emplace_back(mx, my, mx1, my);
  } else {
    bool flag = false;
    int opt = -1, dif = -1;
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        if (x[i] == x[j]) {
          flag = true;
          opt = x[i];
          for (int k = 0; k < 3; ++k) {
            if (k != i && k != j) {
              dif = k;
              break;
            }
          }
          ans.emplace_back(x[i], y[i], x[j], y[j]);
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    if (flag) {
      ans.emplace_back(opt, y[dif], x[dif], y[dif]);
    } else {
      std::vector<int> is;
      for (int i = 0; i < 3; ++i) {
        is.emplace_back(i);
      }
      std::sort(is.begin(), is.end());
      ans.emplace_back(x[is[0]], y[is[0]], x[is[1]], y[is[0]]);
      ans.emplace_back(x[is[1]], my, x[is[1]], my1);
      ans.emplace_back(x[is[2]], y[is[2]], x[is[1]], y[is[2]]);
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto [x1, y1, x2, y2]: ans) {
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
  return 0;
}
