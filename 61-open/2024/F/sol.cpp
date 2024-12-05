/**
 *    author:  feev1x
 *    created: 24.11.2024 11:08:22
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 5e5 + 5;

char S[SZ];

int main() {
  scanf("%s", S);
  std::string s = S;  
  int n = s.size();
  std::vector<int> z(n);
  int l = -1, r = -1;
  for (int i = 1; i < n; ++i) {
    if (r > i) {
      z[i] = std::min(z[i - l], r - i);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i, r = i + z[i];
    }
  }
  std::map<int, std::vector<int>> mp;
  std::set<int> st;
  std::multiset<int> dis;
  st.emplace(0);
  for (int i = 1; i < n; ++i) {
    if (z[i]) {
      mp[z[i]].emplace_back(i);
      dis.emplace(i - *--st.end());
      st.emplace(i);
    }
  }
  dis.emplace(n - *--st.end());
  st.emplace(n);
  int ans = n;
  for (int sz = 1; sz <= n; ++sz) {
    if (*--dis.end() <= sz) {
      ans = sz;
      break;
    }
    for (auto u: mp[sz]) {
      auto it = st.upper_bound(u);
      auto it1 = --it;
      ++it;
      dis.erase(dis.find(*it - *it1));
      --it;
      --it;
      dis.erase(dis.find(*it1 - *it));
      st.erase(u);
      it = st.upper_bound(u);
      it1 = --it;
      ++it;
      dis.emplace(*it - *it1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
