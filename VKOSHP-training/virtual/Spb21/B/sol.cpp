/**
 *    author:  feev1x
 *    created: 14.11.2024 09:48:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::map<int, std::map<int, bool>> dont;
  auto Ask = [&](int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    i64 s; int lb, rb; scanf("%lld%d%d", &s, &lb, &rb);
    dont[lb][rb] = true;
    return s;
  };
  auto Report = [](std::vector<i64> a) {
    printf("!\n");
    for (auto u: a) {
      printf("%lld ", u);
    }
    printf("\n");
    fflush(stdout);
  };
  std::vector<i64> a(n), pref(n);
  auto Sum = [&](int l, int r) {
    if (l > r) return 0ll;
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
  };
  for (int i = 0; i < n; ++i) {
    for (int l = i; l >= 0; --l) {
      if (!dont[l + 1][i + 1]) {
        a[i] = Ask(l + 1, i + 1) - Sum(l, i - 1);
        break;
      }
    }
    pref[i] = a[i];
    if (i) {
      pref[i] += pref[i - 1];
    }
  }
  Report(a);
  return 0;
}
