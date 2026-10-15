#include "Anna.h"
#include <bits/stdc++.h>

namespace {

std::vector<int> p{12, 31, 48, 59, 19, 50, 22, 46, 42, 38, 15, 28, 24, 10, 4, 47, 41, 40, 7, 37, 29, 58, 2, 1, 26, 62, 13, 33, 39, 17, 49, 21, 30, 53, 44, 6, 34, 11, 43, 25, 14, 60, 55, 23, 35, 56, 20, 61, 3, 51, 5, 32, 16, 57, 52, 8, 63, 36, 9, 0, 45, 18, 27, 54};

}

void Anna(int X, int Y, int N, std::string S) {
  int j = 0;
  for (int i = 0; i < N; ++i, ++j) {
    int x = p[j] / 8, y = p[j] % 8;
    if (x == X || y == Y) {
      --i;
      continue;
    }
    if (S[i] == 'A') Paint(x, y, 0);
    else Paint(x, y, 1);
  }
  int num = (X << 3) + Y;
  for (int nw = 0; j < 56; ++j) {
    int x = p[j] / 8, y = p[j] % 8;
    if (x == X || y == Y) continue;
    Paint(x, y, num >> nw & 1);
    nw = (nw + 1) % 6;
  }
  auto Get = [&](int i) {
    if (i >= 0 && i < 8 && (i == X || i == Y)) return true;
    return false;
  };
  for (int i = 0; i < 8; ++i) if (i != X && i != Y) Paint(i, i, int(Get(i - 1) | Get(i + 1)));
}
