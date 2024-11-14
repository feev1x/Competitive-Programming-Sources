/**
 *    author:  feev1x
 *    created: 22.10.2024 10:59:22
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  int64_t B, C; cin >> B >> C;
  vector<int64_t> x(n), p(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> p[i];
  }
  stack<pair<int64_t, int64_t>> st;
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && st.top().first > p[i]) {
      st.pop();
    }
    if (st.empty()) {
      r[i] = -1;
    } else { 
      r[i] = st.top().second;
    }
    st.emplace(p[i], x[i]);
  }
  int64_t bak = 0, nw = 0;
  for (int i = 0; i < n; ++i) {
    if (r[i] == -1) {
      if (bak + B / p[i] < C) {
        bak += B / p[i];
        B -= (B / p[i]) * p[i];
      } else {
        B -= (C - bak) * p[i];
        bak = C;
      }
    } else if (r[i] - x[i] > min(C, B / p[i] + bak)) {
      if (B / p[i] + bak > C) {
        B -= (C - bak) * p[i];
        bak = C;
      } else {
        bak += B / p[i];
        B -= (B / p[i]) * p[i];
      }
    } else {
      if (bak < r[i] - x[i]) {
        B -= (r[i] - x[i] - bak) * p[i];
        bak = r[i] - x[i];
      }
    }
    if (i == n - 1) {
      nw = x[i];
      break;
    }
    if (x[i] + bak >= x[i + 1]) {
      bak -= (x[i + 1] - x[i]);
      nw = x[i + 1];
    } else {
      nw = x[i];
      break;
    }
  }
  cout << nw + bak << '\n';
  return 0;
}
