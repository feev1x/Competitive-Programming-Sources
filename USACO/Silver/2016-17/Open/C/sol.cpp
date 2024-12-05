/**
 *    author:  feev1x
 *    created: 05.12.2024 14:37:49
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 22;
using smat = std::vector<std::string>;
using mat = std::vector<std::vector<int>>;

char S[MXSZ];

int main() {
  std::freopen("where.in", "r", stdin);
  std::freopen("where.out", "w", stdout);
  int n; scanf("%d", &n);
  smat s(n);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  int x1, y1, x2, y2;
  auto Check = [&](int i, int j) {
    return x1 <= i && i <= x2 && y1 <= j && j <= y2;
  };
  std::vector used(n, std::vector(n, false));
  int dx[]{-1, 1, 0, 0};
  int dy[]{0, 0, -1, 1};
  std::function<void(int, int)> Dfs = [&](int i, int j) {
    used[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && !used[x][y] && s[x][y] == s[i][j]) {
        Dfs(x, y);
      }
    }
  };
  std::vector<std::tuple<int, int, int, int>> pcl;
  int ind = 0;
  std::vector<mat> strp(n, mat(n));
  auto IsntContained = [&](int sx, int sy, int ex, int ey) {
    for (int i = 0; i <= sx; ++i) {
      for (int j = 0; j <= sy; ++j) {
        for (auto u: strp[i][j]) {
          auto [_, __, x, y] = pcl[u];
          if (x >= ex && y >= ey) {
            return false;
          }
        }
      }
    }
    return true;
  };
  auto IsPcl = [&](int sx, int sy, int ex, int ey) {
    std::tie(x1, y1, x2, y2) = {sx, sy, ex, ey};
    std::map<char, int> mp;
    std::set<char> st;
    for (int i = sx; i <= ex; ++i) {
      for (int j = sy; j <= ey; ++j) {
        if (!used[i][j]) {
          mp[s[i][j]]++;
          st.emplace(s[i][j]);
          Dfs(i, j);
        }
        if (st.size() > 2) {
          goto end;
        }
      }
    }
end:
    for (int i = sx; i <= ex; ++i) {
      for (int j = sy; j <= ey; ++j) {
        used[i][j] = false;
      }
    }
    if (st.size() != 2) {
      return false;
    }
    bool flag1 = false, flag2 = false;
    for (auto u: st) {
      if (mp[u] > 1) {
        flag2 = true;
      } else {
        flag1 = true;
      }
    }
    return bool(flag1 & flag2);
  };
  for (int szn = n; szn > 0; --szn) {
    for (int szm = n; szm > 0; --szm) {
      for (int x = 0; x + szn - 1 < n; ++x) {
        for (int y = 0; y + szm - 1 < n; ++y) {
          if (IsntContained(x, y, x + szn - 1, y + szm - 1) && IsPcl(x, y, x + szn - 1, y + szm - 1)) {
            pcl.emplace_back(x, y, x + szn - 1, y + szm - 1);
            strp[x][y].emplace_back(ind);
            ind++;
          }
        }
      }
    }
  }
  printf("%d\n", ind);
  return 0;
}
