/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int inf = 1e9;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w, n; cin >> h >> w >> n;
  vector<pair<int, int>> e(n);
  for (int i = 0; i < n; ++i) {
    auto &[r, c] = e[i];
    cin >> r >> c;
  }
  sort(e.begin(), e.end());
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = e[i].second;
  }
  vector<int> d(n + 2, inf), prev(n + 2), pos(n + 2);
  d[0] = -inf;
  pos[0] = -1;
  prev[0] = -1;
  for (int i = 0; i < n; ++i) {
    int j = (upper_bound(d.begin(), d.end(), c[i]) - d.begin());
    d[j] = c[i];
    pos[j] = i;
    prev[pos[j]] = pos[j - 1];
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == inf) break;
    cnt++;
  }
  cout << cnt << '\n';
  int nw = pos[cnt];
  vector<int> p;
  for (; nw != -1; nw = prev[nw]) {
    p.emplace_back(nw);
  }
  reverse(p.begin(), p.end());
  p.emplace_back(e.size());
  e.emplace_back(h, w);
  string res;
  int x = 1, y = 1;
  for (auto u: p) {
    auto [r, c] = e[u];
    while (x < r) {
      x++;
      res += 'D';
    }
    while (y < c) {
      y++;
      res += 'R';
    }
  }
  cout << res << '\n';
} 
