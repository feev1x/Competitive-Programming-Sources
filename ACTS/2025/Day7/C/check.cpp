#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ifstream fin("input", std::ifstream::in);
  std::ifstream ans("MyAns", std::ifstream::in);
  std::ifstream cor("CorrectAns", std::ifstream::in);
  int an, cr; ans >> an; cor >> cr;

  if (an != cr)
      return -1;

  return 0;
}
