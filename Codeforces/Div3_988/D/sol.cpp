/**
 *    author:  feev1x
 *    created: 17.11.2024 22:01:40
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m, L; scanf("%d%d%d", &n, &m, &L);
    std::vector<std::pair<int, int>> seg(n);
    for (auto &[l, r]: seg) {
      scanf("%d%d", &l, &r);
    }
    std::vector<int> x(m), v(m);
    std::multiset<int> st;
    std::map<int, bool> mp;
    int j = 0;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x[i], &v[i]);
      while (j < n && seg[j].second < x[i]) {
        j++;
      }
      if (j == n) --j;
      if (!(seg[j].first <= x[i] && x[i] <= seg[j].second)) {
        mp[i] = true;
      }
    }
    j = 0;
    int sum = 1, cnt = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      while (j < m && !mp[j]) {
        j++;
      }
      while (j < m && seg[i].first > x[j]) {
        st.emplace(v[j]);
        j++;
      }
      while (seg[i].second - seg[i].first + 1 >= sum) {
        if (st.empty()) {
          flag = false;
          break;
        }
        sum += *--st.end();
        assert(sum > 0);
        st.erase(--st.end());
        cnt++;
      }
      if (!flag) {
        break;
      }
    }
    if (flag) {
      printf("%d\n", cnt);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
