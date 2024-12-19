/**
 *    author:  feev1x
 *    created: 15.12.2024 20:42:38
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n);
    std::vector<bool> used(n + 1);
    for (auto &u: a) {
      scanf("%d", &u);
      used[u] = true;
    }
    std::vector<int> cnt(n + 1);
    for (int i = 0, j = 1; i < n; ++i) {
      cnt[a[i]]++;
      if (cnt[a[i]] == 2) {
        cnt[a[i]] = 1;
        while (used[j]) {
          j++;
        }
        cnt[j]++;
        used[j] = true;
        a[i] = j;
      }
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  return 0;
}
