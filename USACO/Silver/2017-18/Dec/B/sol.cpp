/**
 *    author:  feev1x
 *    created: 18.12.2024 15:25:11
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("measurement.in", "r", stdin);
  std::freopen("measurement.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, g; std::cin >> n >> g;
  std::vector<std::tuple<int, int, std::string>> order(n);
  for (auto &[a, b, c]: order) {
    std::cin >> a >> b >> c;
  }
  std::sort(order.begin(), order.end());
  std::set<std::pair<int, int>> st;
  st.emplace(g, 1e9);
  std::map<int, int> mp;
  int cnt = 0;
  for (auto [day, id, s]: order) {
    int f = s[0] == '+' ? 1 : -1;
    s.erase(s.begin());
    int change = f * stoi(s);
    int val = g;
    if (mp.find(id) != mp.end()) {
      val = mp[id];
    }
    bool flag = false, was = (--st.end())->second == 1;
    int mx = (--st.end())->first;
    if (val == mx) {
      was &= true;
      flag = true;
    } else {
      was = false;
    }
    auto it = st.upper_bound({val, -1});
    int cn = it->second;
    st.erase(it);
    if (cn - 1) {
      st.emplace(val, cn - 1);
    }
    val += change;
    if (val >= mx) {
      flag = true;
    }
    it = st.upper_bound({val, -1});
    if (it == st.end() || it->first != val) {
      st.emplace(val, 1);
    } else {
      cn = it->second;
      st.erase(it);
      st.emplace(val, cn + 1);
    }
    if (was && val == (--st.end())->first && (--st.end())->second == 1) {
      cnt--;
    }
    cnt += flag;
    mp[id] = val;
  }
  std::cout << cnt << '\n';
  return 0;
}
