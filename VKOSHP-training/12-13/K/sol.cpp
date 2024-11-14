/**
 *    author:  feev1x
 *    created: 17.10.2024 08:59:23
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
//  freopen("vampire.in", "r", stdin);
//  freopen("vampire.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, n; cin >> k >> n;
  auto Check = [](int a, int b) {
    int ml = a * b;
    string s = to_string(ml);
    string f = to_string(a), f1 = to_string(b);
    string t;
    for (int i = 0; i < f.size(); ++i) {
      t += f[i];
      t += f1[i];
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  };
  if (n <= 4) {
    map<int, bool> mp;
    for (int a = pow(10, n / 2 - 1); k && to_string(a).size() == n / 2; ++a) {
      for (int b = pow(10, n / 2 - 1); k && to_string(b).size() == n / 2; ++b) {
        if (to_string(a * b).size() > n) break;
        if (to_string(a * b).size() < n) continue;
        if (!Check(a, b)) continue;
        if (mp[a * b]) continue;
        mp[a * b] = true;
        cout << a * b << '=' << a << 'x' << b << '\n';
        k--;
      }
    }
    return 0;
  }
  map<int, bool> mp;
  string add, add1;
  for (int i = 0; i < (n - 6) / 2; ++i) {
    add += "00";
    add1 += "0";
  }
  for (int a = 100; k && to_string(a).size() == 3; ++a) {
    for (int b = 100; k && to_string(b).size() == 3; ++b) {
      if (to_string(a * b).size() > 6) break;
      if (to_string(a * b).size() < 6) continue;
      if (!Check(a, b)) continue;
      if (mp[a * b]) continue;
      mp[a * b] = true;
      cout << a * b << add << '=' << a << add1 << 'x' << b << add1 << '\n';
      k--;
    }
  }
  return 0;
}
