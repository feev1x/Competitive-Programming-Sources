/**
 *    author:  feev1x
 *    created: 17.11.2024 16:56:24
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  auto Ask = [&](int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    char ch; scanf(" %c", &ch);
    assert(ch == '+' || ch == '-');
    return ch;
  };
  auto Report = [&](int x, char y) {
    printf("! %c%d\n", y, x);
    fflush(stdout);
  };
  std::vector<int> ul, dr;
  for (int i = 4; i > 0; i >>= 1) {
    if (Ask(-i, i) == '+') {
      ul.emplace_back(i);
    }
  }
  std::map<std::vector<int>, int> order;
  order[{4, 2, 1}] = 1;
  order[{4, 2}] = 2;
  order[{4, 1}] = 3;
  order[{4}] = 4;
  order[{2, 1}] = 5;
  order[{2}] = 6;
  order[{1}] = 7;
  order[{}] = 8;
  if (Ask(1, 1) == '+') {
    for (int i = 4; i > 0; i >>= 1) {
      if (Ask(i, i) == '+') {
        dr.emplace_back(i);
      }
    }
    Report(order[ul] - 1 - (8 - order[dr]), 'h' - order[ul] + 1);
  } else {
    for (int i = 4; i > 0; i >>= 1) {
      if (Ask(i, -i) == '+') {
        dr.emplace_back(i);
      }
    }
    Report(order[ul], 'h' - order[ul] + order[dr]);
  }
  return 0;
}
