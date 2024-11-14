/**
 *    author:  feev1x
 *    created: 24.10.2024 09:05:08
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

vector<pair<int, int>> kn(1);
vector dont(9, vector<bool>(9));
map<int, map<int, int>> mp;
vector<string> ans;

pair<int, int> Convert(string s) {
  int i, j;
  i = s.back() - '0';
  i = 8 - i + 1;
  j = s.front() - 'a' + 1;
  return {i, j};
}

string Convert(int i, int j) {
  string s;
  s += 'a' + j - 1;
  i = 8 - i + 1;
  s += '0' + i;
  return s;
}

bool Check(int i, int j) {
  return 1 <= i && i <= 8 && 1 <= j && j <= 8;
}

void Go1(int i, int j) {
  if (mp[i][j]) return;
  queue<pair<int, int>> q;
  vector used(9, vector<bool>(9, false));
  vector par(9, vector<pair<int, int>>(9));
  q.emplace(i, j);
  used[i][j] = true;
  int dx[] = {1, 1, -1, -1, 2, -2, 2, -2};
  int dy[] = {2, -2, 2, -2, 1, 1, -1, -1};
  int ax = -1, ay = -1;
  while (!q.empty()) {
  auto [x, y] = q.front();
  q.pop();
  if (mp[x][y] >= 1 && !dont[x][y]) {
    ax = x;
    ay = y;
    break;
  }
  for (int k = 0; k < 8; ++k) {
    int X = x + dx[k];
    int Y = y + dy[k];
    if (Check(X, Y) && !used[X][Y]) {
      used[X][Y] = true;
      par[X][Y] = {x, y};
      q.emplace(X, Y);
    }
  }
  }
  kn[mp[ax][ay]] = {i, j};
  mp[i][j] = mp[ax][ay];
  mp[ax][ay] = 0;
  vector<pair<int, int>> pr;
  function<pair<int, int>(int, int)> Let = [&](int X, int Y) {
    auto [px, py] = par[X][Y];
    if (X == i && Y == j) return pair{X, Y};
    int nx = px, ny = py;
    if (mp[px][py]) {
      tie(nx, ny) = Let(px, py);
    }
    ans.emplace_back(Convert(X, Y) + "-" + Convert(px, py));
    return pair{nx, ny};
  };
  while (ax != i || ay != j) {
    tie(ax, ay) = Let(ax, ay);
  //auto [nx, ny] = par[ax][ay];
  //if (!mp[nx][ny]) {
  //  ans.emplace_back(Convert(ax, ay) + "-" + Convert(par[ax][ay].first, par[ax][ay].second));
    
  //} else {
  //  ans.emplace_back(Convert(nx, ny) + "-" + Convert(par[nx][ny].first, par[nx][ny].second));
  //  ans.emplace_back(Convert(ax, ay) + "-" + Convert(par[ax][ay].first, par[ax][ay].second));
  //}
  }
}

void Go(int i, int j) {
  if (mp[i][j]) return;
  queue<pair<int, int>> q;
  vector used(9, vector<bool>(9, false));
  vector par(9, vector<pair<int, int>>(9));
  q.emplace(i, j);
  used[i][j] = true;
  int dx[] = {1, 1, -1, -1, 2, -2, 2, -2};
  int dy[] = {2, -2, 2, -2, 1, 1, -1, -1};
  int ax = -1, ay = -1;
  while (!q.empty()) {
  auto [x, y] = q.front();
  q.pop();
  if (mp[x][y] >= 1 && !dont[x][y]) {
    ax = x;
    ay = y;
    break;
  }
  for (int k = 0; k < 8; ++k) {
    int X = x + dx[k];
    int Y = y + dy[k];
    if (Check(X, Y) && !used[X][Y] && !dont[X][Y]) {
      used[X][Y] = true;
      par[X][Y] = {x, y};
      q.emplace(X, Y);
    }
  }
  }
  if (ax == -1 && ay == -1) {
  Go1(i, j);
  return;
  }
  kn[mp[ax][ay]] = {i, j};
  mp[i][j] = mp[ax][ay];
  mp[ax][ay] = 0;
  vector<pair<int, int>> pr;
  function<void(int, int)> Let = [&](int X, int Y) {
    auto [px, py] = par[X][Y];
    if (X == i && Y == j) return;
    if (mp[px][py]) {
      Let(px, py);
    }
    ans.emplace_back(Convert(X, Y) + "-" + Convert(px, py));
    debug(X, Y, px, py);
  };
  while (ax != i || ay != j) {
    Let(ax, ay);
    tie(ax, ay) = par[ax][ay];
  //auto [nx, ny] = par[ax][ay];
  //if (!mp[nx][ny]) {
  //  ans.emplace_back(Convert(ax, ay) + "-" + Convert(par[ax][ay].first, par[ax][ay].second));
    
  //} else {
  //  ans.emplace_back(Convert(nx, ny) + "-" + Convert(par[nx][ny].first, par[nx][ny].second));
  //  ans.emplace_back(Convert(ax, ay) + "-" + Convert(par[ax][ay].first, par[ax][ay].second));
  //}
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k; cin >> k;
  for (int i = 1; i <= k; ++i) {
  string s; cin >> s;
  kn.emplace_back(Convert(s));
  mp[Convert(s).first][Convert(s).second] = i;
  }
  int cnt = 0;
  for (int i = 8; cnt < k && i >= 1; --i) {
    for (int j = 1; cnt < k && j <= 8; ++j) {
    Go(i, j);
    dont[i][j] = true;
    cnt++;
    }
  }
  cout << ans.size() << '\n';
  for (auto u: ans) cout << u << '\n';
  return 0;
}
