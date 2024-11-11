/**
 *    author:  feev1x
 *    created: 10.11.2024 12:55:09
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
  int n; scanf("%d", &n);
  vector<int> A(n);
  stack<int> B;
  vector<int> ar;
  vector<string> ans;
  for (auto &u: A) {
    scanf("%d", &u);
    while (!B.empty() && B.top() <= u) {
      ar.emplace_back(B.top());
      ans.emplace_back("pop");
      B.pop();
    }
    ans.emplace_back("push");
    B.emplace(u);
  }
  while (!B.empty()) {
    ar.emplace_back(B.top());
    ans.emplace_back("pop");
    B.pop();
  }
  if (is_sorted(ar.begin(), ar.end())) {
    for (auto u: ans) {
      printf("%s\n", u.c_str());
    }
  } else {
    printf("impossible\n");
  }
  return 0;
}
