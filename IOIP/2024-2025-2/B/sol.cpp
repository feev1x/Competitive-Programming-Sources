/**
 *    author:  feev1x
 *    created: 06.12.2024 10:23:23
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5;

char S[MXSZ];

struct Node {
  Node* t[26];
  i64 cnt;
  bool used;
  Node() {
    cnt = 0;
    used = false;
    for (int i = 0; i < 26; ++i) {
      t[i] = nullptr;
    }
  }
  inline void inc() {
    cnt++;
  }
  inline void use() {
    used = true;
  }
};

Node* root = new Node();

int main() {
  int n, m; scanf("%d%d", &n, &m);
  for (int j = 0; j < n; ++j) {
    scanf("%s", S);
    std::string s = S;
    Node* pt = root;
    for (int i = 0; i < (int)s.size(); ++i) {
      int v = s[i] - 'a';
      if (pt->t[v] == nullptr) {
        pt->t[v] = new Node();
      }
      pt = pt->t[v];
      pt->inc();
    }
  }
  i64 res = 0;
  std::vector<std::string> a(m);
  for (auto &u: a) {
    scanf("%s", S);
    u = S;
  }
  std::sort(a.begin(), a.end(), [](const std::string &s1, const std::string &s2) {
      return s1.size() < s2.size();
      });
  for (auto s: a) {
    Node *pt = root;
    bool flag = true;
    for (int i = 0; i < (int)s.size(); ++i) {
      int v = s[i] - 'a';
      if (pt->t[v] == nullptr || pt->t[v]->used) {
        flag = false;
        break;
      }
      pt = pt->t[v];
    }
    if (flag) {
      i64 cnt = pt->cnt;
      res += (cnt * (cnt - 1)) / 2;
      pt->use();
    }
  }
  printf("%lld\n", res);
  return 0;
}

