/**
 *    author:  feev1x
 *    created: 29.10.2024 21:01:55
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main() {
  int n; scanf("%d", &n);
  map<int, int> in, out;
  vector<pair<int, int>> vec;
  int zer = 0;
  for (int i = 0; i < n; ++i) {
    stack<char> st;
    int c_in = 0, c_out = 0;
    char *ms = nullptr;
    scanf("%ms", &ms);
    string s = ms;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '(') {
        st.emplace('(');
        c_in++;
      } else {
        if (st.empty() || st.top() == ')') {
          c_out++;
          st.emplace(')');
        } else {
          c_in--;
          st.pop();
        }
      }
    }
    if (c_in == 0 || c_out == 0) {
      if (c_in + c_out == 0) {
        zer++;
      } else {
        if (c_in == 0) {
          out[c_out]++;
        } else {
          in[c_in]++;
        }
      }
    }
    vec.emplace_back(c_in, c_out);
    free(ms);
  }
  ll res = zer * zer;
  for (auto [c_in, c_out]: vec) {
    if (c_in + c_out == 0) continue;
    if (c_in == 0) {
      res += in[c_out];
      out[c_out]--;
    } else {
      res += out[c_in];
      in[c_in]--;
    }
  }
  printf("%lld\n", res);
  return 0;
}
