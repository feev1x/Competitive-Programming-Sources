/**
 *    author:  feev1x
 *    created: 19.11.2024 09:31:26
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  if (n == 1) {
    printf("YES\n%d\n", a[0]);
    exit(0);
  }
  std::sort(a.begin(), a.end());
  if (n <= 8) {
    bool flag = false;
    do {
      bool flag1 = true;
      for (int i = 1; i < n; ++i) {
        if ((a[i] + a[i - 1]) % k == 0) {
          flag1 = false;
          break;
        }
      }
      if (flag1) {
        flag = true;
        break;
      }
    } while (std::next_permutation(a.begin(), a.end()));
    if (flag) {
      printf("YES\n");
      for (auto u: a) {
        printf("%d ", u);
      }
      printf("\n");
    } else {
      printf("NO\n");
    }
  } else if (k & 1) {
    int cen = k / 2;
    std::vector<int> one, two, three;
    for (int i = 0; i < n; ++i) {
      if (a[i] % k == 0) {
        one.emplace_back(a[i]);
      } else if (a[i] % k <= cen) {
        two.emplace_back(a[i]);
      } else {
        three.emplace_back(a[i]);
      }
    }
    if (one.empty() && two.size() && three.size()) {
      printf("NO\n");
      exit(0);
    }
    std::vector<int> ans;
    while (!two.empty()) {
      ans.emplace_back(two.back());
      two.pop_back();
    }
    if (one.size()) {
      ans.emplace_back(one.back());
      one.pop_back();
    }
    while (!three.empty()) {
      ans.emplace_back(three.back());
      three.pop_back();
    }
    std::vector<int> tmp;
    for (int i = 0; i < ans.size(); ++i) {
      if (((tmp.empty() || tmp.back() % k != 0) && ans[i] % k != 0) && !one.empty()) {
        tmp.emplace_back(one.back());
        one.pop_back();
      }
      tmp.emplace_back(ans[i]);
    }
    if ((tmp.empty() || tmp.back() % k != 0) && !one.empty()) {
      tmp.emplace_back(one.back());
      one.pop_back();
    }
    ans = tmp;
    if (ans.size() != n) {
      printf("NO\n");
      exit(0);
    }
    printf("YES\n");
    for (auto u: ans) {
      printf("%d ", u);
    }
    printf("\n");
  } else {
    int cen = k / 2;
    std::vector<int> one, two, three, four;
    for (int i = 0; i < n; ++i) {
      if (a[i] % k == 0) {
        one.emplace_back(a[i]);
      } else if (a[i] % k < cen) {
        two.emplace_back(a[i]);
      } else if (a[i] % k > cen) {
        three.emplace_back(a[i]);
      } else {
        four.emplace_back(a[i]);
      }
    }
    std::sort(two.begin(), two.end(), [&](int a1, int a2) {
        return a1 % k > a2 % k;
        });
    std::sort(three.begin(), three.end(), [&](int a1, int a2) {
        return a1 % k < a2 % k;
        });
    if (!two.empty() && !three.empty() && (two.front() + three.back()) % k == 0 && (three.front() + two.back()) % k == 0) {
      if (one.empty() && four.empty() && two.size() && three.size()) {
        printf("NO\n");
        exit(0);
      }
      std::vector<int> ans;
      while (!two.empty()) {
        ans.emplace_back(two.back());
        two.pop_back();
      }
      if (one.size()) {
        ans.emplace_back(one.back());
        one.pop_back();
      } else if (four.size()) {
        ans.emplace_back(four.back());
        four.pop_back();
      }
      while (!three.empty()) {
        ans.emplace_back(three.back());
        three.pop_back();
      }
      while (!four.empty() && !one.empty()) {
        ans.emplace_back(four.back());
        ans.emplace_back(one.back());
        four.pop_back();
        one.pop_back();
      }
      if (four.empty()) {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != 0) && ans[i] % k != 0) && !one.empty()) {
            tmp.emplace_back(one.back());
            one.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != 0) && !one.empty()) {
          tmp.emplace_back(one.back());
          one.pop_back();
        }
        ans = tmp;
      } else {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != cen) && ans[i] % k != cen) && !four.empty()) {
            tmp.emplace_back(four.back());
            four.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != cen) && !four.empty()) {
          tmp.emplace_back(four.back());
          four.pop_back();
        }
        ans = tmp;
      }
      if (ans.size() != n) {
        printf("NO\n");
        exit(0);
      }
      printf("YES\n");
      for (auto u: ans) {
        printf("%d ", u);
      }
      printf("\n");
    } else if (three.empty() || two.empty() || (three.front() + two.back()) % k == 0) {
      std::vector<int> ans;
      for (int i = 0; i < two.size(); ++i) {
        ans.emplace_back(two[i]);
      }
      for (int i = 0; i < three.size(); ++i) {
        ans.emplace_back(three[i]);
      }
      while (!four.empty() && !one.empty()) {
        ans.emplace_back(four.back());
        ans.emplace_back(one.back());
        four.pop_back();
        one.pop_back();
      }
      if (four.empty()) {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != 0) && ans[i] % k != 0) && !one.empty()) {
            tmp.emplace_back(one.back());
            one.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != 0) && !one.empty()) {
          tmp.emplace_back(one.back());
          one.pop_back();
        }
        ans = tmp;
      } else {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != cen) && ans[i] % k != cen) && !four.empty()) {
            tmp.emplace_back(four.back());
            four.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != cen) && !four.empty()) {
          tmp.emplace_back(four.back());
          four.pop_back();
        }
        ans = tmp;
      }
      if (ans.size() != n) {
        printf("NO\n");
        exit(0);
      }
      printf("YES\n");
      for (auto u: ans) {
        printf("%d ", u);
      }
      printf("\n");
    } else {
      std::vector<int> ans;
      for (int i = 0; i < three.size(); ++i) {
        ans.emplace_back(three[i]);
      }
      for (int i = 0; i < two.size(); ++i) {
        ans.emplace_back(two[i]);
      }
      while (!four.empty() && !one.empty()) {
        ans.emplace_back(four.back());
        ans.emplace_back(one.back());
        four.pop_back();
        one.pop_back();
      }
      if (four.empty()) {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != 0) && ans[i] % k != 0) && !one.empty()) {
            tmp.emplace_back(one.back());
            one.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != 0) && !one.empty()) {
          tmp.emplace_back(one.back());
          one.pop_back();
        }
        ans = tmp;
      } else {
        std::vector<int> tmp;
        for (int i = 0; i < ans.size(); ++i) {
          if (((tmp.empty() || tmp.back() % k != cen) && ans[i] % k != cen) && !four.empty()) {
            tmp.emplace_back(four.back());
            four.pop_back();
          }
          tmp.emplace_back(ans[i]);
        }
        if ((tmp.empty() || tmp.back() % k != cen) && !four.empty()) {
          tmp.emplace_back(four.back());
          four.pop_back();
        }
        ans = tmp;
      }
      if (ans.size() != n) {
        printf("NO\n");
        exit(0);
      }
      printf("YES\n");
      for (auto u: ans) {
        printf("%d ", u);
      }
      printf("\n");
    }
  }
  return 0;
}
