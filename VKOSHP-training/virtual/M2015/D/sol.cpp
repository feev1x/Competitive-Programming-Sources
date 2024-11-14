/**
 *    author:  feev1x
 *    created: 13.11.2024 09:32:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("d.in", "r", stdin);
  std::freopen("d.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  char S[n + 1]; scanf("%s", S);
  std::string s = S;
  std::map<char, char> mp, st;
  for (int i = 0; i < 26; ++i) {
    st[i + 'a'] = i + 'a';
  }
  for (int i = 0; i < m; ++i) {
    char c1, c2; scanf(" %c %c", &c1, &c2);
    mp[st[c1]] = c2;
    mp[st[c2]] = c1;
    char temp = st[c2];
    st[c2] = st[c1];
    st[c1] = temp;
  }
  for (int i = 0; i < n; ++i) {
    if (mp[s[i]]) {
      s[i] = mp[s[i]];
    }
  }
  printf("%s\n", s.c_str());
  return 0;
}
