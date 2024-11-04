/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(m + 1), b(m + 1);
  vector<int64_t> c(m + 1);
  vector<vector<pair<int, int64_t>>> g(n + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    g[a[i]].emplace_back(b[i], c[i]);
    g[b[i]].emplace_back(a[i], c[i]);
  }
  vector<int64_t> d1(n + 1, 1e18), dn(n + 1, 1e18), cnt1(n + 1), cntn(n + 1);
  set<pair<int64_t, int>> q;
  cnt1[1] = 1;
  cntn[n] = 1;
  d1[1] = 0;
  dn[n] = 0;
  q.emplace(d1[1], 1);
  while (!q.empty()) {
    int cur = q.begin()->second;
    if (cnt1[cur] == 0) cnt1[cur] = 1;
    q.erase(q.begin());
    for (auto [to, w]: g[cur]) {
      if (d1[to] == d1[cur] + w) {
        cnt1[to] += cnt1[cur];
        q.emplace(d1[to], to);
      }
      if (d1[to] > d1[cur] + w) {
        q.erase({d1[to], to});
        d1[to] = d1[cur] + w;
        cnt1[to] = cnt1[cur];
        q.emplace(d1[to], to);
      }
    }
  }
  q.emplace(dn[n], n);
  while (!q.empty()) {
    int cur = q.begin()->second;
    if (cntn[cur] == 0) cntn[cur] = 1;
    q.erase(q.begin());
    for (auto [to, w]: g[cur]) {
      if (dn[to] == dn[cur] + w) {
        cntn[to] += cntn[cur];
        q.emplace(dn[to], to);
      }
      if (dn[to] > dn[cur] + w) {
        q.erase({dn[to], to});
        dn[to] = dn[cur] + w;
        cntn[to] = cntn[cur];
        q.emplace(dn[to], to);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (cnt1[a[i]] != cnt1[b[i]] || cntn[a[i]] != cntn[b[i]]) {
      cout << "No\n";
      continue;
    }
    if (d1[a[i]] + dn[b[i]] + c[i] == d1[n]) {
      if (d1[b[i]] + dn[a[i]] + c[i] == d1[n]) {
        assert(cnt1[a[i]] * cntn[b[i]] + cnt1[b[i]] * cntn[a[i]] <= cnt1[n]);
        if (cnt1[a[i]] + cntn[b[i]] + cnt1[b[i]] * cntn[a[i]] == cnt1[n]) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      } else {
        if (cnt1[a[i]] * cntn[b[i]] == cnt1[n]) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      }
    } else if (d1[b[i]] + dn[a[i]] + c[i] == d1[n]) {
      if (cnt1[b[i]] * cntn[a[i]] == cnt1[n]) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      cout << "No\n";
    }
  }
}

