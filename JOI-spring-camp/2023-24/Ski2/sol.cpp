#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void chmin(int &a, int b) { if (a > b) a = b; }
inline void chmin(int64_t &a, int64_t b) { if (a > b) a = b; }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> h(n), c(n), idx(n);
  std::map<int, int> mp, mn;
  int64_t add = 0;
  int min = 1e9;
  std::multiset<int> st;
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i] >> c[i];
    chmin(min, h[i]);
    mp[h[i]]++;
    st.emplace(h[i]);
    if (mn.count(h[i])) chmin(mn[h[i]], c[i]);
    else mn[h[i]] = c[i];
  }
  add += (mp[min] - 1) * 1LL * k;
  mp[min + 1] += mp[min] - 1;
  mp[min] = 1;
  chmin(mn[min + 1], mn[min]);
  std::vector<int> ps;
  while (st.size()) {
    int val = *st.begin();
    st.erase(st.begin());
    if (ps.size() && ps.back() >= val) {
      val++;
      st.emplace(val);
    } else ps.emplace_back(val);
  }
  int cn = n;
  n = ps.size();
  std::vector<int> a(n);
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i] = mp[ps[i]];
    if (mn[ps[i]] == 0) mn[ps[i]] = c[i - 1];
    c[i] = std::min(mn[ps[i]], (i ? c[i - 1] : mn[ps[i]]));
  }
  std::vector dp(n, std::vector(cn + 1, std::vector<int64_t>(cn + 2, INF)));
  std::vector mdp(n, std::vector(cn + 1, std::vector<int64_t>(cn + 2, INF)));
  std::vector fdp(n, std::vector(cn + 1, std::vector<int64_t>(cn + 2, INF)));
  dp[0][a[0]][a[0]] = add;
  mdp[0] = dp[0];
  for (int i = 1; i < n; ++i) {
    for (int mx = 1; mx <= cn; ++mx) {
      for (int ls = a[i]; ls <= cn; ++ls) {
        if (mx + ls - a[i] <= cn) chmin(dp[i][mx][ls], mdp[i - 1][mx][mx + ls - a[i]] + (ls - a[i]) * 1LL * k);
        chmin(dp[i][mx][ls], fdp[i - 1][mx][ls - a[i]] + (ls - a[i]) * 1LL * k);
      }
    }
    mdp[i] = dp[i];
    for (int ls = cn; ls >= 0; --ls) 
      for (int mx = 1; mx <= cn; ++mx)
        chmin(mdp[i][mx][ls], mdp[i][mx - 1][ls] + c[i - 1]);
    if (i + 1 < n)
      for (int mx = 1; mx <= cn; ++mx) {
        std::multiset<int64_t> st;
        for (int ls = a[i + 1]; ls <= std::min(cn, mx + a[i + 1]); ++ls) st.emplace(dp[i][mx][ls - a[i + 1]]);
        fdp[i][mx][0] = *st.begin();
        for (int ls = a[i + 1] + 1; ls <= cn; ++ls) {
          st.erase(st.find(dp[i][mx][ls - a[i + 1] - 1]));
          if (mx + ls - a[i + 1] <= cn) st.emplace(dp[i][mx][mx + ls - a[i + 1]]);
          fdp[i][mx][ls - a[i + 1]] = *st.begin();
        }
      }
  }
  int64_t res = INF;
  for (int mx = 1; mx <= cn; ++mx)
    for (int ls = 0; ls <= cn; ++ls) {
      if (mx >= ls) chmin(res, dp[n - 1][mx][ls]);
      else chmin(res, dp[n - 1][mx][ls] + (ls - mx) * 1LL * c[n - 2]);
    }
  std::cout << res << '\n';
  return 0;
}
