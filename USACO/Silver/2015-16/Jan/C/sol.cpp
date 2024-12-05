/**
 *    author:  feev1x
 *    created: 29.11.2024 23:38:01
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 3500, INF = 2e9;

char S[MXSZ];

int main() {
  std::freopen("gates.in", "r", stdin);
  std::freopen("gates.out", "w", stdout);
  int n; scanf("%d", &n);  
  scanf("%s", S);
  std::string s = S;
  std::map<char, std::pair<int, int>> mp;
  std::map<int, std::map<int, std::map<int, std::map<int, bool>>>> used;
  std::map<int, std::map<int, bool>> used1;
  mp['N'] = {0, 1};
  mp['E'] = {1, 0};
  mp['S'] = {0, -1};
  mp['W'] = {-1, 0};
  int x{}, y{}, lx{}, ly{}, cnt{};
  used1[x][y] = true;
  bool back = false;
  for (int i = 0; i < n; ++i) {
    x += mp[s[i]].first;
    y += mp[s[i]].second;
    if (used[lx][ly][x][y]) {
      back = true;
    } else {
      used[lx][ly][x][y] = used[x][y][lx][ly] = true;
      back = false;
    }
    if (!back && used1[x][y]) {
      cnt++;
    }
    used1[x][y] = true;
    lx = x, ly = y;
  }
  printf("%d\n", cnt);
  return 0;
}
