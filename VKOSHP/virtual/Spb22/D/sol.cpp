/**
 *    author:  feev1x
 *    created: 23.10.2024 11:33:27
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7, mod1 = 1e9 + 9, p = 31, p1 = 101;
 
vector<int> hs, hs1, pow_p, pow_p1;
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, c; cin >> q >> c;
  pow_p.resize(500000 + 1), pow_p1.resize(500000 + 1);
  pow_p[0] = pow_p1[0] = 1;
  for (int i = 1; i <= 5e5; ++i) {
		pow_p[i] = (pow_p[i - 1] * p) % mod;
		pow_p1[i] = (pow_p1[i - 1] * p1) % mod1;
	}
  map<int, map<int, pair<int, int>>> mp;
  for (int k = 1; k <= q; ++k) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      string s; cin >> s;
      hs.resize(s.size() + 2);
      hs1.resize(s.size() + 2);
      for (int i = 1; i <= s.size(); ++i) {
        hs[i] = (hs[i - 1] + int(s[i - 1]) * pow_p[i]) % mod;
        hs1[i] = (hs1[i - 1] + int(s[i - 1]) * pow_p1[i]) % mod1;
      }
      mp[hs[s.size()]][hs1[s.size()]] = {k, x};
    } else {
      string s; cin >> s;
      hs.resize(s.size() + 2);
      hs1.resize(s.size() + 2);
      int pos = -1, x, nm;
      for (int i = 1; i <= s.size(); ++i) {
        hs[i] = (hs[i - 1] + int(s[i - 1]) * pow_p[i]) % mod;
        hs1[i] = (hs1[i - 1] + int(s[i - 1]) * pow_p1[i]) % mod1;
        if (mp[hs[i]][hs1[i]].first) {
          if (pos == -1 || nm < mp[hs[i]][hs1[i]].first) {
            pos = i;
            x = mp[hs[i]][hs1[i]].second;
            nm = mp[hs[i]][hs1[i]].first;
          }
        }
      }
      if (pos == -1) {
        cout << -1 << '\n';
        continue;
      }
      for (int i = pos + 1; i <= s.size(); ++i) {
        if (s[i - 1] == 'L') {
          x = (x + 1) % c;
        } else {
          x = (x - 1 + c) % c;
        }
      }
      cout << x << '\n';
    }
  }
  return 0;
}
