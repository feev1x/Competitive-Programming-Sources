/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
class segtree { 
  int n;
  vector<int> t;
  int64_t val(int v, int tl, int tr, int pos) {
    if (tl == tr) {
      return t[v];
    }
    int tm = tl + tr >> 1;
    if (pos <= tm) {
      return t[v] + val(v << 1, tl, tm, pos);
    }
    return t[v] + val(v << 1 | 1, tm + 1, tr, pos);
  }
  void update(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
      t[v]++;
      return;
    }
    if (tl > r || l > tr) {
      return;
    }
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r);
    update(v << 1 | 1, tm + 1, tr, l, r);
  }
public:
  segtree(int n) {
    this->n = n;
    t.assign(n * 4 + 1, 0);
  }
  int64_t num(int i) {
    return val(1, 1, n, i);
  }
  void modify(int l, int r) {
    update(1, 1, n, l, r);
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int64_t> a(n + 1), cnd(m + 1), p(n + 1), ad(n + 1), mxx(n + 1), um(n + 1);
  set<pair<int64_t, int>> st;
  map<int64_t, bool> mp;
  int64_t mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (mx < a[i]) {
      mp[i] = true;
      st.emplace_back(a[i], i);
      um[i] = a[i] - mx;
      mx = a[i];
    }
    mxx[i] = mx;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> cnd[i];
    auto it = st.lower_bound({cnd[i], -1}); 
    if (it == st.end()) {
      p[n]++;
    } else if (it->first == cnd[i]) {
      p[it->second]++;
    } else {
      a[it->second] -= (a[it->second] - cnd[i]);
    }
  }
}

