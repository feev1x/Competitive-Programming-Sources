/**
 *    author:  feev1x
 *    created: 17.11.2024 22:42:18
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int k; scanf("%d", &k);
    std::map<int, int> mp;
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int n, m;
    k -= 2;
    for (int i = 0; i < k + 2; ++i) {
      mp[a[i]]--;
      if (k % a[i] == 0 && mp[k / a[i]]) {
        n = a[i], m = k / a[i];
        break;
      }
      mp[a[i]]++;
    }
    printf("%d %d\n", n, m);
  }
  return 0;
}
