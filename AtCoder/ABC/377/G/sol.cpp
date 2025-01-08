/**
 *    author:  feev1x
 *    created: 04.11.2024 18:39:49
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

struct Node {
  vector<Node*> next;
  int dep, mndep;
  Node(int _dep, int _mndep) : dep(_dep), mndep(_mndep) {
    next.assign(26, nullptr);
  }
};

Node* root = new Node(0, 1e9);

signed main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char *S; scanf("%ms", &S);
    string s = S;
    free(S);
    int res = s.size();
    auto ptr = root;
    int j;
    for (j = 0; j < s.size(); ++j) {
      int nx = s[j] - 'a';
      if (ptr->next[nx] == nullptr) {
        break;
      }
      ptr = ptr->next[nx];
      res = min(res, ptr->mndep - ptr->dep + int(s.size() - j - 1));
      ptr->mndep = min(ptr->mndep, int(s.size()));
    }
    debug(s, j);
    for (; j < s.size(); ++j) {
      int nx = s[j] - 'a';
      ptr->next[nx] = new Node(ptr->dep + 1, int(s.size()));
      ptr->mndep = min(ptr->mndep, int(s.size()));
      ptr = ptr->next[nx];
    }
    printf("%d\n", res);
  }
  return 0;
}
