/**
 *    author:  feev1x
 *    created: 16.10.2024 10:12:34
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double v, x, y, a, b; cin >> v >> x >> y >> a >> b;
  double d = 0, tri = 0;
  double time = 0, otime = 0;
  for (double spd = 0;; spd += a) {
    if (spd >= v) {
      d = (otime * spd);
      spd = v;
    } else {
      tri = (time * spd) / 2;
    }
    d = d + tri;
    if (y - d > spd) { 
      time++;
      if (spd == v) {
        otime++;
      }
    } else {
      time += (y - d) / spd;
      break;
    }
    d = 0;
  }
  double time1 = 0, otime1 = 0;
  double d1 = 0, tri1 = 0;
  for (double spd = 0;; spd += b) {
    if (spd >= v) {
      d1 = (otime1 * spd);
      spd = v;
    } else {
      tri1 = (time1 * spd) / 2;
    }
    d1 = d1 + tri1;
    if (x - d1 > spd) {
      time1++;
      if (spd == v) {
        otime1++;
      }
    } else {
      time1 += (x - d1) / spd;
      break;
    }
    d1 = 0;
  }
  cout << time1 + time << '\n';
}
