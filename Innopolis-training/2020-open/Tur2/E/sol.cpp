/**
 *    author:  feev1x
 *    created: 21.11.2024 16:57:29
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  i64 s; scanf("%lld", &s);
  std::vector<i64> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &l[i], &r[i]);
  }
  if (n <= 20) {
    i64 res = 0;
    std::vector<i64> ans(n);
    for (int mask = 0; mask < (1 << n); ++mask) {
      i64 well = 0, wellwell = 0;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) {
          well += l[i];
          wellwell += r[i] - l[i];
        }
      }
      if (well <= s) {
        i64 mxwell = well + wellwell;
        if (mxwell > s) {
          mxwell = s;
        }
        if (res < mxwell) {
          res = mxwell;
          for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
              ans[i] = l[i];
              mxwell -= l[i];
            } else {
              ans[i] = 0;
            }
          }
          for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
              if (r[i] - l[i] >= mxwell) {
                ans[i] += mxwell;
                mxwell = 0;
                break;
              }
              ans[i] = r[i];
              mxwell += l[i];
              mxwell -= r[i];
            }
          }
          assert(mxwell == 0);
        }
      }
    }
    printf("%lld\n", res);
    for (auto u: ans) {
      printf("%lld ", u);
    }
    printf("\n");
  } else {
    std::vector<
  }
  return 0;
}
