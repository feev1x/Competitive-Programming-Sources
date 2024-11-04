/**
 *    author:  feev1x
 *    created: 02.11.2024 18:19:08
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int h, w, k; scanf("%d%d%d", &h, &w, &k);
  vector<string> s(h);
  for (auto &u: s) {
    char *S; scanf("%ms", &S);
    u = S;
    free(S);
  }
  auto Check = [&](int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w && s[i][j] == '.';
  };
  vector used(h, vector<bool>(w));
  function<int(int, int, int)> Dfs = [&](int i, int j, int sz) {
    if (sz == k) return 1;
    used[i][j] = true;
    int num = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    bool flag = false;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && !used[x][y]) {
        int nm = Dfs(x, y, sz + 1);
        if (nm > 0) num += nm, flag = true;
      }
    }
    used[i][j] = false;
    if (sz < k && !flag) return 0; 
    return num;
  };
  ll res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      res += Dfs(i, j, 0);
    }
  }
  printf("%lld\n", res);
  return 0;
}
