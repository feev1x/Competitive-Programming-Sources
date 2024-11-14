/**
 *    author:  feev1x
 *    created: 15.10.2024 18:42:12
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b; cin >> a >> b;
  vector<int> Fa, Fb;
  for (int i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      Fa.emplace_back(i);
      if (a / i != i)
        Fa.emplace_back(a / i);
    }
  }
  for (int i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      Fb.emplace_back(i);
      if (b / i != i)
        Fb.emplace_back(b / i);
    }
  }
  sort(Fa.begin(), Fa.end());
  sort(Fb.begin(), Fb.end());
  int i = 0, j = 0;
  int64_t sum = 0;
  string res;
  while (i < Fa.size() && j < Fb.size()) {
    if (Fa[i] == Fb[j]) {
      string s = to_string(Fa[i]);
      int64_t sm = 0;
      for (int i = 0; i < s.size(); ++i) {
        sm += s[i] - '0';
      }
      if (sm > sum) {
        sum = sm;
        res = s;
      }
      i++, j++;
    } else if (Fa[i] > Fb[j]) {
      j++;
    } else {
      i++;
    }
  }
  cout << res << '\n';
}
