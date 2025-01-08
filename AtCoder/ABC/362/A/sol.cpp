/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, g, b; cin >> r >> g >> b;
  string s; cin >> s;
  if (s == "Red") {
    cout << min(g, b) << '\n';
  } else if (s == "Green") {
    cout << min(r, b) << '\n';
  } else {
    cout << min(r, g) << '\n';
  }
}

