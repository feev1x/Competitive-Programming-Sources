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
  double d = 0;
  double time = 1;
  bool flag = false;
  for (double spd = a;; spd += a) {
    if (spd >= v) {
      d += dis(v, time - 1 + (v - (spd - a)) / a, spd - a, time - 1);
      spd = v;
    } else {
      d += dis(spd - a, time - 1, spd, time);
    }
    if (y - d > spd) { 
      time++;
    } else {
      debug(y, d, spd, time);
      time += (y - d) / spd;
      break;
    }
  }
  double time1 = 1;
  double d1 = ;
  for (double spd = b;; spd += b) {
    if (spd >= v) {
      d1 += dis(v, time1 - 1 + (v - (spd - b)) / b, spd - b, time1 - 1);
      spd = v;
    } else {
      d1 += dis(spd - b, time1 - 1, spd, time1);
    }
    if (x - d1 > spd) { 
      time1++;
    } else {
      debug(x, d1, spd, time1);
      time1 += (x - d1) / spd;
      break;
    }
  }
  debug(time1, time);
  cout << time1 + time << '\n';
}
