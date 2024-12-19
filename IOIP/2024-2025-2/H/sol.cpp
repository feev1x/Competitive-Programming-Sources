/**
 *    author:  feev1x
 *    created: 06.12.2024 09:26:40
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);  
  std::map<int, int> mp;
  std::set<int> st;
  for (int i = 0; i < n; ++i) {
    int u; scanf("%d", &u);
    st.emplace(u);
    mp[u]++;
  }
  int cnt = 1;
  while (st.size() > 2) {
    int m1 = *st.begin();
    int m2 = *++st.begin();
    auto it = --st.end();
    int M1 = *it;
    int M2 = *--it;
    if (cnt & 1) {
      mp[m2]++;
      mp[m1]--;
      cnt++;
      if (!mp[m1]) {
        st.erase(st.begin());
        mp.erase(m1);
        continue;
      }
    }
    if (mp[m1] < mp[M1]) {
      mp[m2] += mp[m1];
      mp[M2] += mp[m1];
      mp[M1] -= mp[m1];
      cnt += mp[m1] * 2;
      mp.erase(m1);
      st.erase(st.begin());
    } else {
      mp[m2] += mp[M1] - 1;
      mp[M2] += mp[M1];
      mp[m1] -= mp[M1] - 1;
      cnt += mp[M1] * 2 - 1;
      if (!mp[m1]) {
        mp.erase(m1);
        st.erase(st.begin());
      }
      mp.erase(M1);
      st.erase(--st.end());
    }
  }
  printf("%d\n%d %d\n", cnt - 1, *st.begin(), *--st.end());
  return 0;
}
