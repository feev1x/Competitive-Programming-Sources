#include "hieroglyphs.h"
#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

std::vector<int> ucs(std::vector<int> A, std::vector<int> B) {
  int n = A.size(), m = B.size();
  std::vector<std::vector<int>> pa(N), pb(N);
  for (int i = 0; i < n; ++i) pa[A[i]].emplace_back(i);
  for (int i = 0; i < m; ++i) pb[B[i]].emplace_back(i);
  std::set<int> sa, sb;
  for (int i = 0; i < N; ++i) {
    if (pa[i].empty() || pb[i].empty()) continue;
    if (pa[i].size() < pb[i].size()) {
      for (auto u: pa[i]) sa.emplace(u);
    } else {
      for (auto u: pb[i]) sb.emplace(u);
    }
  }
  std::vector<int> ans;
  if (sa.empty() && sb.empty()) return ans;
  {
    auto Dfs = [&](auto &&self, int i, int j) -> bool {
      if (ans.size() == sa.size() + sb.size()) return true;
      {
        auto it = sa.upper_bound(i);
        if (sa.size() && it != sa.end()) {
          int idx = *it;
          int jdx = std::upper_bound(pb[A[idx]].begin(), pb[A[idx]].end(), j) - pb[A[idx]].begin();
          if (jdx < pb[A[idx]].size()) {
            jdx = pb[A[idx]][jdx];
            auto it = sb.upper_bound(j);
            if (sb.empty() || it == sb.end() || *it > jdx) {
              ans.emplace_back(A[idx]);
              if (self(self, idx, jdx)) return true;
              ans.pop_back();
            }
          }
        }
      }
      auto it = sb.upper_bound(j);
      if (sb.size() && it != sb.end()) {
        int jdx = *it;
        int idx = std::upper_bound(pa[B[jdx]].begin(), pa[B[jdx]].end(), i) - pa[B[jdx]].begin();
        if (idx < pa[B[jdx]].size()) {
          idx = pa[B[jdx]][idx];
          auto it = sa.upper_bound(i);
          if (sa.empty() || it == sa.end() || *it > idx) {
            ans.emplace_back(B[jdx]);
            if (self(self, idx, jdx)) return true;
            ans.pop_back();
          }
        }
      }
      return false;
    }; Dfs(Dfs, -1, -1);
    if (ans.empty()) return {-1};
  }
  {
    for (int i = 1; i < ans.size(); ++i) {
      std::swap(ans[i], ans[i - 1]);
      int k = 0;
      for (int j = 0; k < ans.size() && j < n; ++j) if (A[j] == ans[k]) k++;
      if (k < i) {
        std::swap(ans[i], ans[i - 1]);
        continue;
      }
      k = 0;
      for (int j = 0; k < ans.size() && j < m; ++j) if (B[j] == ans[k]) k++;
      if (k < i) {
        std::swap(ans[i], ans[i - 1]);
        continue;
      }
      return {-1};
    }
  }
  return ans;
}
