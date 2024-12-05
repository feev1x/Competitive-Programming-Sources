/**
 *    author:  feev1x
 *    created: 30.11.2024 22:30:35
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    if (n == k) {
      printf("YES\n");
      for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
          printf("%d ", j);
        }
        for (int j = 1; j < i; ++j) {
          printf("%d ", j);
        }
        printf("\n");
      }
      continue;
    }
    if (n == 1) {
      printf("NO\n");
      continue;
    }
    if (k == 2) {
      printf("YES\n");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", i);
      }
      printf("\n");
      for (int i = n; i > 0; --i) {
        printf("%d ", i);
      }
      printf("\n");
      continue;
    }
    if (k == 1 || k > n || n % 2 == 0) {
      printf("NO\n");
      continue;
    }
    int st = n / 2 + 1;
    if (k > 2 + (n - st + 1) / st) {
      printf("NO\n");
      continue;
    }
    k--;
    printf("YES\n");
    std::vector<int> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
      printf("%d ", i);
      sum[i] += i;
    }
    printf("\n");
    int dif = n - st + 1;
    for (int ss = st; k > 1 && ss <= n; ss += st) {
      int pos = 1;
      for (int i = ss; i <= n; ++i) {
        printf("%d ", i);
        sum[pos++] += i;
      }
      for (int i = 1; i < ss; ++i) {
        printf("%d ", i);
        sum[pos++] += i;
      }
      k--;
      printf("\n");
    }
    int mn = *std::min_element(sum.begin() + 1, sum.end());
    for (int i = 1; i <= n; ++i) {
      sum[i] -= mn - 1;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", n - sum[i] + 1);
    }
    printf("\n");
  }
  return 0;
}
