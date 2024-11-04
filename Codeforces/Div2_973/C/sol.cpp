/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    deque<char> s;
    bool bl = false;
    int cnt = 0;
    while (s.size() < n) {
      if (s.empty()) {
        printf("? 1\n");
        fflush(stdout);
        cnt++;
        int ans; scanf("%d", &ans);
        if (ans == 1) {
          s.emplace_back('1');
        } else {
          for (int i = 0; i < n; ++i) {
            s.emplace_back('0');
          }
          break;
        }
      } else if (bl) {
        s.emplace_front('1');
        printf("? ");
        for (auto c: s) {
          printf("%c", c);
        }
        printf("\n");
        fflush(stdout);
        cnt++;
        int ans; scanf("%d", &ans);
        s.pop_front();
        if (ans == 1) {
          s.emplace_front('1');
        } else {
          s.emplace_front('0');
        }
      } else {
        s.emplace_back('1');
        printf("? ");
        for (auto c: s) {
          printf("%c", c);
        }
        printf("\n");
        fflush(stdout);
        cnt++;
        int ans; scanf("%d", &ans);
        s.pop_back();
        if (ans == 1) {
          s.emplace_back('1');
        } else {
          s.emplace_back('0');
          printf("? ");
          for (auto c: s) {
            printf("%c", c);
          }
          printf("\n");
          fflush(stdout);
          cnt++;
          int ans; scanf("%d", &ans);
          s.pop_back();
          if (ans == 1) {
            s.emplace_back('0');
          } else {
            bl = true;
            s.emplace_front('1');
            printf("? ");
            for (auto c: s) {
              printf("%c", c);
            }
            printf("\n");
            fflush(stdout);
            cnt++;
            int ans; scanf("%d", &ans);
            s.pop_front();
            if (ans == 1) {
              s.emplace_front('1');
            } else {
              s.emplace_front('0');
            }
          }
        }
      }
    }
    if (cnt > 2 * n) {
      while (true) cnt++;
    }
    printf("! ");
    for (auto c: s) {
      printf("%c", c);
    }
    printf("\n");
    fflush(stdout);
  }
}

