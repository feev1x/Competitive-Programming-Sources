/**
 *    author:  feev1x
 *    created: 14.10.2024 18:50:32
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<vector<double>>> p(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
  vector<vector<vector<double>>> ex(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1)));
  vector<int> cnt(4);
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    cnt[u]++;
  }
  p[cnt[1]][cnt[2]][cnt[3]] = 1;
  for (double c = n; c >= 0; --c) {
    for (double b = n; b >= 0; --b) {
      for (double a = n; a >= 0; --a) {
        if (n < a + b + c || a + b + c == 0) {
          continue;
        }
        double pzr = ((double)n - (a + b + c)) / n;
        double ev = pzr / (1 - pzr) + 1;
        ex[a][b][c] += ev * p[a][b][c];
        if (a) {
          double pb = (double)a / (a + b + c);
          p[a - 1][b][c] += p[a][b][c] * pb;
          ex[a - 1][b][c] += ex[a][b][c] * pb;
        }
        if (b) {
          double pb = (double)b / (a + b + c);
          p[a + 1][b - 1][c] += p[a][b][c] * pb;
          ex[a + 1][b - 1][c] += ex[a][b][c] * pb;
        }
        if (c) {
          double pb = (double) c / (a + b + c);
          p[a][b + 1][c - 1] += p[a][b][c] * pb;
          ex[a][b + 1][c - 1] += ex[a][b][c] * pb;
        }
      }
    }
  }
  cout << fixed << setprecision(10) << ex[0][0][0] << '\n';
}
