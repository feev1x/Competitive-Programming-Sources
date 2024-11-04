/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b; cin >> n >> a >> b;
  vector<int64_t> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    d[i] %= (a + b);
    d[i]++;
  }
  sort(d.begin() + 1, d.end());
  int64_t mx = 0;
  for (int i = 1; i < n; ++i) {
    mx = max(mx, d[i + 1] - d[i]);
  }
  mx = max(mx, ((a + b) - d[n]) + d[1]);
  if (mx > b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

