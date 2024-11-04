/**
 *    author:  feev1x
 *    created: 19.10.2024 20:27:00
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, q; cin >> n >> q;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
      if (p[i] > i) {
        a[i] += 1;
        a[p[i]] -= 1;
      } else {
        a[i] -= 1;
        a[p[i]] += 1; 
      }
      debug(a);
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + a[i];
    }
    debug(pref);
    string s; cin >> s;
    s = " " + s;
    vector<int> lmp(n + 1, 1);
    set<int> st;
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'L' && s[i + 1] == 'R') {
        lmp[i] = 0;
        if (pref[i]) {
          st.emplace(i);
        }
      }
    }
    while (q--) {
      int i; cin >> i;
      if (s[i] == 'L') {
        st.erase(i);
        if (lmp[i] == 0) {
          lmp[i] = 1;
        }
        if (s[i - 1] == 'L') {
          lmp[i - 1] = 0;
          if (pref[i - 1]) {
            st.emplace(i - 1);
          }
        }
        s[i] = 'R';
      } else {
        if (lmp[i - 1] == 0) {
          lmp[i - 1] = 1;
          st.erase(i - 1);
        }
        if (s[i + 1] == 'R') {
          lmp[i] = 0;
          if (pref[i]) {
            st.emplace(i);
          }
        }
        s[i] = 'L';
      }
      debug(st);
      if (st.empty()) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}
