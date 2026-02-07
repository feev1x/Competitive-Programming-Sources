#include <bits/stdc++.h>
using namespace std;

// #define int long long

using ll = long long;

const int N = 2e5 + 5, mod = 1e9 + 7;

int p[N];

int mul(const int &a, const int &b) {
  return (ll)a * b % mod;
}

void add_self(int &a, const int &b) {
  a += b;
  if(a >= mod) a -= mod;
}

void solve() {
  p[0] = 1;
  
  for(int i = 1; i < N; i++) {
    p[i] = mul(p[i - 1], 2);
  }
  
  int n, m, q; cin >> n >> m >> q;
  
  vector<int> a(n + 1);
  
  while(m--) {
    int l, r; cin >> l >> r;
    
    l--;
    
    a[l] ^= 1;
    a[r] ^= 1;
  }
  
  // cout << "a: " << '\n';
  
  for(int i = 0; i < n; i++) {
    a[i + 1] ^= a[i];
    // cout << a[i];
  }
  
  // cout << '\n';
  
  vector<int> suf(n + 1);
  
  for(int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + (a[i] == 0);
  }
  
  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    
    l--;
    
    vector<int> f1;
    
    for(int i = l; i < r && (int)f1.size() < k; i++) {
      if(a[i] == 1) {
        f1.push_back(i);
      }
    }
    
    int sz = f1.size();
    
    int res = 0;
    
    for(int i = 0; i < sz; i++) {
      add_self(res, p[min((suf[f1[i]] - suf[r]) + (sz - i - 1), k - i - 1)]);
    }
    
    cout << res << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
