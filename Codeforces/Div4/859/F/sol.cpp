/**
 *    author:  feev1x
 *    created: 15.12.2024 00:39:53
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

constexpr int MXSZ = 4;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m, i1, j1, i2, j2; scanf("%d%d%d%d%d%d", &n, &m, &i1, &j1, &i2, &j2);
    scanf("%s", S);
    std::string dir = S;
    auto Check = [&](int i, int j) {
      return 1 <= i && i <= n && 1 <= j && j <= m;
    };
    std::map<std::string, std::pair<int, int>> dd;
    std::map<std::string, std::string> r, l;
    r["DR"] = "DL";
    r["DL"] = "UL";
    r["UL"] = "UR";
    r["UR"] = "DR";
    l["DL"] = "DR";
    l["UL"] = "DL";
    l["UR"] = "UL";
    l["DR"] = "UR";
    dd["DR"] = {1, 1};
    dd["DL"] = {1, -1};
    dd["UR"] = {-1, 1};
    dd["UL"] = {-1, -1};
    std::map<std::string, std::vector<std::vector<bool>>> used;
    for (auto [key, val]: dd) {
      used[key].resize(n + 1, std::vector<bool>(m + 1));
    }
    int x = i1, y = j1, cnt = 0;
    while (x != i2 || y != j2) {
      if (used[dir][x][y]) {
        cnt = -1;
        break;
      }
      used[dir][x][y] = true;
      if (!Check(dd[dir].first + x, dd[dir].second + y)) {
        cnt++;
        if (Check(dd[r[dir]].first + x, dd[r[dir]].second + y)) {
          dir = r[dir];
        } else if (Check(dd[l[dir]].first + x, dd[l[dir]].second + y)) {
          dir = l[dir];
        } else {
          dir = r[r[dir]];
        }
      }
      x += dd[dir].first;
      y += dd[dir].second;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
