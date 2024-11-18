/**
 *    author:  feev1x
 *    created: 17.11.2024 17:28:43
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXC = 1e5 + 5;

int main() {
  int n, q; scanf("%d%d", &n, &q);
  std::map<int, std::map<int, int>> mp;
  std::map<int, std::set<int>> st;
  std::map<int, int> cnt;
  int sum = 0;
  while (q--) {
    char ch; scanf(" %c", &ch);
    int u, v, c; scanf("%d%d%d", &u, &v, &c);
    if (ch == '+') {
      mp[c][u]++;
      mp[c][v]++;
      cnt[c]++;
      if (mp[c][u] > 1 || mp[c][v] > 1) {
        if (st[c].empty()) {
          sum -= (cnt[c] - 1);
        }
        if (mp[c][u] > 1) {
          st[c].emplace(u);
        }
        if (mp[c][v] > 1) {
          st[c].emplace(v);
        }
      } else if (st[c].empty()) {
          sum++;
       }
    } else {
      mp[c][u]--;
      mp[c][v]--;
      cnt[c]--;
      if (mp[c][u] <= 1 && mp[c][v] <= 1) {
        if (!st[c].empty()) {
          if (mp[c][u] <= 1) {
            st[c].erase(u);
          }
          if (mp[c][v] <= 1) {
            st[c].erase(v);
          }
          if (st[c].empty()) {
            sum += cnt[c];
          }
        } else {
          sum--;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
