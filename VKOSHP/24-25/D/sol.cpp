/**
 *    author:  feev1x
 *    created: 17.11.2024 15:35:11
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 n, m, s; scanf("%lld%lld%lld", &n, &m, &s);
  if (s == n * m) {
    printf("0\n");
    return 0;
  }
  if (s % n == 0 || s % m == 0) {
    printf("1\n");
    return 0;
  }
  bool flag = false;
  for (i64 i = 1; i <= (n + 1) / 2; ++i) {
    if (s % i == 0 && s / i <= m || s % (n - i) == 0 && s / (n - i) <= m) {
      flag = true;
      break;
    }
    i64 temp = s - i * m;
    if (temp > 0 && temp % (n - i) == 0 && temp / (n - i) <= m) {
      flag = true;
      break;
    }
    temp = s - (n - i) * m;
    if (temp > 0 && temp % i == 0 && temp / (n - i) <= m) {
      flag = true;
      break;
    }
    i64 a = i, b = n - i;
    if (a > b) {
      std::swap(a, b);
    }
    if (a == b) {
      if (s % a == 0 && s / a <= 2 * m) {
        flag = true;
        break;
      }
    } else {
      if ((s - b * m) % (a - b) == 0) {
        i64 x = (s - b * m) / (a - b);
        if (x > 0 && x < m && a * x + b * (m - x) == s) {
          flag = true;
          break;
        }
      }
    }
  }
  std::swap(n, m);
  for (i64 i = 1; i <= (n + 1) / 2; ++i) {
    if (s % i == 0 && s / i <= m || s % (n - i) == 0 && s / (n - i) <= m) {
      flag = true;
      break;
    }
    i64 temp = s - i * m;
    if (temp > 0 && temp % (n - i) == 0 && temp / (n - i) <= m) {
      flag = true;
      break;
    }
    temp = s - (n - i) * m;
    if (temp > 0 && temp % i == 0 && temp / (n - i) <= m) {
      flag = true;
      break;
    }
    i64 a = i, b = n - i;
    if (a > b) {
      std::swap(a, b);
    }
    if (a == b) {
      if (s % a == 0 && s / a <= 2 * m) {
        flag = true;
        break;
      }
    } else {
      if ((s - b * m) % (a - b) == 0) {
        i64 x = (s - b * m) / (a - b);
        if (x > 0 && x < m && a * x + b * (m - x) == s) {
          flag = true;
          break;
        }
      }
    }
  }
  if (flag) {
    printf("2\n");
  } else {
    printf("3\n");
  }
  return 0;
}
