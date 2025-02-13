/**
 *    author:  feev1x
 *    created: 11.02.2025 22:22:01
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        std::vector<int> a(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            p[i] = p[i - 1] ^ a[i];
        }

        std::map<int, int> dp;

        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[p[i - 1]] = (mul(dp[p[i - 1]], 3) + mul(dp[p[i]], 2)) % MOD;
        }

        int res = 0;
        for (auto [key, val]: dp) {
            add_self(res, val);
        }

        std::cout << res << '\n';
    }
    return 0;
}
