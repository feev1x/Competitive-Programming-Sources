/**
 *    author:  feev1x
 *    created: 12.11.2024 19:28:42
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  i64 p; scanf("%lld", &p);
  std::vector<i64> t(n);
  std::set<std::pair<i64, int>> st;
  std::set<int> want, que;
  std::queue<std::pair<i64, int>> q;
  int i = 0;
  for (auto &u: t) {
    scanf("%d", &u);
    st.emplace(u, i++);
  }
  i64 tm = 0;
  while (st.size() || que.size()) {
    while (!st.empty() && st.begin()->first <= tm) {
      want.emplace(st.begin()->second);
      st.erase(st.begin());
    }
    while (!q.empty() && q.front().first <= tm) {
      st.erase(q.front().second);
      q.pop();
    }

  }
  return 0;
}
