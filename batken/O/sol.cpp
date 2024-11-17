/**
 *    author:  feev1x
 *    created: 16.11.2024 12:47:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    if (n & 1) {
      printf("Kosuke\n");
    } else {
      printf("Sakurako\n");
    }
  }
  return 0;
}
