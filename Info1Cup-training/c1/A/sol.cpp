/**
 *    author:  feev1x
 *    created: 28.01.2025 09:08:04
**/
#include <bits/stdc++.h>
#include "game.h"

int k;

std::map<int, std::vector<int>> mp;

void init(int n, int K) {
    k = K;

    auto Dfs = [&](auto &&self, int l, int r) {
        int sz = r - l + 1, num = 1;

        for (int i = 1; i <= n; i += sz, num++) {
            int l = i, r = i + sz - 1;
            bool flag = false;

            for (int j = 0; l + j <= r; j += num) {
                chooseInterval(l, l + j);

                if (l + j == r) {
                    flag = true;
                }
            }

            for (int j = 0; r - j >= l; j += k - num + 1) {
                chooseInterval(r - j, r);

                if (r - j == l) {
                    flag = true;
                }
            }

            if (!flag) {
                chooseInterval(l, r);
            }

            self(self, i, i + sz - 1);
        }
    };
}

void query(int a, int b) {
    
}
