/**
 *    author:  feev1x
 *    created: 29.12.2024 10:27:47
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, q; std::cin >> n >> q;
    std::string s; std::cin >> s;
    std::vector<bool> a(n + 1), b(n + 1);
    std::array<std::set<int>, 2> sa, sb;
    for (int i = 1; i <= n; ++i) {
      a[i] = s[i - 1] == 'R';
      sa[a[i]].emplace(i);
    }
    std::cin >> s;
    for (int i = 1; i <= n; ++i) {
      b[i] = s[i - 1] == 'U';
      sb[b[i]].emplace(i);
    }
    int r1, c1;
    auto FindR = [&](int l, int r, int x) {
      auto it = sa[x].lower_bound(l);
      if (sa[x].empty() || it == sa[x].end() || *it > r) {
        return -1;
      }
      return *it;
    };
    auto FindC = [&](int l, int r, int x) {
      auto it = sb[x].lower_bound(l);
      if (sb[x].empty() || it == sb[x].end() || *it > r) {
        return -1;
      }
      return *it;
    };
    while (q--) {
      int type; std::cin >> type;
      if (type == 1) {
        int r, c; std::cin >> r >> c >> r1 >> c1;
        std::vector<int> rw, cl;
        int found = FindR(1, r1 - 1, 0);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(1, r1 - 1, 1);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(r1 + 1, n, 0);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(r1 + 1, n, 1);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(1, r - 1, 0);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(1, r - 1, 1);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(r + 1, n, 0);
        if (found != -1) {
          rw.emplace_back(found);
        }
        found = FindR(r + 1, n, 1);
        if (found != -1) {
          rw.emplace_back(found);
        }
        rw.emplace_back(r1);
        rw.emplace_back(r);
        std::sort(rw.begin(), rw.end());
        rw.erase(unique(rw.begin(), rw.end()), rw.end());
        found = FindC(1, c1 - 1, 0);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(1, c1 - 1, 1);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(c1 + 1, n, 0);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(c1 + 1, n, 1);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(1, c - 1, 0);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(1, c - 1, 1);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(c + 1, n, 0);
        if (found != -1) {
          cl.emplace_back(found);
        }
        found = FindC(c + 1, n, 1);
        if (found != -1) {
          cl.emplace_back(found);
        }
        cl.emplace_back(c1);
        cl.emplace_back(c);
        std::sort(cl.begin(), cl.end());
        cl.erase(unique(cl.begin(), cl.end()), cl.end());
        int i, j;
        for (i = 0; i < rw.size(); ++i) {
          if (rw[i] == r) {
            break;
          }
        }
        for (j = 0; j < cl.size(); ++j) {
          if (cl[j] == c) {
            break;
          }
        }
        std::vector<std::vector<bool>> used(rw.size(), std::vector<bool>(cl.size()));
        auto Check = [&](int x, int y) {
          return 0 <= x && x < rw.size() && 0 <= y && y < cl.size() && !used[x][y];
        };
        auto Dfs = [&](auto &&self, int x, int y) -> void {
          used[x][y] = true;
          if (a[rw[x]]) {
            if (Check(x, y + 1)) {
              self(self, x, y + 1);
            }
          } else {
            if (Check(x, y - 1)) {
              self(self, x, y - 1);
            }
          }
          if (b[cl[y]]) {
            if (Check(x - 1, y)) {
              self(self, x - 1, y);
            }
          } else {
            if (Check(x + 1, y)) {
              self(self, x + 1, y);
            }
          }
        };
        Dfs(Dfs, i, j);
        for (i = 0; i < rw.size(); ++i) {
          if (rw[i] == r1) {
            break;
          }
        }
        for (j = 0; j < cl.size(); ++j) {
          if (cl[j] == c1) {
            break;
          }
        }
        std::cout << (used[i][j] ? "YES\n" : "NO\n");
      } else if (type == 2) {
        int i; std::cin >> i;
        sa[a[i]].erase(i);
        a[i] = a[i] == 1 ? 0 : 1;
        sa[a[i]].emplace(i);
      } else {
        int i; std::cin >> i;
        sb[b[i]].erase(i);
        b[i] = b[i] == 1 ? 0 : 1;
        sb[b[i]].emplace(i);
      }
    }
  }
  return 0;
}
