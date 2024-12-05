/**
 *    author:  feev1x
 *    created: 30.11.2024 12:09:40
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  std::map<int, std::vector<int>> mp;
  for (auto &u: a) {
    scanf("%d", &u);
    mp[u % 10].emplace_back(u);
  }
  a.clear();
  for (auto [key, val]: mp) {
    for (auto u: val) {
      a.emplace_back(u);
    }
  }
  for (auto u: a) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
