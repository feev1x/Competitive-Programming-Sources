#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int h, w; std::cin >> h >> w;
  std::vector<std::string> s(h + 2);
  for (int i = 1; i <= h; ++i) {
    std::cin >> s[i];
    s[i] = " " + s[i];
    s[i] += " ";
  }
  s[0].assign(w + 2, ' ');
  s[h + 1].assign(w + 2, ' ');
  int i = 1, j = 1, oi, oj;
  std::vector<std::vector<bool>> used(h + 2, std::vector<bool>(w + 2));
  for (int i = 0; i <= h + 1; ++i) used[i][0] = used[i][w + 1] = true;
  for (int i = 0; i <= w + 1; ++i) used[0][i] = used[h + 1][i] = true;
  while (!used[i][j]) {
    used[i][j] = true;
    oi = i, oj = j;
    switch(s[i][j]) {
      case 'U':
        --i;
        break;
      case 'D':
        ++i;
        break;
      case 'L':
        --j;
        break;
      default:
        ++j;
        break;
    }
  }
  if (1 <= i && i <= h && 1 <= j && j <= w) std::cout << "-1\n";
  else std::cout << oi << ' ' << oj << '\n';
  return 0;
}
