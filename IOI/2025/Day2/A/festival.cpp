#include "festival.h"
#include <bits/stdc++.h>

inline bool chmax(__int128 &a, __int128 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

std::vector<int> max_coupons(int A, std::vector<int> P, std::vector<int> T) {
  int n = P.size();
  std::vector<int> res, id(n);
  std::vector<std::vector<int>> idx(5);
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) id[i] = i;
  std::sort(id.begin(), id.end(), [&](int i, int j) {
    return P[i] < P[j];
  });
  for (auto i: id) {
    sum += P[i];
    idx[T[i]].emplace_back(i);
  }
  std::vector dp(idx[1].size() + 1, std::vector(idx[2].size() + 1, std::vector(idx[3].size() + 1, std::vector<__int128>(idx[4].size() + 1, -1))));
  std::vector p(idx[1].size() + 1, std::vector(idx[2].size() + 1, std::vector(idx[3].size() + 1, std::vector<int>(idx[4].size() + 1, 0))));
  std::vector used(idx[1].size() + 1, std::vector(idx[2].size() + 1, std::vector(idx[3].size() + 1, std::vector<bool>(idx[4].size() + 1, 0))));
  dp[0][0][0][0] = 0;
  std::queue<std::tuple<int, int, int, int>> q;
  used[0][0][0][0] = true;
  q.emplace(0, 0, 0, 0);
  int ri, rj, rk, rl;
  while (q.size()) {
    auto [i, j, k, l] = q.front();
    q.pop();
    if (dp[i][j][k][l] >= sum * 2) {
      ri = i, rj = j, rk = k, rl = l;
      while (p[ri][rj][rk][rl] != 0) {
        if (p[ri][rj][rk][rl] == 1) res.emplace_back(idx[1][--ri]);
        if (p[ri][rj][rk][rl] == 2) res.emplace_back(idx[2][--rj]);
        if (p[ri][rj][rk][rl] == 3) res.emplace_back(idx[3][--rk]);
        if (p[ri][rj][rk][rl] == 4) res.emplace_back(idx[4][--rl]);
      }
      std::reverse(res.begin(), res.end());
      while (i < idx[1].size()) res.emplace_back(idx[1][i++]);
      while (j < idx[2].size()) res.emplace_back(idx[2][j++]);
      while (k < idx[3].size()) res.emplace_back(idx[3][k++]);
      while (l < idx[4].size()) res.emplace_back(idx[4][l++]);
      return res;
    }
    if (chmax(dp[i+1][j][k][l], (dp[i][j][k][l] - :wq
            ))) {
      p[i+1][j][k][l] = 1;
      if (!used[i+1][j][k][l]) q.emplace(i+1, j, k, l);
      used[i+1][j][k][l] = true;
    }
    if (chmax(dp[i][j+1][k][l], dp[i][j][k][l])) {
      p[i][j+1][k][l] = 2;
      if (!used[i][j+1][k][l]) q.emplace(i, j+1, k, l);
      used[i][j+1][k][l] = true;
    }
    if (chmax(dp[i][j][k+1][l], dp[i][j][k][l])) {
      p[i][j][k+1][l] = 3;
      if (!used[i][j][k+1][l]) q.emplace(i, j, k+1, l);
      used[i][j][k+1][l] = true;
    }
    if (chmax(dp[i][j][k][l+1], dp[i][j][k][l])) {
      p[i][j][k][l+1] = 1;
      if (!used[i][j][k][l+1]) q.emplace(i, j, k, l+1);
      used[i][j][k][l+1] = true;
    }
  }
  for (int i = 0; i < idx[1].size(); ++i)
  for (int j = 0; j < idx[2].size(); ++j)
  for (int k = 0; k < idx[3].size(); ++k)
  for (int l = 0; l < idx[4].size(); ++l)
    if (dp[i][j][k][l] >= 0) 
      ri=i,rj=j,rk=k,rl=l;
      while (p[ri][rj][rk][rl] != 0) {
        if (p[ri][rj][rk][rl] == 1) res.emplace_back(idx[1][--ri]);
        if (p[ri][rj][rk][rl] == 2) res.emplace_back(idx[2][--rj]);
        if (p[ri][rj][rk][rl] == 3) res.emplace_back(idx[3][--rk]);
        if (p[ri][rj][rk][rl] == 4) res.emplace_back(idx[4][--rl]);
      }
  std::reverse(res.begin(), res.end());
  return res;
}
