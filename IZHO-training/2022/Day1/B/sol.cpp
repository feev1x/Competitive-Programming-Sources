/**
 *    author:  feev1x
 *    created: 28.12.2024 12:17:56
**/
#include <bits/stdc++.h>

using i64 = long long;

struct SpTable {
  std::vector<std::vector<std::pair<i64, int>>> sp;
  std::vector<int> lg;
  int n;
  SpTable(std::vector<i64> a) : n(a.size() - 1) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<std::pair<i64, int>>(n + 1));
    for (int i = 1; i <= n; ++i) {
      sp[0][i] = {a[i], i};
    }
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  inline std::pair<i64, int> get(int l, int r) {
    int i = lg[r - l + 1];
    if (sp[i][l].first == 0 && sp[i][r - (1 << i) + 1].first == 0) {
      return {-1, -1};
    }
    return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<i64> a(n + 1), df(n + 1), p(n + 1), rn(n + 1);
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    p[i] = p[i - 1] + a[i];
    df[i] = a[i] - sum;
    if (df[i] > 0) {
      rn[i] = 1;
    }
    sum += a[i];
  }
  SpTable sp(df), sp1(rn);
//  if (n <= 3000 && q <= 3000) {
//    while (q--) {
//      int L, R, k; std::cin >> L >> R >> k;
//      std::vector<int> b, p;
//      for (int i = L; i <= R; ++i) {
//        b.emplace_back(a[i]);
//        p.emplace_back(0);
//      }
//      std::sort(b.begin(), b.end());
//      int l = 0, r = b.size(), ans = -1;
//      while (l <= r) {
//        int m = l + r >> 1;
//        i64 sz = b[m];
//        bool flag = true;
//        for (int i = 0; i < b.size(); ++i) {
//          if (i == m) {
//            continue;
//          }
//          if (sz - b[i] >= k) {
//            sz += b[i];
//          } else {
//            flag = false;
//          }
//        }
//        if (flag) {
//          r = m - 1;
//          ans = m;
//        } else {
//          l = m + 1;
//        }
//      }
//      if (ans == -1) {
//        std::cout << "0\n";
//      } else {
//        std::cout << (int)b.size() - ans << '\n';
//      }
//    }
//  } else {
    while (q--) {
      int L, R, k; std::cin >> L >> R >> k;
      int ind = sp1.get(L, R).second;
      int j = std::lower_bound(a.begin(), a.end(), a[ind] - k) - a.begin();
      if (j < L) {
        j = L;
      }
      i64 nd = sp.get(j, R).first - p[L - 1] + k;
      if (nd <= 0) {
        std::cout << R - L + 1 << '\n';
        continue;
      }
      int indm = sp.get(j, R).second;
      int l = ind, r = R, ans = -1;
      while (l <= r) {
        int m = l + r >> 1;
        bool flag = false;
        if (m == indm) {
          flag = true;
        } else if (a[m] >= nd) {
          flag = true;
        }
        if (flag) {
          r = m - 1;
          ans = m;
        } else {
          l = m + 1;
        }
      }
      if (ans == -1) {
        std::cout << "0\n";
      } else {
        std::cout << R - ans + 1 << '\n';
      }
    }
//  }
  return 0;
}
