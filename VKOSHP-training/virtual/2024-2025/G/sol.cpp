/**
 *    author:  feev1x
 *    created: 10.12.2024 11:25:12
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      pos[p[i]] = i;
    }
    auto p_old = p;
    if (p == std::vector{0, 1, 3, 2} || p == std::vector{0, 2, 1, 3} || p == std::vector{0, 3, 2, 1}) {
      printf("-1\n");
      continue;
    }
    std::vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == i) {
        continue;
      }
      int l, r;
      if (n - i == 1) {
        ans.emplace_back(i - 2, i);
        l = i - 2, r = i;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        std::reverse(p.begin() + l, p.begin() + r + 1);
        ans.emplace_back(i - 1, i);
        l = i - 1, i;
        std::reverse(p.begin() + l, p.begin() + r + 1);
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        ans.emplace_back(i - 1, i + 1);
        l = i - 1, r = i + 1;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        std::reverse(p.begin() + l, p.begin() + r + 1);
        ans.emplace_back(i - 2, i + 1);
        l = i - 2, r = i + 1;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        std::reverse(p.begin() + l, p.begin() + r + 1);
        break;
      }
      if (pos[i] == i + 1) {
        pos[p[i]] = i + 2;
        pos[i] = i;
        pos[p[i + 2]] = i + 1;
        std::swap(p[i], p[i + 2]);
        std::swap(p[i], p[i + 1]);
        ans.emplace_back(i, i + 2);
        l = i, r = i + 2;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        ans.emplace_back(i, i + 1);
        l = i, r = i + 1;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
      } else {
        ans.emplace_back(i, pos[i] - 1);
        l = i, r = pos[i] - 1;
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        l = i, r = pos[i];
        std::reverse(p_old.begin() + l, p_old.begin() + r + 1);
        ans.emplace_back(i, pos[i]);
        int ls = i;
        for (int j = i; j < pos[i]; ++j) {
          pos[p[j]]++;
        }
        for (int j = pos[i]; j > i; --j) {
          std::swap(p[j], p[j - 1]);
        }
      }
      assert(p == p_old);
    }
    assert(std::is_sorted(p.begin(), p.end()));
    assert(std::is_sorted(p_old.begin(), p_old.end()));
    int c1 = 0, c2 = 0;
    printf("%d\n", (int)ans.size());
    for (auto [l, r]: ans) {
      printf("%d %d\n", l, r);
//      for (int i = 1; i <= n; ++i) {
//        printf("%d ", p_old[i]);
//      }
//      c1 += ((r - l + 1) & 1);
//      c2 += !((r - l + 1) & 1);
//      printf("\n");
    }
//    printf("c1 c2 : %d %d\n", c1, c2);
  }
  return 0;
}
