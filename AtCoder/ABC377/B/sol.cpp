/**
 *    author:  feev1x
 *    created: 26.10.2024 18:02:13
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
  vector<string> s(8);
  int cntr = 0, cntc = 0;
  for (int i = 0; i < 8; ++i) {
    cin >> s[i];
    if (s[i].find('#') == string::npos) {
      cntr++;
    }
  }
  for (int i = 0; i < 8; ++i) {
    bool flag = true;
    for (int j = 0; j < 8; ++j) {
      if (s[j][i] == '#') flag = false;
    }
    cntc += flag;
  }
  cout << cntr * cntc << '\n';
  return 0;
}
