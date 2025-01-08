/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  if (s[n - 1] == 'n' && s[n - 2] == 'a' && s[n - 3] == 's') cout << "Yes\n";
  else cout << "No\n";
}

