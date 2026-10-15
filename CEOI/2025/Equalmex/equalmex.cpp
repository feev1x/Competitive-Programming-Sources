#include <bits/stdc++.h>

std::vector<int> solve(int n, std::vector<int>& v, int q, std::vector<std::pair<int,int>>& queries)
{
	std::vector<int> res(q);
  for (int i = 0; i < q; ++i) {
    auto [l, r] = queries[i];
    std::vector<int> ok(r - l + 3);
    for (int j = l; j <= r; ++j) if (v[j] < ok.size()) ok[v[j]] = true;
    int mex = 1;
    for (int j = 1; j < ok.size(); ++j) {
      if (!ok[j]) break;
      ++mex;
    }
    if (mex == 1) {
      res[i] = r - l + 1;
      continue;
    }
    for (int j = l; j <= r; ++j) if (v[j] < ok.size()) ok[v[j]] = false;
    int cnt = 0, k = 1;
    for (int j = l; j <= r; ++j) {
      if (v[j] < mex && ok[v[j]] < k) {
        ok[v[j]] = k;
        cnt++;
        if (cnt == mex - 1) {
          cnt = 0;
          k++;
        }
      }
    }
    res[i] = k - 1;
  }
	return res;
}
