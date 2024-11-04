/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int l, r; cin >> l >> r;
  if (l + r == 2) {
    cout << "Invalid\n";
  } else {
    if (l == 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

