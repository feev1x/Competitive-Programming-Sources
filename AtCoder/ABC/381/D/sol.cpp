/**
 *    author:  feev1x
 *    created: 05.12.2024 09:14:47
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n), p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i) {
      p[i] = p[i - 1] + (a[i] == a[i - 1]);
    }
  }
  int l = 0, r = n & 1 ? n - 1 : n, ans = 0;
  while (l <= r) {
    int m = l + r >> 1;
    if (m & 1) {
      m++;
    }
    std::vector<int> cnt(n + 1);
    std::multiset<int> st;
    for (int i = 0; i < m; ++i) {
      if (cnt[a[i]] != 2 && cnt[a[i]] != 0) {
        st.erase(st.find(cnt[a[i]]));
      }
      cnt[a[i]]++;
      if (cnt[a[i]] != 2) {
        st.emplace(cnt[a[i]]);
      }
    }
    bool flag = st.empty() && (m == 0 || p[m - 1] == m / 2);
    for (int i = 0; !flag && i + m < n; ++i) {
      if (cnt[a[i]] != 2 && cnt[a[i]] != 0) {
        st.erase(st.find(cnt[a[i]]));
      }
      cnt[a[i]]--;
      if (cnt[a[i]] != 2 && cnt[a[i]] != 0) {
        st.emplace(cnt[a[i]]);
      }
      i += m;
      if (cnt[a[i]] != 2 && cnt[a[i]] != 0) {
        st.erase(st.find(cnt[a[i]]));
      }
      cnt[a[i]]++;
      if (cnt[a[i]] != 2 && cnt[a[i]] != 0) {
        st.emplace(cnt[a[i]]);
      }
      i -= m;
      flag = st.empty() && p[i + m] - p[i + 1] == m / 2;
    }
    if (flag) {
      l = m + 2;
      ans = m;
    } else {
      r = m - 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}
