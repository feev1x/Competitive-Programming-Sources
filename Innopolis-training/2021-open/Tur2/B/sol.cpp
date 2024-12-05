/**
 *    author:  feev1x
 *    created: 20.11.2024 09:11:37
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  std::vector<int> sr;
  std::map<int, std::map<int, std::set<int>>> pos;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sr = a;
  std::sort(sr.begin(), sr.end());
  for (int i = 0; i < n; ++i) {
    pos[sr[i]][a[i]].emplace(i);
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    if (sr[i] == a[i]) continue;
    if (pos[a[i]][sr[i]].empty()) {
      printf("No\n");
      exit(0);
    }
    int j = *pos[a[i]][sr[i]].begin();
    pos[a[i]][sr[i]].erase(pos[a[i]][sr[i]].begin());
    pos[sr[i]][a[i]].erase(i);
    ans.emplace_back(i + 1, j + 1);
    std::swap(a[i], a[j]);
  }
  if (sr == a) {
    printf("Yes\n%d\n", (int)ans.size());
    for (auto [u, v]: ans) {
      printf("%d %d\n", u, v);
    }
  } else {
    printf("No\n");
  }
  return 0;
}
