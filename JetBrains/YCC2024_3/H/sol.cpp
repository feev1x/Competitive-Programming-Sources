/**
 *    author:  feev1x
 *    created: 29.10.2024 15:45:52
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

bool is(const std::string& text, const std::string& pattern) {
  int n = text.size(), m = pattern.size();
  if (m == 0) return true;
  if (n < m) return false;

  std::vector<int> prefix(m, 0);
  for (int i = 1, j = 0; i < m; )
    if (pattern[i] == pattern[j]) prefix[i++] = ++j;
    else if (j > 0) j = prefix[j - 1];
    else prefix[i++] = 0;

  for (int i = 0, j = 0; i < n; )
    if (text[i] == pattern[j]) { i++; j++; if (j == m) return true; }
    else if (j > 0) j = prefix[j - 1];
    else i++;

  return false;
}

vector<int> pref(string s) {
  int n = s.size();
	vector<int> p(n);                              
	for (int i = 1; i < n; ++i) {                   
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
  return p;
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> s(3);
  for (auto &u: s) cin >> u;
  if (is(s[0], s[1])) {
    s.erase(++s.begin());
  } else if (is(s[1], s[0])) {
    s.erase(s.begin());
  } else if (is(s[0], s[2])) {
    s.erase(--s.end());
  } else if (is(s[2], s[0])) {
    s.erase(s.begin());
  } else if (is(s[1], s[2])) {
    s.erase(--s.end());
  } else if (is(s[2], s[1])) {
    s.erase(++s.begin());
  }
  if (s.size() == 2) {
    if (is(s[0], s[1])) {
      s.erase(--s.end());
    } else if (is(s[1], s[0])) {
      s.erase(s.begin());
    }
  }
  sort(s.begin(), s.end());
  int res = 0;
  for (auto u: s) res += u.size();
  do {
    string ans = s[0];
    for (int i = 1; i < s.size(); ++i) {
      string nw = s[i] + ans;
      auto p = pref(nw);
      if (p.back() >= s[i].size()) continue;
      int sm = p.back();
      while (sm < s[i].size()) {
        ans += s[i][sm++];
      }
    }
    res = min(res, int(ans.size()));
  } while (next_permutation(s.begin(), s.end()));
  cout << res << '\n';
  return 0;
}
