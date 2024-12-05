/**
 *    author:  feev1x
 *    created: 19.11.2024 09:01:12
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  char S[1001]; scanf("%s", S);
  std::string s = S, a, b;
  std::sort(s.begin(), s.end());
  a = s;
  std::deque<char> dq;
  int mx = 0, cnt = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      mx = std::max(mx, cnt);
      cnt = 1;
    }
  }
  mx = std::max(mx, cnt);
  b.resize(s.size());
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int j = (i + mx) % n;
    b[j] = a[i];
    if (a[j] == b[j]) {
      printf("IMPOSSIBLE\n");
      exit(0);
    }
  }
  printf("%s\n%s\n", a.c_str(), b.c_str());
  return 0;
}
