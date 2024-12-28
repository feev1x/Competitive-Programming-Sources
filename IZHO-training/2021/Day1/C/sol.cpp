/**
 *    author:  feev1x
 *    created: 26.12.2024 12:59:22
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Bit {
  std::vector<int> p;
  int n; 
  Bit(int _n) : n(_n) {
    p.resize(n + 1);
  }
  inline void modify(int r, int x) {
    for (; r <= n; r += r & -r) {
      p[r] += x;
    }
  }
  inline int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) {
      res += p[r];
    }
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, t; std::cin >> n >> t;
  std::vector<int> p1(n + 1), p2(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> p1[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> p2[i];
  }
  if (t == 2) {
    std::map<std::vector<int>, bool> used;
    std::vector<std::pair<int, int>> ans;
    auto Dfs = [&](auto &&self, std::vector<int> p, int lef, int rig) {
      if (used[p]) {
        return false;
      }
      used[p] = true;
      if (p == p2) {
        return true;
      }
      for (int i = 1; i <= n; ++i) {
        auto pr = p;
        int cnt = 0;
        for (int j = i + 1; j <= n; ++j) {
          cnt += p[j] > p[i] ? 1 : -1;
          std::swap(pr[j], pr[j - 1]);
          if (cnt == 0 && (lef != i || rig != j) && self(self, pr, i, j)) {
            ans.emplace_back(i, j - i);
            return true;
          }
        }
        pr = p;
        cnt = 0;
        for (int j = i - 1; j > 0; --j) {
          cnt += p[j] > p[i] ? 1 : -1;
          std::swap(pr[j], pr[j + 1]);
          if (cnt == 0 && (lef != j || rig != i) && self(self, pr, j, i)) {
            ans.emplace_back(i, j - i);
            return true;
          }
        }
      }
      return false;
    };
    if (Dfs(Dfs, p1, -1, -1)) {
      std::cout << "YES\n";
      reverse(ans.begin(), ans.end());
      std::cout << ans.size() << '\n';
      for (auto [p, k]: ans) {
        std::cout << p << ' ' << k << '\n';
      }
    } else {
      std::cout << "NO\n";
    }
  } else {
    Bit bit1(n), bit2(n);
    i64 cnt1 = 0, cnt2 = 0;
    int pos_1, pos_n;
    bool flag1, flag2;
    for (int i = 1; i <= n; ++i) {
      cnt1 += bit1.get(p1[i] - 1);
      bit1.modify(p1[i], 1);
      if (p1[i] == 1) {
        pos_1 = i;
      } else if (p1[i] == n) {
        pos_n = i;
      }
    }
    flag1 = pos_1 < pos_n;
    for (int i = 1; i <= n; ++i) {
      cnt2 += bit2.get(p2[i] - 1);
      bit2.modify(p2[i], 1);
      if (p2[i] == 1) {
        pos_1 = i;
      } else if (p2[i] == n) {
        pos_n = i;
      }
    }
    flag2 = pos_1 < pos_n;
    std::cout << (cnt1 == cnt2 && flag1 == flag2 ? "YES\n" : "NO\n");
  }
  return 0;
}

