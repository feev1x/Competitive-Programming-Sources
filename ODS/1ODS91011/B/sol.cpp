/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int R, G, a, b, c; cin >> R >> G >> a >> b >> c;
  vector<int64_t> p(a), q(b), r(c);
  for (auto &u: p) cin >> u;
  for (auto &u: q) cin >> u;
  for (auto &u: r) cin >> u;
  sort(p.begin(), p.end(), greater<>());
  sort(q.begin(), q.end(), greater<>());
  sort(r.begin(), r.end(), greater<>());
  int64_t sum = 0;
  for (int i = 0; i < R; ++i) {
    sum += p[i];
  }
  for (int i = 0; i < G; ++i) {
    sum += q[i];
  }
  R--;
  G--;
  int nw = 0;
  while ((R >= 0 || G >= 0) && nw < r.size()) {
    if (R < 0) {
      if (q[G] >= r[nw]) break;
      sum += r[nw] - q[G--];
    } else if (G < 0) {
      if (p[R] >= r[nw]) break;
      sum += r[nw] - p[R--];
    } else {
      if (q[G] > p[R]) {
        if (p[R] >= r[nw]) break;
        sum += r[nw] - p[R--];
      } else {
        if (q[G] >= r[nw]) break;
        sum += r[nw] - q[G--];
      }
    }
    nw++;
  }
  cout << sum << '\n';
}

