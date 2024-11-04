/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s[12]; int cnt = 0;
  for (int i = 0; i < 12; ++i) cin >> s[i], cnt += (s[i].size() == i + 1);
  cout << cnt << '\n';
}

