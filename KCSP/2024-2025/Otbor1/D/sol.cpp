/**
 *    author:  feev1x
 *    created: 08.12.2024 11:37:22
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15, INF = 1e9;

char S[MXSZ];

int main() {
  int n; scanf("%d", &n);
  std::vector<std::string> s(n);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  auto D = [&](int i) {
    int res = 0;
    for (int k = 0; k < s[i].size(); ++k) {
      res += std::abs(s[i][k] - s[i + 1][k]);
    }
    return res;
  };
  auto D1 = [&](std::string s1, std::string s2) {
    int res = 0;
    for (int k = 0; k < s1.size(); ++k) {
      res += std::abs(s1[k] - s2[k]);
    }
    return res;
  };
  std::set<int> st;
  int min = INF;
  for (int i = 0; i + 1 < n; ++i) {
    min = std::min(min, D(i));
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (D(i) == min) {
      if (i) {
        st.emplace(i - 1);
      }
      st.emplace(i);
      if (i + 1 < n) {
        st.emplace(i + 1);
      }
    }
  }
  if (st.size() > 9) {
    printf("1 1\n");
    exit(0);
  }
  int res = min, l = 1, r = 1;
  for (auto u: st) {
    std::multiset<int> mst;
    for (int i = 0; i + 1 < n; ++i) {
      mst.emplace(D(i));
    }
    for (int i = 0; i < n; ++i) {
      if (i == u) {
        continue;
      }
      if (i + 1 < n) {
        mst.erase(mst.find(D(i)));
      }
      if (i) {
        mst.erase(mst.find(D(i - 1)));
      }
      if (u + 1 < n && u != i - 1) {
        mst.erase(mst.find(D(u)));
      }
      if (u && u - 1 != i) {
        mst.erase(mst.find(D(u - 1)));
      }
      if (i + 1 < n && i + 1 != u) {
        mst.emplace(D1(s[u], s[i + 1]));
      }
      if (i && i - 1 != u) {
        mst.emplace(D1(s[i - 1], s[u]));
      }
      if (u + 1 < n && u + 1 != i) {
        mst.emplace(D1(s[i], s[u + 1]));
      }
      if (u && u - 1 != i) {
        mst.emplace(D1(s[u - 1], s[i]));
      }
      if (i + 1 == u || u + 1 == i) {
        mst.emplace(D1(s[u], s[i]));
      }
      if (res < *mst.begin()) {
        res = *mst.begin();
        l = i + 1, r = u + 1;
      }
      if (i + 1 < n) {
        mst.emplace(D(i));
      }
      if (i) {
        mst.emplace(D(i - 1));
      }
      if (u + 1 < n && u != i - 1) {
        mst.emplace(D(u));
      }
      if (u && u - 1 != i) {
        mst.emplace(D(u - 1));
      }
      if (i + 1 < n && i + 1 != u) {
        mst.erase(mst.find(D1(s[u], s[i + 1])));
      }
      if (i && i - 1 != u) {
        mst.erase(mst.find(D1(s[i - 1], s[u])));
      }
      if (u + 1 < n && u + 1 != i) {
        mst.erase(mst.find(D1(s[i], s[u + 1])));
      }
      if (u && u - 1 != i) {
        mst.erase(mst.find(D1(s[u - 1], s[i])));
      }
      if (i + 1 == u || u + 1 == i) {
        mst.erase(mst.find(D1(s[u], s[i])));
      }
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}
