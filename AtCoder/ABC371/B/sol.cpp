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
  vector<bool> A(n);
  for (int i = 0; i < m; ++i) {
    int a; cin >> a;
    char b; cin >> b;
    if (b == 'M' && !A[a]) {
      A[a] = 1;
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

