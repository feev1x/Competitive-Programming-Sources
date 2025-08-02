#include "bits/stdc++.h"
#define nemeshay ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
#define int long long
#define sigma signed 
#define pb push_back
#define fr first 
#define sc second
#define pii pair<int, int>
#define ar array
using namespace std;
const int N = 1e6 + 12, inf = 1e18 + 7, mod = 1e9 + 7;
bool a[N], b[N], probel[N];
string ok;
bool check(string s, string l) {
  int n = s.size(), m = l.size();
  if (n >= m) {
    for (int i = n - m; i < n; i++) {
      if (s[i] != l[i - (n - m)]) break;
      if (i == n - 1) return 1;
    }
  }
  return 0;
}
string rec(int ind, string s, string l){
  if (check(s, l)) return "";
  if (ind == ok.size() - 1) return s;
  if (b[ind + 1]) {
    for (char i = '0'; i <= '9'; i++) {
      if (a[ind + 1] && i == '0') continue;
      string ret = rec(ind + 1, s + i, l);
      if (ret.size()) return ret;
    }
    return "";
  }
  else return rec(ind + 1, s + ok[ind + 1], l);
}
void test_case() {
  string s, l;
  cin >> s;
  getline(cin, l);
  getline(cin, l);
  vector <string> pon{""};
  for (auto j: l) {
    if (j == ' ') pon.pb("");
    else pon.back() += j;
  }
  l = "";
  for (int i = 0; i < pon.size(); i++) {
    if (pon[i].size() > 1) a[l.size()] = 1;
    if (i) probel[l.size()] = 1;
    l += pon[i];
  }
  string ladno = "";
  for (int i = 0; i < l.size(); i++) {
    ladno += l[i];
    if (check(ladno, s)) for (int j = i - s.size() + 1; j <= i; j++) b[j] = 1;
  } 
  ok = l;
  string ans = rec(-1, "", s);
  for (int i = 0; i < ans.size(); i++) {
    if (probel[i]) cout << ' ';
    cout << ans[i];
  } 
  assert(ans.size());
  cout << '\n';
  
}
sigma main() {
  nemeshay
  int t = 1;
  while (t--) test_case();
}
