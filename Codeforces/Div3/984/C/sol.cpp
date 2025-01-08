/**
 *    author:  feev1x
 *    created: 02.11.2024 20:47:22
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    char *S; scanf("%ms", &S);
    string s = S;
    free(S);
    set<int> st;
    for (int i = 0; i + 3 < s.size(); ++i) {
      if (s.substr(i, 4) == "1100") {
        st.emplace(i);
      }
    }
    auto Check = [&](int i) {
      return 0 <= i && i + 3 < s.size();
    };
    int q; scanf("%d", &q);
    while (q--) {
      int i; char c; scanf("%d %c", &i, &c); i--;
      assert(c == '0' || c == '1');
      if (s[i] != c) {
        if (s[i] == '1') {
          for (int x = i - 1; x <= i; ++x) {
            if (Check(x) && s.substr(x, 4) == "1100") {
              st.erase(x);
            }
          }
          s[i] = c;
          for (int x = i - 3; x < i; ++x) {
            if (Check(x) && s.substr(x, 4) == "1100") {
              st.emplace(x);
            }
          }
        } else {
          for (int x = i - 3; x < i; ++x) {
            if (Check(x) && s.substr(x, 4) == "1100") {
              st.erase(x);
            }
          }
          s[i] = c;
          for (int x = i - 1; x <= i; ++x) {
            if (Check(x) && s.substr(x, 4) == "1100") {
              st.emplace(x);
            }
          }
        }
      }
      printf(st.empty() ? "NO\n" : "YES\n");
    }
  }
  return 0;
}
