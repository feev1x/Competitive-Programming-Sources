#include "grader.h"
#include <bits/stdc++.h>

using i64 = long long;

// to compile: g++ grader.cpp solution.cpp -o test.exe
std::string find_next(std::string str) {
  std::string s = str;
  int k = s.size();
  std::map<char, char> next;
  next['A'] = 'C';
  next['C'] = 'G';
  next['G'] = 'T';
  next['T'] = '-';
  if (get_min_max(str).first == str) {
    return str;
  }
  int l = 0, r = k - 1, ans = 0;
  while (l <= r) {
    int m = l + r >> 1;
    s = str;
    for (int i = k - 1; i >= m; --i) {
      s[i] = '_';
    }
    if (get_min_max(s).first == "") {
      r = m - 1;
    } else {
      l = m + 1;
      ans = m;
    }
  }
  s = str;
  for (int i = k - 1; i > ans; --i) {
    s[i] = '_';
  }
  for (int i = ans; i >= 0; --i) {
    s[i] = '?';
    auto pr = get_min_max(s);
    if (pr.second[i] <= str[i]) {
      s[i] = '_';
      continue;
    }
    pr = std::pair{"", ""};
    char ch = next[str[i]];
    while (ch != '-') {
      s[i] = ch;
      pr = get_min_max(s);
      if (pr.first != "") {
        break;
      }
      ch = next[ch];
    }
    str[i] = s[i];
    for (int j = i + 1; j < k; ++j) {
      str[j] = '?';
    }
    pr = get_min_max(str);
    return pr.first;
  }
	return "";
}

