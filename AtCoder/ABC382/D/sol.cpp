/**
 *    author:  feev1x
 *    created: 30.11.2024 18:12:38
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::set<std::vector<int>> st;
  std::function<void(std::vector<int>)> Rec = [&](std::vector<int> a) {
    if (a.size() == n) {
      st.emplace(a);
      return;
    }
    int val = a.empty() ? -9 : a.back();
    int i = a.size() + 1;
    for (int add = 10; (n - i) * 10 + add + val <= m; ++add) {
      a.emplace_back(val + add);
      Rec(a);
      a.pop_back();
    }
  };
  Rec({});
  printf("%d\n", (int)st.size());
  for (auto a: st) {
    for (auto u: a) {
      printf("%d ", u);
    }
    printf("\n");
  }
  return 0;
}
