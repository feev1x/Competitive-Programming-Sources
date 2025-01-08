/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d; cin >> n >> d;
  vector<int> a(d + 1);
  int lcnt = 0, rcnt = 0;
  vector<int> cy(4000001), cx(4000001);
  int64_t disx = 0, disy = 0;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    x += 2e6;
    y += 2e6;
    disx += x;
    disy += y;
    cy[y]++;
    cx[x]++;
  }
  rcnt = n;
  lcnt = 0;
  for (int i = 0; i <= 4e6; ++i) {
    rcnt -= cy[i];
    lcnt += cy[i];
    if (disy <= d) {
      a[disy]++;
    }
    disy += lcnt;
    disy -= rcnt;
  }
  for (int i = 1; i <= d; ++i) {
    a[i] += a[i - 1];
  }
  lcnt = 0;
  rcnt = n;
  int64_t res = 0;
  bool flag = true;
  for (int i = 0; i <= 4e6; ++i) {
    rcnt -= cx[i];
    lcnt += cx[i];
    if (disx <= d) {
      res += a[d - disx];
    }
    disx += lcnt;
    disx -= rcnt;
  }
  cout << res << '\n';
}

