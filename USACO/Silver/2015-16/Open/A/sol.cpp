/**
 *    author:  feev1x
 *    created: 02.12.2024 17:39:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("reduce.in", "r", stdin);
  std::freopen("reduce.out", "w", stdout);
  int n; scanf("%d", &n);
  std::map<int, std::set<int>> mpx, mpy;
  for (int i = 0; i < n; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    mpx[x].emplace(y);
    mpy[y].emplace(x);
  }
  if (n <= 3) {
    printf("0\n");
    exit(0);
  }
  std::function<int(int&, std::map<int, std::set<int>>&, std::map<int, std::set<int>>&)> Dfs = [&](int &cnt, std::map<int, std::set<int>> &mx, std::map<int, std::set<int>> &my) {
    int smx = mx.begin()->first, smy = my.begin()->first, lrx = mx.rbegin()->first, lry = my.rbegin()->first;
    int res = (lrx - smx) * (lry - smy);
    if ((int)mx[smx].size() <= cnt) {
      int cn = cnt - (int)mx[smx].size();
      auto nmx = mx, nmy = my;
      nmx.erase(smx);
      for (auto u: mx[smx]) {
        nmy[u].erase(smx);
      }
      res = std::min(res, Dfs(cn, nmx, nmy));
    }
    if ((int)my[smy].size() <= cnt) {
      int cn = cnt - (int)my[smy].size();
      auto nmx = mx, nmy = my;
      nmy.erase(smy);
      for (auto u: my[smy]) {
        nmx[u].erase(smy);
      }
      res = std::min(res, Dfs(cn, nmx, nmy));
    }
    if ((int)mx[lrx].size() <= cnt) {
      int cn = cnt - (int)mx[lrx].size();
      auto nmx = mx, nmy = my;
      nmx.erase(lrx);
      for (auto u: mx[lrx]) {
        nmy[u].erase(lrx);
      }
      res = std::min(res, Dfs(cn, nmx, nmy));
    }
    if ((int)my[lry].size() <= cnt) {
      int cn = cnt - (int)my[lry].size();
      auto nmx = mx, nmy = my;
      nmy.erase(lry);
      for (auto u: my[lry]) {
        nmx[u].erase(lry);
      }
      res = std::min(res, Dfs(cn, nmx, nmy));
    }
    return res;
  };
  int cn = 3;
  printf("%d\n", Dfs(cn, mpx, mpy));
  return 0;
}
