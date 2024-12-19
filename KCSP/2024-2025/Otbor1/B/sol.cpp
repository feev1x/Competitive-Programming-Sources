/**
 *    author:  feev1x
 *    created: 08.12.2024 11:10:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::deque<int> st;
  for (int i = 1; i <= n; ++i) {
    int u; scanf("%d", &u);
    while (u--) {
      if (st.size() && st.front() != i) {
        st.pop_front();
      }
      st.emplace_back(i);
    }
    if (i > 1) {
      printf("%d ", i - st.front());
    }
  }
  printf("\n");
  return 0;
}
