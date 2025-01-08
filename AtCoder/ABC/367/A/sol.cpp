/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
  bool fl = true;
  for (int i = b; i != c; i = (i + 1) % 24) {
    if (i == a) {
      fl = false;
      break;
    }
  }
  if (fl) cout << "Yes\n";
  else cout << "No\n";
}

