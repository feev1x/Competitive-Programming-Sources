/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b; cin >> a >> b;
  set<int> st;
  for (int x = -1000; x <= 1000; ++x) {
    vector<int> v = {a, b, x};
    sort(v.begin(), v.end());
    do {
      if (v[0] - v[1] == v[2] - v[0]) {
        st.emplace(x);
        break;
      }
    } while (next_permutation(v.begin(), v.end()));
  }
  cout << st.size() << '\n';
}

