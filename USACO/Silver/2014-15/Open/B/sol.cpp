/**
 *    author:  feev1x
 *    created: 29.11.2024 17:54:29
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("trapped.in", "r", stdin);
  std::freopen("trapped.out", "w", stdout);
  int n, b; scanf("%d%d", &n, &b);
  std::vector<std::pair<int, int>> bales(n);
  for (auto &[pos, sz]: bales) {
    scanf("%d%d", &sz, &pos);
  }
  std::sort(bales.begin(), bales.end());
  if (b < bales.front().first || b > bales.back().first) {
    printf("-1\n");
    exit(0);
  }
  int res = -1;
  std::set<std::pair<int, int>> l, r;
  std::vector<int> suf(n);
  for (int i = 0; i < n; ++i) {
    if (bales[i].first > b) {
      r.emplace(std::max(0, bales[i].second - (bales[i].first - b)) + 1, i);
    } else {
      l.emplace(std::max(0, bales[i].second - (b - bales[i].first)) + 1, i);
    }
  }
  int mx = 0;
  for (auto it = --l.end(); ; --it) {
    mx = std::max(mx, it->second);
    suf[it->second] = mx;
    if (it == l.begin()) {
      break;
    }
  }
  int mn = n + 1;
  for (auto it = --r.end(); ; --it) {
    mn = std::min(mn, it->second);
    suf[it->second] = mn;
    if (it == r.begin()) {
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (bales[i].first > b) {
      auto it = l.upper_bound({bales[i].first - b, n});
      if (it != l.end()) {
        int j = suf[it->second];
        if (res == -1 || res > std::max(0, (bales[i].first - bales[j].first) - bales[i].second)) {
          res = std::max(0, (bales[i].first - bales[j].first) - bales[i].second);
        }
      }
    } else {
      auto it = r.upper_bound({b - bales[i].first, n});
      if (it != r.end()) {
        int j = suf[it->second];
        if (res == -1 || res > std::max(0, (bales[j].first - bales[i].first) - bales[i].second)) {
          res = std::max(0, (bales[j].first - bales[i].first) - bales[i].second);
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
