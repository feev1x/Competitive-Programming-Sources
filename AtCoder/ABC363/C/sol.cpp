/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

bool palind(string s) {
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  sort(s.begin(), s.end());
  int cnt = 0;
  do {
    cnt++;
    for (int i = k - 1; i < n; ++i) {
      if (palind(s.substr(i - k + 1, k))) {
        cnt--;
        break;
      }
    }
  } while (next_permutation(s.begin(), s.end()));
  cout << cnt << '\n';
}

