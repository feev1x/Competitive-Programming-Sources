#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<int>(l, r)(rng)

void solve() {
  int n = rnd(1, 5), m = rnd(1, 5), q = rnd(1, 5);
  
  cout << n << ' ' << m << ' ' << q << '\n';
  
  while(m--) {
    int l = rnd(1, n), r = rnd(1, n);
    if(l > r) swap(l, r);
    cout << l << ' ' << r << '\n';
  }
  
  while(q--) {
    int l = rnd(1, n), r = rnd(1, n);
    if(l > r) swap(l, r);
    cout << l << ' ' << r << ' ' << rnd(1, r - l + 1) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
