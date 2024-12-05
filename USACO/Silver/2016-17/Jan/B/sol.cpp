/**
 *    author:  feev1x
 *    created: 03.12.2024 15:37:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("hps.in", "r", stdin);
  std::freopen("hps.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> ph(n + 1), pp(n + 1), ps(n + 1), pref(n + 1);
  std::vector<int> sh(n + 1), sp(n + 1), ss(n + 1), suf(n + 1);
  for (int i = 1; i <= n; ++i) {
    char ch; scanf(" %c ", &ch);
    ph[i] = ph[i - 1];
    pp[i] = pp[i - 1];
    ps[i] = ps[i - 1];
    switch(ch) {
      case 'H':
        ph[i]++;
        break;
      case 'P':
        pp[i]++;
        break;
      default:
        ps[i]++;
        break;
    };
    pref[i] = std::max({ph[i], pp[i], ps[i]});
  }
  for (int i = n; i >= 1; --i) {
    sh[i] = ph[n] - ph[i - 1];
    sp[i] = pp[n] - pp[i - 1];
    ss[i] = ps[n] - ps[i - 1];
    suf[i] = std::max({sh[i], sp[i], ss[i]});
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = std::max(res, pref[i - 1] + suf[i]);
  }
  printf("%d\n", res);
  return 0;
}
