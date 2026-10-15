#include <bits/stdc++.h>

const std::string D = "UDLR";

inline void go(char direction, int &xx, int &yy) {
  switch (direction) {
    case 'U':
      --xx;
      break;
    case 'D':
      ++xx;
      break;
    case 'L':
      --yy;
      break;
    default:
      ++yy;
      break;
  }
}

bool move(char direction, int &x, int &y, int &xx, int &yy) {
  std::cout << direction << std::endl;
  switch (direction) {
    case 'U':
      --xx;
      break;
    case 'D':
      ++xx;
      break;
    case 'L':
      --yy;
      break;
    default:
      ++yy;
      break;
  }
  std::string result;
  std::cin >> result;
  if (result == "win" || result == "fail")
    exit(0);
  if (result == "new") {
    std::cin >> x >> y;
    return true;
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  int xs, ys; std::cin >> xs >> ys;
  int xa, ya; std::cin >> xa >> ya;
  std::vector mv(n + 1, std::vector<char>(m + 1));
  std::vector mv2(n + 1, std::vector<char>(m + 1));
  if (m & 1) {
    m--;
    for (int j = 1; j <= m; j += 2) mv[2][j] = 'D', mv[n][j] = 'R';
    for (int j = 2; j <= m; j += 2) mv[n][j] = 'U', mv[2][j] = 'R';
    mv[2][m] = 'U';
    for (int j = 1; j <= m; ++j) mv[1][j] = 'L';
    mv[1][1] = 'D';
    m++;
    for (int i = 2; i <= n; i += 2) mv[i][m] = 'U';
    for (int i = 1; i <= n; i += 2) mv[i][m] = 'L';
    for (int i = 2; i <= n; i += 2) mv[i][m - 1] = 'R';
    for (int i = 1; i <= n; i += 2) mv[i][m - 1] = 'U';
    mv[1][m - 1] = 'L';
    mv2 = mv;
    if (n & 1) {
      mv2[n][m - 1] = 'R';
      mv2[n][m] = 'U';
      mv2[n - 1][m] = 'L';
      mv2[n - 1][m - 1] = 'U';
    }
  } else {
    for (int j = 1; j <= m; j += 2) mv[2][j] = 'D', mv[n][j] = 'R';
    for (int j = 2; j <= m; j += 2) mv[n][j] = 'U', mv[2][j] = 'R';
    mv[2][m] = 'U';
    for (int j = 1; j <= m; ++j) mv[1][j] = 'L';
    mv[1][1] = 'D';
    mv2 = mv;
  }
  std::vector used(n + 1, std::vector<bool>(m + 1));
  std::deque<std::pair<int, int>> dq;
  dq.emplace_back(xs, ys);
  used[xs][ys] = true;
  while (true) {
    if (xa == n && ya == 1 && (xs != n - 1 || ys != m - 1 && ys != m)) {
      int x = xs, y = ys;
      go(mv2[xs][ys], x, y);
      if (used[x][y]) {
        if (std::abs(xs - xa) + std::abs(ys - ya) > 1) {
          auto [xd, yd] = dq.front();
          dq.pop_front();
          used[xd][yd] = false;
        }
        for (int i = 0; i < 4; ++i) {
          x = xs, y = ys;
          go(D[i], x, y);
          if (!used[x][y]) {
            move(D[i], xa, ya, xs, ys);
            dq.emplace_back(xs, ys);
            used[xs][ys] = true;
            break;
          }
        }
      } else {
        if (move(mv2[xs][ys], xa, ya, xs, ys)) {
          dq.emplace_back(xs, ys);
          used[xs][ys] = true;
        } else {
          auto [xd, yd] = dq.front();
          dq.pop_front();
          used[xd][yd] = false;
          dq.emplace_back(xs, ys);
          used[xs][ys] = true;
        }
      }
    } else {
      int x = xs, y = ys;
      go(mv[xs][ys], x, y);
      if (!used[x][y]) {
        if (move(mv[xs][ys], xa, ya, xs, ys)) {
          dq.emplace_back(xs, ys);
          used[xs][ys] = true;
        } else {
          auto [xd, yd] = dq.front();
          dq.pop_front();
          used[xd][yd] = false;
          dq.emplace_back(xs, ys);
          used[xs][ys] = true;
        }
      } else {
        if (std::abs(xs - xa) + std::abs(ys - ya) > 1) {
          auto [xd, yd] = dq.front();
          dq.pop_front();
          used[xd][yd] = false;
        }
        for (int i = 0; i < 4; ++i) {
          x = xs, y = ys;
          go(D[i], x, y);
          if (!used[x][y]) {
            move(D[i], xa, ya, xs, ys);
            dq.emplace_back(xs, ys);
            used[xs][ys] = true;
            break;
          }
        }
      }
    }
  }
  return 0;
}
