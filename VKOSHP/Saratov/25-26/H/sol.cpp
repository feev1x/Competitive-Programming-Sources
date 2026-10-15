#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) { return a * 1LL * b % MOD; }
inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  std::vector<std::array<int, 26>> p(n + 1);
  for (int i = 0; i < n + 1; ++i)
    for (int j = 0; j < 26; ++j) p[i][j] = 0;
  std::vector<int> dp(n), pd(n + 1), prev(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) p[i + 1][j] = p[i][j];
    p[i + 1][s[i] - 'a']++;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) prev[i] = prev[i - 1];
    else prev[i] = i;
  }
  auto Get = [&](int l, int r, char c) {
    int v = c - 'a';
    return p[r + 1][v] - p[l][v];
  };
  auto Good = [&](int l, int r) {
    char a = s[l], b = s[r];
    if (a == b) return false;
    int cn = Get(l, r, a);
    if (cn != Get(l, l + cn - 1, a)) return false;
    cn = Get(l, r, b);
    if (cn != Get(r - cn + 1, r, b)) return false;
    return true;
  };
  for (int i = 0; i < n; ++i) {
    int j = prev[i] - 1;
    if (j < 0) continue;
    int k = prev[j], add = 0;
    if (k - 1 < 0) add = 1;
    else add = dp[k - 1];
    add_self(dp[i], pd[j]);
    add_self(dp[i], -pd[k]);
    add_self(dp[i], add);
    pd[i + 1] = pd[i];
    add_self(pd[i + 1], dp[i]);
  }
  std::cout << dp.back() << '\n';
  return 0;
}
