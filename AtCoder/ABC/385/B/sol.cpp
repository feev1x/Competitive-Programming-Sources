/**
 *    author:  feev1x
 *    created: 21.12.2024 18:06:51
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int h, w, x, y; std::cin >> h >> w >> x >> y; x--, y--;
  std::vector<std::string> s(h);
  std::vector<std::vector<bool>> used(h, std::vector<bool>(w + 1));
  for (int i = 0; i < h; ++i) {
    std::cin >> s[i];
  }
  std::string t; std::cin >> t;
  std::map<char, std::pair<int, int>> mp;
  mp['U'] = {-1, 0};
  mp['D'] = {1, 0};
  mp['L'] = {0, -1};
  mp['R'] = {0, 1};
  auto Check = [&](int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w && s[i][j] != '#';
  };
  int cnt = 0;
  int n = t.size();
  for (int i = 0; i < n; ++i) {
    int X = x + mp[t[i]].first;
    int Y = y + mp[t[i]].second;
    if (Check(X, Y)) {
      x = X, y = Y;
      if (!used[x][y] && s[x][y] == '@') {
        cnt++;
      }
      used[x][y] = true;
    }
  }
  std::cout << x + 1 << ' ' << y + 1 << ' ' << cnt << '\n';
  return 0;
}
