/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, m, q; cin >> n >> m >> q;
    vector<int> beg(n + 1, 1e9), mp(n + 1), a(n), b(m), p(m);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      mp[a[i]] = i + 1;
    }
    bool flag = true;
    vector<set<int>> pos(n + 1);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
      b[i] = mp[b[i]];
      pos[b[i]].emplace(i);
    }
    for (int i = 1; i <= n; ++i) {
      if (pos[i].empty()) continue;
      beg[i] = *pos[i].begin();
    }
    set<int> st;
    for (int i = 1; i < n; ++i) {
      if (beg[i] > beg[i + 1]) {
        st.emplace(i);
      }
    }
    if (st.empty()) cout << "YA\n";
    else cout << "TIDAK\n";
    while (q--) {
      int s, t; cin >> s >> t, s--;
      t = mp[t];
      pos[b[s]].erase(s);
      int old = b[s];
      b[s] = t;
      pos[b[s]].emplace(s);
      beg[b[s]] = *pos[b[s]].begin();
      if (pos[old].empty()) {
        beg[old] = 1e9;
      } else {
        beg[old] = *pos[old].begin();
      }
      beg[t] = *pos[t].begin();
      int temp = t;
      t = old;
      if (t - 1 > 0) {
        if (beg[t - 1] > beg[t]) {
          st.emplace(t - 1);
        } else {
          st.erase(t - 1);
        }
      }
      if (t + 1 <= n) {
        if (beg[t] > beg[t + 1]) {
          st.emplace(t);
        } else {
          st.erase(t);
        }
      }
      t = temp;
      if (t - 1 > 0) {
        if (beg[t - 1] > beg[t]) {
          st.emplace(t - 1);
        } else {
          st.erase(t - 1);
        }
      }
      if (t + 1 <= n) {
        if (beg[t] > beg[t + 1]) {
          st.emplace(t);
        } else {
          st.erase(t);
        }
      }

      if (st.empty()) cout << "YA\n";
      else cout << "TIDAK\n";
    }
  }
}

