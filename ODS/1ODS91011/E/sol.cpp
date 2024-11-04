/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<bool> prime(201, true);  
  prime[1] = false;
  for (int i = 2; i * i <= 200; ++i) {
    if (prime[i]) {
      for (int j = i + i; j <= 200; j += i) {
        prime[j] = false;
      }
    }
  }
  int a, b, c, d; cin >> a >> b >> c >> d;
  bool flag = false;
  for (int i = a; i <= b; ++i) {
    bool can = true;
    for (int j = c; j <= d; ++j) {
      if (prime[i + j]) {
        can = false;
        break;
      }
    }
    if (can) flag = true;
  }
  if (!flag) cout << "Symovar\n";
  else cout << "Inovak\n";
}

