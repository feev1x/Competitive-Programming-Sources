/**
 *    author:  feev1x
 *    created: 14.11.2024 11:31:47
**/
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned i64;

i64 F(i64 a) {
  if (a < 0) return -a;
  return a;
}

int main() {
  i64 a, b; scanf("%lld%lld", &a, &b);
  i64 ra = a, rb = b;
  std::vector<std::pair<i64, i64>> res;
  while (a != 0 && b != 0 && res.size() <= 50) {
    if (F(a) > F(b)) {
      if (a < 0) {
        if (b < 0) {
          res.emplace_back(1, -(F(a) / F(b)));
          a = -(F(a) % F(b));
        } else {
          res.emplace_back(1, F(a) / F(b));
          a = -(F(a) % F(b));
        }
      } else {
        if (b > 0) {
          res.emplace_back(1, -(F(a) / F(b)));
          a = (F(a) % F(b));
        } else {
          res.emplace_back(1, F(a) / F(b));
          a = (F(a) % F(b));
        }
      }
    } else {
      if (b < 0) {
        if (a < 0) {
          res.emplace_back(2, -(F(b) / F(a)));
          b = -(F(b) % F(a));
        } else {
          res.emplace_back(2, F(b) / F(a));
          b = -(F(b) % F(a));
        }
      } else {
        if (a > 0) {
          res.emplace_back(2, -(F(b) / F(a)));
          b = (F(b) % F(a));
        } else {
          res.emplace_back(2, F(b) / F(a));
          b = (F(b) % F(a));
        }
      }
    }
  }
  if (res.size() > 50) {
    res.clear();
    a = ra, b = rb;
    while (a != 0ll && b != 0ll) {
      if (F(a) > F(b)) {
        if (a < 0ll) {
          if (b < 0ll) {
            res.emplace_back(1ll, -((F(a) + F(b) - 1) / F(b)));
            a += res.back().second * b;
          } else {
            res.emplace_back(1ll, (F(a) + F(b) - 1) / F(b));
            a += res.back().second * b;
          }
        } else {
          if (b > 0ll) {
            res.emplace_back(1ll, -((F(a) + F(b) - 1) / F(b)));
            a += res.back().second * b;
          } else {
            res.emplace_back(1ll, (F(a) + F(b) - 1) / F(b));
            a += res.back().second * b;
          }
        }
      } else {
        if (b < 0ll) {
          if (a < 0ll) {
            res.emplace_back(2ll, -((F(b) + F(a) - 1) / F(a)));
            b += res.back().second * a;
          } else {
            res.emplace_back(2ll, (F(b) + F(a) - 1) / F(a));
            b += res.back().second * a;
          }
        } else {
          if (a > 0ll) {
            res.emplace_back(2ll, -((F(b) + F(a) - 1) / F(a)));
            b += res.back().second * a;
          } else {
            res.emplace_back(2ll, (F(b) + F(a) - 1) / F(a));
            b += res.back().second * a;
          }
        }
      }
    }
  }
  assert(res.size() <= 50);
  printf("%d\n", (int)res.size());
  for (auto [x, y]: res) {
    printf("%lld %lld\n", x, y);
  }
  return 0;
}
