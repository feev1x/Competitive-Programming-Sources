/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

class segtree {
  int n;
  vector<int> t;
  void update(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) {
      return;
    }
    if (l <= tl && tr <= r) {
      t[v]++;
      return;
    }
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r);
    update(v << 1 | 1, tm + 1, tr, l, r);
  }
  int vl(int v, int tl, int tr, int pos) {
    if (tl == tr) {
      return t[v];
    }
    int tm = tl + tr >> 1;
    if (pos <= tm) {
      return t[v] + vl(v << 1, tl, tm, pos);
    }
    return t[v] + vl(v << 1 | 1, tm + 1, tr, pos);
  }
public:
  segtree(int n) {
    this->n = n;
    t.assign(n * 4 + 1, 0);
  }
  int val(int pos) {
    return vl(1, 1, n, pos);
  }
  void modify(int l, int r) {
    update(1, 1, n, l, r);
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> h(n);
  for (auto &u: h) cin >> u;
  vector<int64_t> val(n);
  stack<pair<int, int>> st;
  int64_t cnt = 0;
  segtree t(n);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && st.top().first <= h[i]) {
      st.pop();
    }
    if (st.empty()) {
      val[i] = i;
      t.modify(1, i);
    } else {
      val[i] = (i - st.top().second);
      t.modify(st.top().second + 1, i);
    }
    st.emplace(h[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << t.val(i) << ' ';
  }
}

