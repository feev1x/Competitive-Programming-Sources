/**
 *    author:  feev1x
 *    created: 27.02.2025 16:24:16
**/
#include <bits/stdc++.h>

inline void min_self(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x; std::cin >> n >> x;

    std::vector<int> a(n), ans(1 << n, n), dp(1 << n, x);
    for (auto &u: a) {
        std::cin >> u;
    }

    ans[0] = 1;
    dp[0] = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                int mask2 = mask ^ (1 << i), add = dp[mask2] + a[i] > x, add2 = !add;

                if (ans[mask] > ans[mask2] + add) {
                    ans[mask] = ans[mask2] + add;
                    dp[mask] = a[i] + dp[mask2] * add2;
                } else if (ans[mask] == ans[mask2] + add) {
                    min_self(dp[mask], a[i] + dp[mask2] * add2);
                }
            }
        }
    }

    std::cout << ans.back() << '\n';
    return 0;
}
