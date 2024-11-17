/**
 *    author:  feev1x
 *    created: 14.11.2024 11:14:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, a, b; scanf("%d%d%d", &n, &a, &b);
  std::vector<int> x(n), y(n);
  std::set<std::pair<int, int>> sA, sB;
  int sum = 0;
  for (auto &u: x) {
    scanf("%d", &u);
  }
  for (auto &u: y) {
    scanf("%d", &u);
  }
  for (int i = 0; i < n; ++i) {
    if (x[i] > y[i]) {
      sA.emplace(x[i] - y[i], i);
      sum += x[i];
    } else {
      sB.emplace(y[i] - x[i], i);
      sum += y[i];
    }
  }
  while (sA.size() < a) {
    sum -= sB.begin()->first;
    int i = sB.begin()->second;
    sB.erase(sB.begin());
    sA.emplace(x[i] - y[i], i);
  }
  while (sB.size() < b) {
    sum -= sA.begin()->first;
    int i = sA.begin()->second;
    sA.erase(sA.begin());
    sB.emplace(y[i] - x[i], i);
  }
  printf("%d\n", sum);
  std::vector<char> res(n);
  for (auto [smsms, u]: sA) {
    res[u] = 'T';
  }
  for (auto [smsms, u]: sB) {
    res[u] = 'P';
  }
  for (auto u: res) {
    printf("%c ", u);
  }
  printf("\n");
  return 0;
}
