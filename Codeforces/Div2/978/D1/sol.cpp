/**
 *    author:  feev1x
 *    created: 21.10.2024 07:58:22
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    auto Ask = [](int i, int j) {
      i++, j++;
      cout << "? " << i << ' ' << j << endl;
      int got; cin >> got;
      return got;
    };
    auto Report = [](int i) {
      i++;
      cout << "! " << i << endl;
    };
    int n; cin >> n;
    int not_imp = n - 1, imp = -1;
    for (int i = 0; i < n; i += 2) {
      int j = (i + 1) % n;
      auto mind1 = Ask(i, j);
      auto mind2 = Ask(j, i);
      if (mind1 ^ mind2) {
        mind1 = Ask(i, not_imp);
        mind2 = Ask(not_imp, i);
        if (mind1 ^ mind2) {
          imp = i;
        } else {
          imp = j;
        }
        break;
      }
      not_imp = 0;
    }
    Report(imp);
  }
  return 0;
}
