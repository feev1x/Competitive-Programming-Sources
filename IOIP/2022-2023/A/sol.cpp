/**
 *    author:  feev1x
 *    created: 06.11.2024 09:35:56
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

const ld pi = acos(-1);

struct Vector {
  ld x, y;
  Vector(ld _x, ld _y) : x(_x), y(_y) {}
};

ld angle(Vector v1, Vector v2) {
  double crosspr = abs(v1.x * v2.y - v2.x * v1.y);
	double skalpr = v1.x * v2.x + v1.y * v2.y;
  return atan2(crosspr, skalpr);
}

signed main() {
  ld d, h, w, k; scanf("%Lf%Lf%Lf%Lf", &d, &h, &w, &k);
  Vector sm(0, 2 * d), v1(w, d), v2(h, 2 * d);
  ld an1 = angle(sm, v1);
  ld an2 = angle(sm, v2);
  if (an1 <= an2) {
    ld ans = tan(an1) * 2 * d;
    if ((ans * ans + 2 * d * 2 * d) > k * k) {
      printf("-1\n");
      return 0;
    }
    printf("%.5Lf\n", an1 * 180 / pi);
    return 0;
  }
  ld l = 0, r = 1e18, ans = 0;
  for (int i = 0; i < 10000; ++i) {
    ld m = (l + r) / 2;
    if (m * m + 2 * d * 2 * d >= k * k) {
      r = m - 1e-8;
      if (m * m + 2 * d * 2 * d - k * k <= 1) {
        ans = m;
      }
    } else {
      l = m + 1e-8;
    }
  }
  if (2 * d > k) {
    printf("-1\n");
    return 0;
  }
  Vector v(ans, 2 * d);
  ld an = angle(sm, v);
  if (an1 <= an) {
    printf("%.5Lf\n", an * 180 / pi);
  } else {
    printf("-1\n");
  }
  return 0;
}
