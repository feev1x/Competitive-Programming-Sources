/**
 *    author:  feev1x
 *    created: 30.11.2024 21:29:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    auto b = a;
    std::sort(b.begin(), b.end());
    std::array<std::array<std::vector<int>, 3>, 3> pos;
    for (int i = 0; i < n; ++i) {
      pos[b[i]][a[i]].emplace_back(i);
    }
    std::vector<std::pair<int, int>> ans;
    while (pos[2][0].size()) {
      if (pos[0][1].empty()) {
        if (pos[2][1].empty()) {
          int p1 = pos[1][1].back(), p2 = pos[0][2].back();
          pos[1][1].pop_back();
          pos[0][2].pop_back();
          ans.emplace_back(p1 + 1, p2 + 1);
          pos[0][1].emplace_back(p2);
          pos[1][2].emplace_back(p1);
        } else {
          int p1 = pos[2][1].back(), p2 = pos[0][2].back();
          pos[2][1].pop_back();
          pos[0][2].pop_back();
          ans.emplace_back(p1 + 1, p2 + 1);
          pos[0][1].emplace_back(p2);
          pos[2][2].emplace_back(p1);
        }
      } else {
        int p1 = pos[0][1].back(), p2 = pos[2][0].back();
        pos[0][1].pop_back();
        pos[2][0].pop_back();
        ans.emplace_back(p1 + 1, p2 + 1);
        pos[2][1].emplace_back(p2);
        pos[0][0].emplace_back(p1);
      }
    }
    while (pos[0][2].size()) {
      if (pos[2][1].empty()) {
        if (pos[0][1].empty()) {
          int p1 = pos[1][1].back(), p2 = pos[0][2].back();
          pos[1][1].pop_back();
          pos[0][2].pop_back();
          ans.emplace_back(p1 + 1, p2 + 1);
          pos[0][1].emplace_back(p2);
          pos[1][2].emplace_back(p1);
        } else {
          int p1 = pos[2][1].back(), p2 = pos[0][2].back();
          pos[2][1].pop_back();
          pos[0][2].pop_back();
          ans.emplace_back(p1 + 1, p2 + 1);
          pos[0][1].emplace_back(p2);
          pos[2][2].emplace_back(p1);
        }
      } else {
        int p1 = pos[2][1].back(), p2 = pos[0][2].back();
        pos[2][1].pop_back();
        pos[0][2].pop_back();
        ans.emplace_back(p1 + 1, p2 + 1);
        pos[0][1].emplace_back(p2);
        pos[2][2].emplace_back(p1);
      }
    }
    for (int i = 0; i < 3; i += 2) {
      while (pos[i][1].size()) {
        if (pos[1][i].empty()) {
          break;
        }
        int p1 = pos[i][1].back(), p2 = pos[1][i].back();
        pos[i][1].pop_back();
        pos[1][i].pop_back();
        ans.emplace_back(p1 + 1, p2 + 1);
      }
    }
    assert(ans.size() <= n);
    printf("%d\n", (int)ans.size());
    for (auto [u, v]: ans) {
      printf("%d %d\n", u, v);
    }
  }
  return 0;
}
