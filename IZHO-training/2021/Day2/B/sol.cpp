/**
 *    author:  feev1x
 *    created: 27.12.2024 10:37:34
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

inline i64 min(i64 a, i64 b) {
  if (a > b) {
    return b;
  }
  return a;
}

inline i64 max(i64 a, i64 b) {
  if (a < b) {
    return b;
  }
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<i64> a(n + 1), b(n + 2), pa(n + 5);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    pa[i] = pa[i - 1] + a[i];
  }
  for (int i = 1; i <= n + 1; ++i) {
    std::cin >> b[i];
  }
  auto SumA = [&](int l, int r) {
    return pa[r] - pa[l - 1];
  };
  std::stack<std::pair<int, int>> stk;
  std::vector<int> left(n + 2), right(n + 2);
  std::vector<std::vector<int>> mx(n + 2), del(n + 2);
  for (int i = 1; i <= n + 1; ++i) {
    while (stk.size() && stk.top().first < b[i]) {
      stk.pop();
    }
    if (stk.size()) {
      left[i] = stk.top().second;
      mx[left[i]].emplace_back(max(0, b[i] - SumA(left[i], i - 1)));
      del[i].emplace_back(max(0, b[i] - SumA(left[i], i - 1)));
    }
    stk.emplace(b[i], i);
  }
  while (stk.size()) {
    stk.pop();
  }
  for (int i = n + 1; i >= 1; --i) {
    while (stk.size() && stk.top().first < b[i]) {
      stk.pop();
    }
    if (stk.size()) {
      right[i] = stk.top().second;
      mx[i].emplace_back(max(0, b[i] - SumA(i, right[i] - 1)));
      del[right[i]].emplace_back(max(0, b[i] - SumA(i, right[i] - 1)));
    }
    int l = left[i], r = right[i];
    stk.emplace(b[i], i);
  }
  std::multiset<int> st;
  for (int i = 1; i <= n; ++i) {
    for (auto u: del[i]) {
      st.erase(st.find(u));
    }
    for (auto u: mx[i]) {
      st.emplace(u);
    }
    if (st.empty()) {
      std::cout << 0 << " \n"[i == n];
    } else {
      std::cout << *--st.end() << " \n"[i == n];
    }
  }
  return 0;
}
