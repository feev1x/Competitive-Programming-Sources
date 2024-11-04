/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
#define int int64_t
void rec(int n, int i) {
  if (n % i == 0 && n / i >= i) {
    cout << i << '\n';
  } else if (n % i == 0) return;
  if (n / (i + 1) >= (i + 1)) rec(n, i + 1);
  if (n % i == 0 && n / i > i) {
    cout << n / i << '\n';
  }
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  rec(n, 1);
}

