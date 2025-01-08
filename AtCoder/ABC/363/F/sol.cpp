/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

string rev(int64_t n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return s;
}

string f(int64_t n) {
  if (to_string(n) == rev(n) && to_string(n).find('0') == string::npos) {
    return to_string(n);
  }
  for (int64_t x = 2; x * x <= n; ++x) {
    if (n % x == 0 && to_string(x).find('0') == string::npos) {
      int64_t y = stoll(rev(x));
      if ((n / x) % y == 0 && !f((n / x) / y).empty()) {
        return to_string(x) + "*" + f((n / x) / y) + "*" + to_string(y);
      }
    }
  }
  return "";
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n; cin >> n;
  string ans = f(n);
  if (ans.empty()) ans = "-1";
  cout << ans << '\n';
}

