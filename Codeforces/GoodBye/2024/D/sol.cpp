/**
 *    author:  feev1x
 *    created: 28.12.2024 21:43:54
**/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
  
#define ordered_set tree<std::pair<int, int>, null_type,less<std::pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
 
using i64 = long long;

constexpr int MOD = 998244353;

inline int mul(int a, int b) {
  return (i64)a * b % MOD;
}

inline int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}
 
inline int divide(int a, int b) {
  return (i64)a * binpow(b, MOD - 2) % MOD;
}

inline int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, q; scanf("%d%d", &n, &q);
    std::vector<int> a(n), pos(n), b(n);
    ordered_set st, st1;
    for (auto &u: a) {
      scanf("%d", &u);
    }
    for (auto &u: b) {
      scanf("%d", &u);
    }
    for (int i = 0; i < n; ++i) {
      pos[i] = i;
      st.insert({a[i], i});
      st1.insert({b[i], i});
    }
    std::sort(pos.begin(), pos.end(), [&](int i, int j) {
        return a[i] < a[j];
        });
    int sm = 0;
    int res = 1;
    for (auto [key, v]: st1) {
      res = mul(res, min(key, a[pos[sm++]]));
    }
    printf("%d ", res);
    while (q--) {
      int o, x; scanf("%d%d", &o, &x); x--;
      if (o == 1) {
        st.erase({a[x], x});
        a[x]++;
        st.insert({a[x], x});
        int i = st.order_of_key({a[x], -1});
        int val = st1.find_by_order(i)->first;
        if (min(val, a[x] - 1) != min(val, a[x])) {
          res = divide(res, min(val, a[x] - 1));
          res = mul(res, min(val, a[x]));
        }
      } else {
        st1.erase({b[x], x});
        b[x]++;
        st1.insert({b[x], x});
        int i = st1.order_of_key({b[x], -1});
        int val = st.find_by_order(i)->first;
        if (min(val, b[x] - 1) != min(val, b[x])) {
          res = divide(res, min(val, b[x] - 1));
          res = mul(res, min(val, b[x]));
        }
      }
      printf("%d ", res);
    }
    printf("\n");
  }
  return 0;
}

