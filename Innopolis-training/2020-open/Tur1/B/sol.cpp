/**
 *    author:  feev1x
 *    created: 22.11.2024 09:20:43
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 1e5 + 5;

char S[SZ];

int main() {
  int n; scanf("%d", &n);
  std::vector<std::string> s(n);
  std::vector<std::map<int, int>> mp;
  size_t mxsz = 0;
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
    if (mp.size() < u.size()) {
      mp.resize(u.size());
    }
    for (int i = 0; i < u.size(); ++i) {
      mp[i][u[i]]++;
    }
    mxsz = std::max(mxsz, u.size());
  }
  int res = 0;
  for (int i = 0; i < mxsz; ++i) {
    int mx = 0, cnt = 0;
    for (int j = 0; j < 26; ++j) {
      mx = std::max(mx, mp[i][j + 'a']);
      cnt += mp[i][j + 'a'];
    }
    res += cnt - mx;
  }
  printf("%d\n", res);
  return 0;
}
