/**
 *    author:  feev1x
 *    created: 30.11.2024 12:18:21
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MX = 1e5;

int main() {
  int a, b; scanf("%d%d", &a, &b);
  std::vector<int> p(MX, -1);
  std::queue<int> q;
  q.emplace(a);
  p[a] = 0;
  while (q.size()) {
    int v = q.front();
    q.pop();
    if (v == b) {
      break;
    }
    if (v / 1000 < 9 && p[v + 1000] == -1) {
      p[v + 1000] = v;
      q.emplace(v + 1000);
    }
    if (v % 10 > 1 && p[v - 1] == -1) {
      p[v - 1] = v;
      q.emplace(v - 1);
    }
    int nx = v / 10 + (v % 10) * 1000;
    if (nx != v && p[nx] == -1) {
      p[nx] = v;
      q.emplace(nx);
    }
    nx = (v % 1000) * 10 + v / 1000;
    if (nx != v && p[nx] == -1) {
      p[nx] = v;
      q.emplace(nx);
    }
  }
  std::deque<int> res;
  for (int v = b; v != 0; v = p[v]) {
    res.emplace_front(v);
  }
  for (auto u: res) {
    printf("%d\n", u);
  }
  return 0;
}
