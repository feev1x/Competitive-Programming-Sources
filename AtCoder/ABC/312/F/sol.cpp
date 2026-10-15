#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<int> t(n), x(n);
  std::vector<int> op, reg, pull, all;
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i] >> x[i];
    if (t[i] == 2) op.emplace_back(x[i]);
    else {
      all.emplace_back(x[i]);
      if (t[i] == 0) pull.emplace_back(x[i]);
      else reg.emplace_back(x[i]);
    }
  }
  std::sort(op.begin(), op.end(), std::greater<>());
  std::sort(reg.begin(), reg.end(), std::greater<>());
  std::sort(pull.begin(), pull.end(), std::greater<>());
  std::sort(all.begin(), all.end(), std::greater<>());
  std::vector<int64_t> p_reg, p_pull, p_all;
  int64_t ls = 0;
  for (auto u: reg) p_reg.emplace_back(ls += u);
  ls = 0;
  for (auto u: pull) p_pull.emplace_back(ls += u);
  ls = 0;
  for (auto u: all) p_all.emplace_back(ls += u);
  int nw = 0;
  int64_t res = (p_pull.size() ? p_pull[std::min((int)p_pull.size() - 1, m - 1)] : 0LL);
  for (int i = 0; m - i - 2 >= 0 && i < op.size(); ++i) {
    nw += op[i];
    if (all.size() <= m - i - 2) continue;
    int val = all[m - i - 2];
    int l = 0, r = (int)reg.size() - 1, ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (reg[mid] >= val) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    ans++;
    if (ans > nw) res = std::max(res, int64_t(nw ? p_reg[nw - 1]: 0LL) + int64_t(m - i - 2 - nw >= 0 ? p_pull[m - i - 2 - nw] : 0LL));
    else res = std::max(res, p_all[m - i - 2]);
  }
  std::cout << res << '\n';
  return 0;
}
