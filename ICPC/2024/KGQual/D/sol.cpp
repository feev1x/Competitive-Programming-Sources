/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, M, k; cin >> n >> M >> k;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  sort(a.begin(), a.end());
  int cnt = 0, i = 0;
  while (i < n) {
    int j = (--upper_bound(a.begin(), a.end(), M + a[i]) - a.begin());
    if (j - i + 1 > k) {
      j = min(i + k - 1, n - 1);
    }
    i = j + 1;
    cnt++;
  }
  cout << cnt << '\n';
}

