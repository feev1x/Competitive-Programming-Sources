/**
 *    author:  feev1x
 *    created: 15.11.2024 09:01:15
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 n, m, h, w; scanf("%lld%lld%lld%lld", &n, &m, &h, &w);  
  i64 n1 = n, m1 = m, h1 = h, w1 = w;
  if (n > m) {
    std::swap(n, m);
    std::swap(n1, m1);
  }
  if (h > w) {
    std::swap(h, w);
    std::swap(h1, w1);
  }
  std::swap(n1, m1);
  i64 cnt = 0, cnt1 = 0;
  while (n > h) {
    n /= 2;
    cnt++;
  }
  while (m > w) {
    m /= 2;
    cnt++;
  }
  while (n1 > h1) {
    n1 /= 2;
    cnt1++;
  }
  while (m1 > w1) {
    m1 /= 2;
    cnt1++;
  }
  printf("%lld\n", std::min(cnt1, cnt));
  return 0;
}
