/**
 *    author:  feev1x
 *    created: 02.01.2025 16:51:51
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> a(2 * n);
    std::map<int, int> mp;
    bool flag = false;
    for (auto &u: a) {
      std::cin >> u;
      mp[u]++;
      if (mp[u] == 2 * n) {
        flag = true;
      }
    }
    if (flag) {
      if (a[0] == -1) {
        for (int i = 0; i < 2 * n; ++i) {
          if (i & 1) {
            std::cout << "L";
          } else {
            std::cout << "R";
          }
        }
        std::cout << '\n';
      } else if (a[0] == 0) {
        for (int i = 0; i < 2 * n; ++i) {
          if (i & 1) {
            std::cout << "R";
          } else {
            std::cout << "L";
          }
        }
        std::cout << '\n';
      } else {
        assert(false);
      }
      continue;
    }
    if (n <= 2000) {
      std::sort(a.begin(), a.end());
      std::string s;
      std::vector<std::vector<int>> p(n + 1, std::vector<int>(n + 1, -1));
      auto Rec = [&](auto &&self, int l, int r) {
        if (l > n || r > n) {
          return false;
        }
        if (p[l][r] != -1) {
          return true;
        }
        if (l + r == 2 * n) {
          return true;
        }
        mp[l - r]--;
        if (mp[l - r] >= 0 && self(self, l + 1, r)) {
          p[l][r] = 1;
          return true;
        }
        mp[l - r]++;
        int l1 = n - l, r1 = n - r - 1;
        if (r1 < 0) {
          return false;
        }
        mp[r1 - l1]--;
        if (mp[r1 - l1] >= 0 && self(self, l, r + 1)) {
          p[l][r] = 2;
          return true;
        }
        mp[r1 - l1]++;
        return false;
      };
      assert(Rec(Rec, 0, 0));
      int l = 0, r = 0;
      while (l + r < 2 * n) {
        assert(p[l][r] != -1);
        if (p[l][r] == 1) {
          s += 'L';
          l++;
        } else {
          s += 'R';
          r++;
        }
      }
      std::cout << s << '\n';
    } else {
      std::string s;
      int l = 0, r = 0;
      for (int i = 0; i < 2 * n; ++i) {
        if (l + 1 <= n && l - r == a[i]) {
          s += "L";
          l++;
        } else {
          s += "R";
          r++;
        }
      }
      assert(l == r);
      std::cout << s << '\n';
    }
  }
  return 0;
}
