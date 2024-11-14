/**
 *    author:  feev1x
 *    created: 19.10.2024 17:39:56
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int64_t inf = 1e18;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  int64_t p, q; cin >> p >> q;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  auto Dijkstra = [&](set<pair<int64_t, pair<int, int>>> st) {
    auto Edges = [&](int x, int y) {
      auto Check = [&](int x, int y, char ch) {
        if (1 <= x && x <= n) {
          if (1 <= y && y <= m) {
            return s[x][y] == ch;
          }
        }
        return false;
      };
      vector<tuple<int, int, int64_t>> e;
      auto Add = [&](int x, int y, int64_t w, string ch) {
        for (int i = 0; i < ch.size(); ++i) {
          if (Check(x, y, ch[i])) {
            e.emplace_back(x, y, w);
            break;
          }
        }
      };
      Add(x - 2, y, q, "U");
      Add(x + 2, y, q, "D");
      Add(x, y - 2, q, "L");
      Add(x, y + 2, q, "R");
      Add(x - 1, y - 1, p, "LU");
      Add(x - 1, y + 1, p, "RU");
      Add(x + 1, y - 1, p, "LD");
      Add(x + 1, y + 1, p, "RD");
      return e;
    };
    vector<vector<int64_t>> dis(n + 1, vector<int64_t>(m + 1, 1e18));
    for (auto [w, pr]: st) {
      auto [x, y] = pr;
      dis[x][y] = 0;
    }
    while (!st.empty()) {
      auto [x, y] = st.begin()->second;
      st.erase(st.begin());
      auto e = Edges(x, y);
      for (auto [i, j, w]: e) {
        if (dis[i][j] > dis[x][y] + w) {
          st.erase({dis[i][j], {i, j}});
          dis[i][j] = dis[x][y] + w;
          st.emplace(dis[i][j], make_pair(i, j));
        }
      }
    }
    return dis;
  };
  set<pair<int64_t, pair<int, int>>> st;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '.') {
        st.emplace(0, make_pair(i, j));
      }
    }
  }
  auto dis = Dijkstra(st);
  int64_t res = -1;
  auto Chmin = [](int64_t &a, int64_t b) {
    if (b != inf && (a == -1 || a > b)) {
      a = b;
    }
  };
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  auto Check = [&](int x, int y) {
    if (1 <= x && x <= n) {
      if (1 <= y && y <= m) {
        return s[x][y] != '#' && dis[x][y] != inf;
      }
    }
    return false;
  };
  auto Update = [&](int x, int y) {
    if (dis[x][y] == inf || s[x][y] == '#') {
      return;
    }
    for (int k = 0; k < 4; ++k) {
      int i = x + dx[k];
      int j = y + dy[k];
      if (Check(i, j)) {
        Chmin(res, dis[x][y] + dis[i][j]);
      }
    }
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      Update(i, j);
    }
  }
  cout << res << '\n';
  return 0;
}
