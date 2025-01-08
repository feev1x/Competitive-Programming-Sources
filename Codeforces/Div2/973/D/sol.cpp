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
    int n; cin >> n;
    vector<int64_t> a(n);
    stack<pair<int64_t, int>> st;
    for (auto &u: a) {
      cin >> u;
      int64_t sum = u, cnt = 1;
      while (!st.empty() && st.top().first >= sum / cnt) {
        sum += st.top().first * st.top().second;
        cnt += st.top().second;
        st.pop();
      }
      if (sum % cnt == 0) {
        st.emplace(sum / cnt, cnt);
      } else {
        // sum / cnt ex = 9.15
        // cnt(9) = cnt
        // cnt(10) = sum % cnt
        // cnt(9) = cnt - cnt(10)
        int c10 = sum % cnt;
        int c9 = cnt - c10;
        st.emplace(sum / cnt, c9);
        st.emplace(sum / cnt + 1, c10);
      }
    }
    int64_t mx = st.top().first;
    while (st.size() > 1) st.pop();
    int64_t mn = st.top().first;
    cout << mx - mn << '\n';
  }
}

// 4 1
// 5 2: 3 1, 2 1
// 7 3: 3 1, 2 2
// 3 2, 2 2
