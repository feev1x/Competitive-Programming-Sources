/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  map<int, vector<int>> mp;
  for (int i = 0; i < s.size(); ++i) {
    mp[s[i]].emplace_back(i);
  }
  int64_t res = 0;
  for (auto [key, a]: mp) {
    if (a.size() <= 1) continue;
    int64_t l = 0, r = a.size();
    for (int i = 0; i < a.size(); ++i) {
      int64_t dis = 0;
      if (i) {
        dis = a[i] - a[i - 1] - 1;
      }
      res += dis * l * r;
      res += max(int64_t(0), ((r - 1) * l));
      l++;
      r--;
    }
  } 
  cout << res << '\n';
}

