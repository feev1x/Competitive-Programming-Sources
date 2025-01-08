/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, d, k; cin >> n >> d >> k;
    vector<pair<int, int>> rab(k);
    map<int, int> lf, rg;
    for (auto &[l, r]: rab) cin >> l >> r, lf[l]++, rg[r]++;
    int mx = 0, mn = n;
    int nw = 0;
    for (int i = 1; i <= d; ++i) {
      nw += lf[i];
    }
    int bro = 1, mot = 1;
    for (int l = 1; l + d <= n; ++l) {
      if (mx < nw) {
        mx = nw;
        bro = l;
      }
      if (mn > nw) {
        mn = nw;
        mot = l;
      }
      nw -= rg[l];
      nw += lf[l + d];
      if (mx < nw) {
        mx = nw;
        bro = l + 1;
      }
      if (mn > nw) {
        mn = nw;
        mot = l + 1;
      }

    }
    cout << bro << ' ' << mot << '\n';
  }
}

