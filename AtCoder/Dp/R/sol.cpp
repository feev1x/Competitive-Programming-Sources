/**
 *    author:  feev1x
 *    created: 23.10.2024 17:34:01
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

inline int mul(int a, int b) {
  return int64_t(a) * b % mod;
}

class Matrix {
 public:
  vector<vector<int>> t;
  int n;
  Matrix(int _n) : n(_n) {
    t.resize(n, vector<int>(n));
  }
  Matrix(int _n, vector<vector<int>> _t) : n(_n), t(_t) {}
  Matrix operator*(const Matrix &b) const {
    Matrix c(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          add_self(c.t[i][j], mul(t[i][k], b.t[k][j]));
        }
      }
    }
    return c;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; int64_t k; cin >> n >> k;
  vector b(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> b[i][j];
    }
  }
  Matrix ans(n), a(n, b);
  for (int i = 0; i < n; ++i) {
    ans.t[i][i] = 1;
  }
  while (k) {
    if (k & 1) {
      ans = ans * a;
    }
    a = a * a;
    k >>= 1;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      add_self(res, ans.t[i][j]);
    }
  }
  cout << res << '\n';
  return 0;
}
