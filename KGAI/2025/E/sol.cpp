/**
 *    author:  feev1x
 *    created: 22.12.2024 14:12:25
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s, t; std::cin >> s >> t;  
  if (s[0] != t[0]) {
    std::cout << "NO\n";
    exit(0);
  }
  if (s == t) {
    std::cout << "YES\n";
    exit(0);
  }
  std::deque<char> dq;
  for (int i = 0, j = 0; i < t.size() && j < s.size(); ++i, ++j) {
    if (s[j] != t[i]) {
      i--;
      if ((int)dq.size() & 1) {
        continue;
      }
      if (dq.empty()) {
        std::cout << "NO\n";
        exit(0);
      }
      i--;
      dq.pop_back();
    } else {
      dq.emplace_back(s[j]);
    }
  }
  if (dq.size() != t.size()) {
    std::stack<int> st;
    for (int i = s.size() - 1, j = t.size() - 1; i >= 0 && j > 0; --i) {
      if (s[i] == t[j]) {
        st.emplace(i);
        j--;
      }
    }
    if (st.size() != t.size() - 1) {
      std::cout << "NO\n";
      exit(0);
    }
    bool flag = false;
    for (int i = 0; st.size() && i < s.size();) {
      int j = st.top();
      st.pop();
      if (j - i == 1) {
        i = j;
        continue;
      }
      if (i % 2 == 1 && j % 2 == 1 && j - i == 2) {
        std::cout << "NO\n";
        exit(0);
      }
      flag = true;
      break;
    }
    if (!flag) {
      if (int(t.size()) & 1) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    } else {
      std::cout << "YES\n";
    }
  } else {
    std::cout << "YES\n";
  }
  return 0;
}
