#include <bits/stdc++.h>
using namespace std;

#include "grader.h"

// generate string of k blocks from alphabet a
// each block of size from L to R, neighbouring blocks are different
// total length from Lk to Rk, avg of (L+R)k/2
mt19937 rnd(603543658);
string generate(int k, int a, int L = 1000, int R = -1) {
    string from;
    for (int i = 0; i < 26; i++)
        from.push_back('a' + i);
    for (int i = 0; i < 26; i++)
        from.push_back('A' + i);
    for (int i = 0; i < 10; i++)
        from.push_back('0' + i);
    if (R == -1)
        R = 2 * L;

	uniform_int_distribution<int> distrib_len(L, R);
	uniform_int_distribution<int> distrib_alphabet(0, a - 1);

    string s;
    int last = 0;
    for (int i = 0; i < k; i++) {
        while (true) {
            int c = distrib_alphabet(rnd);
            if (c != last) {
                last = c;
                break;
            }
        }
        string t(distrib_len(rnd), from[last]);
        s += t;
    }
    return s;
}

int main() {
  ios::sync_with_stdio(0);
  // reads number of tests, k, a
  int n = 5, k, a;
  cin >> k >> a;
  double score = 0;
  for (int i = 0; i < n; i++) {
      string s = generate(k, a);
      vector<int> g = split(s, k, a);
      vector<string> t;
      int it = 0;
      for (int x : g) {
        t.push_back(s.substr(it, x));
        it += x;
      }
      shuffle(t.begin(), t.end(), rnd);
      string s1 = merge(t);
      if (s1 != s) {
          cout << "WA\n";
          cout << "strings don't match\n";
          cout << "expected:\n" << s << '\n';
          cout << "found:\n" << s1 << '\n';
          return 0;
      }
      score += pow(g.size() / (double)s.size(), 4);
  }
  score /= n;
  cout << "OK\nScore: " << fixed << setprecision(3) << score * 4 << '\n';
}
