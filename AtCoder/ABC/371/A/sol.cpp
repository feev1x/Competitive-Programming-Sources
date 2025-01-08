/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char ab, ac, bc; cin >> ab >> ac >> bc;
  int md = 0;
  int a = 0, b = 0, c = 0;
  if (ab == '>') a++;
  else b++;
  if (ac == '>') a++;
  else c++;
  if (bc == '>') b++;
  else c++;
  if (a == 1) cout << "A";
  else if (b == 1) cout << "B";
  else cout << "C";
}

