/**
 *    author:  feev1x
 *    created: 20.11.2024 10:02:48
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 11, MOD = 999999001, N = 51;

char S[SZ];

inline int mul(int a, int b, int mod = MOD) {
  return (i64)a * b % mod;
}

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int binpow(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res = mul(res, a, mod);
    }
    a = mul(a, a, mod);
    n >>= 1;
  }
  return res;
}

int main() {
  int B, n; scanf("%d%d", &B, &n);
  int t; scanf("%d", &t);
  std::vector<std::string> s(t);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  auto Check = [&](int num, int j) {
    int cnt = 0, nm = num, i = B;
    while (num > 0) {
      if (s[j][num % i] == '0' || nm % (num % i) != 0) {
        return false;
      }
      num /= i;
      cnt++;
    }
    return cnt == n;
  };
  for (int j = 0; j < t; ++j) {
    if (std::count(s[j].begin(), s[j].end(), '1') == 1) {
      printf("1\n");
      continue;
    }
    std::map<int, std::map<int, int>> dp[N];
    std::map<int, std::map<int, bool>> used[N];
    std::function<int(int, int, int)> Ans = [&](int len, int d, int lcm) {
      if (len == n) {
        return d == 0 ? 1 : 0;
      }
      if (used[len][d][lcm]) {
        return dp[len][d][lcm];
      }
      int res = 0;
      for (int i = 1; i < B; ++i) {
        if (s[j][i] == '1') {
          int nx = std::lcm(lcm, i);
          add_self(res, Ans(len + 1, ((i64)binpow(B, n - (len + 1), nx) * i % nx + d) % nx, nx));
          if (((i64)binpow(B, n - (len + 1), nx) * i % nx + d) % nx == 0 && len == 1) {
            std::cerr << lcm << ' ' << i << '\n';
          }
        }
      }
      used[len][d][lcm] = true;
      return dp[len][d][lcm] = res;
    };
    printf("%d\n", Ans(0, 0, 1));
  }
  return 0;
}
