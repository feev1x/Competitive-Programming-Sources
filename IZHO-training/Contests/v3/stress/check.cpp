#include "bits/stdc++.h"

using i64 = long long;

int main() {
  std::ifstream fin("input", std::ifstream::in);
  std::ifstream ans("MyAns", std::ifstream::in);
  std::ifstream cor("CorrectAns", std::ifstream::in);
  int n, q; fin >> n >> q;
  while (q--) {
    int myans; ans >> myans;
    int cans; cor >> cans;
    if (myans != cans) {
      std::cout << "Wrong Answer! expected: " << cans << " found: " << myans << '\n';
      return -1;
    }
  }
  return 0;
}
