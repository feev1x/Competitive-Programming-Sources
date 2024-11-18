/**
 *    author:  feev1x
 *    created: 17.11.2024 15:01:15
**/
#include <bits/stdc++.h>

using i64 = long long;

i64 binpow(i64 a, int n) {
  i64 res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
  return res;
}

int main() {
  int n; scanf("%d", &n);
  char S[n + 1]; scanf("%s", S);
  std::string s = S;
  i64 num = 0;
  for (int i = 0; i < s.size(); ++i) {
    num = num * 10 + s[i] - '0';
  }
  i64 b = binpow(10, n);
  while (std::gcd(num, b) > 1) {
    i64 gc = std::gcd(num, b);
    num /= gc;
    b /= gc;
  }
  if (num >= 1e6 || b >= 1e6) {
    printf("NO\n");
  } else {
    printf("YES\n%lld %lld\n", num, b);
  }
  return 0;
}
