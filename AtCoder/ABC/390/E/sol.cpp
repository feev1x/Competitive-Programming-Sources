/**
 *    author:  feev1x
 *    created: 03.02.2025 17:23:52
**/
#include <bits/stdc++.h>

inline void umax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x; std::cin >> n >> x;

    std::vector<int> v(n), a(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i] >> a[i] >> c[i]; v[i]--;
    }

    std::vector<std::array<int, 3>> dp(x + 1, {0, 0, 0});

    for (int i = 0; i < n; ++i) {
        for (int j = x - c[i]; j >= 0; --j) {
            umax(dp[j + c[i]][v[i]], dp[j][v[i]] + a[i]);
        }
    }

    int l = 0, r = 2e9, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;

        bool fl = true;
        int cal = 0;
        for (int j = 0; j < 3; ++j) {
            bool flag = false;

            for (int i = 0; i <= x - cal; ++i) {
                if (dp[i][j] >= m) {
                    cal += i;

                    flag = true;

                    break;
                }
            }

            if (!flag) {
                fl = false;
            }
        }

        if (cal > x) {
            fl = false;
        }

        if (fl) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
