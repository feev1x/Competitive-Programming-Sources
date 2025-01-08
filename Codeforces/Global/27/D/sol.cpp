/**
 *    author:  feev1x
 *    created: 27.10.2024 22:23:17
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

int mul(int a, int b) {
  return int64_t(a) * b % mod;
}

void mul_self(int &a, int b) {
  a = mul(a, b);
}

void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int add(int a, int b) {
  int res = a + b;
  if (res >= mod) {
    res -= mod;
  }
  return res;
}

int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      mul_self(res, a);
    }
    a = mul(a, a);
    n /= 2;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n), p(n), gr(n, -1), mal(n), sum(n), js(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int u; cin >> u;
      a[i] = u;
      while (u % 2 == 0) {
        cnt++;
        u /= 2;
      }
      if (i) js[i] = js[i - 1];
      js[i] += u;
      mal[i] = u;
      p[i] = cnt;
    }
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && st.top().first < a[i]) {
        st.pop();
      }
      gr[i] = (st.empty() ? -1 : st.top().second);
      st.emplace(mal[i], i);
    }
    auto Count = [&](int l, int r) {
      return l == 0 ? p[r] : p[r] - p[l - 1];
    };
    auto Sum = [&](int l, int r) {
      return l == 0 ? js[r] : js[r] - js[l - 1];
    };
    for (int i = 0; i < n; ++i) {
      if (i) {
        if (gr[i] != -1) {
          sum[i] = add(add(sum[gr[i]], Sum(gr[i] + 1, i)) - mal[i], 
                       mul(mal[i], binpow(2, Count(gr[i] + 1, i))));
        } else {
          sum[i] = add(js[i] - mal[i], mul(mal[i], binpow(2, p[i])));
        }
      } else {
        sum[i] = a[i];
      }
      cout << sum[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
