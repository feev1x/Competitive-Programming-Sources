/**
 *    author:  feev1x
 *    created: 19.11.2024 11:31:09
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZA = 20;
constexpr i64 INF = 1e18;

char S[MXSZA];

int main() {
  int n; scanf("%d", &n);
  std::vector<std::string> a(n);
  for (auto &u: a) {
    scanf("%s", S);
    u = S;
  }
  std::vector<i64> d(n + 4, INF);
  d[0] = -INF;
  auto Num = [](std::string s) {
    i64 num = 0;
    for (int i = 0; i < s.size(); ++i) {
      num = num * 10 + s[i] - '0';
    }
    return num;
  };
  auto Str = [](i64 n) {
    std::string s;
    while (n > 0) {
      s += char(n % 10 + '0'); 
      n /= 10;
    }
    if (s.empty()) {
      s = "0";
    }
    std::reverse(s.begin(), s.end());
    return s;
  };
  for (int i = 0; i < n; ++i) {
    std::sort(a[i].begin(), a[i].end(), std::greater<>());
    int mx = std::upper_bound(d.begin(), d.end(), Num(a[i])) - d.begin();
    std::reverse(a[i].begin(), a[i].end());
    int mn = std::upper_bound(d.begin(), d.end(), Num(a[i])) - d.begin();
    std::string s(a[i].size(), '0');
    std::vector<int> cnt(10);
    for (int j = 0; j < a[i].size(); ++j) {
      cnt[a[i][j] - '0']++;
    }
    auto Apply = [&](int j, i64 num) {
      if (num < d[j] && num > d[j - 1] && num < d[j + 1]) {
        d[j] = num;
      }
    };
    for (int j = mx; j >= mn; --j) {
      if (j == 1) {
        Apply(j, Num(a[i]));
        break;
      }
      auto mp = cnt;
      i64 bol = d[j - 1];
      std::string sb = Str(bol);
      int sz = sb.size();
      mp[0] -= (int)a[i].size() - sz;
      for (int unt = 0; unt <= sz; ++unt) {
        auto cn = mp;
        i64 num = 0;
        bool flag = true;
        for (int in = 0; in < unt; ++in) {
          if (!cn[sb[in] - '0']) {
            flag = false;
            break;
          } else {
            cn[sb[in] - '0']--;
            num = num * 10 + sb[in] - '0';
          }
        }
        if (!flag) {
          break;
        }
        if (unt < sz) {
          flag = false;
          for (int dig = sb[unt] - '0' + 1; dig < 10; ++dig) {
            if (cn[dig]) {
              num = num * 10 + dig;
              flag = true;
              cn[dig]--;
              break;
            }
          }
        }
        if (!flag) {
          continue;
        }
        for (int dig = 0; dig < 10; ++dig) {
          for (int _ = 0; _ < cn[dig]; ++_) {
            num = num * 10 + dig;
          }
        }
        Apply(j, num);
      }
      if (sz < (int)a[i].size()) {
        for (int sz1 = sz + 1; sz1 <= a[i].size(); ++sz1) {
          i64 num = 0;
          auto cn = mp;
          cn[0] += (int)sz1 - sz;
          for (int dig = 1; dig < 10; ++dig) {
            if (cn[dig]) {
              cn[dig]--;
              num = num * 10 + dig;
              break;
            }
          }
          for (int dig = 0; dig < 10; ++dig) {
            for (int _ = 0; _ < cn[dig]; ++_) {
              num = num * 10 + dig;
            }
          }
          Apply(j, num);
        }
      }
    }
  }
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == INF) break;
    res = i;
  }
  printf("%d\n", res);
  return 0;
}
