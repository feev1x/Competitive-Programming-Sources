/**
 *    author:  tourist
 *    created: 17.11.2024 06:36:17
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    for (int x = 1; x <= n; x++) {
      if (cnt[x] > 0 && (n - 2) % x == 0) {
        if (cnt[(n - 2) / x] > 0) {
          cout << x << " " << (n - 2) / x << '\n';
          break;
        }
      }
    }
  }
  return 0;
}
