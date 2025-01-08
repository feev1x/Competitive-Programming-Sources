/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w, q; cin >> h >> w >> q;
  vector<vector<int>> a(h + 1, vector<int>(w + 1, -1));
  vector<set<int>> rw(h + 1), cl(w + 1);
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      rw[i].emplace(j);
    }
  }
  for (int i = 1; i <= w; ++i) {
    for (int j = 1; j <= h; ++j) {
      cl[i].emplace(j);
    }
  }
  function<void(int, int)> boom = [&](int r, int c) {
    if (a[r][c] == -1) {
      rw[r].erase(c);
      cl[c].erase(r);
      a[r][c] = 1;
    }
  };
  int res = h * w;
  while (q--) {
    int r, c; cin >> r >> c;
    if (a[r][c] == -1) {
      boom(r, c);
      res--;
    } else {
      auto up = cl[c].upper_bound(r), right = rw[r].upper_bound(c);
      if (!cl[c].empty() && up != cl[c].begin()) {
        boom(*--up, c);
        res--;
      }
      up = cl[c].upper_bound(r);
      if (!cl[c].empty() && up != cl[c].end()) {
        boom(*up, c);
        res--;
      }
      if (!rw[r].empty() && right != rw[r].begin()) {
        boom(r, *--right);
        res--;
      }
      right = rw[r].upper_bound(c);
      if (!rw[r].empty() && right != rw[r].end()) {
        boom(r, *right);
        res--;
      }
    }
  }
  cout << res << '\n';

}

