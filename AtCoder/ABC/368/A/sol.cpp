/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = n - k; i < n; ++i) {
    cout << a[i] << ' ';
  }
  for (int i = 0; i < n - k; ++i) {
    cout << a[i] << ' ';
  }
}

