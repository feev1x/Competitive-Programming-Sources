/**
 *    author:  feev1x
 *    created: 27.02.2025 13:03:06
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 5, MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int dp[N][2];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i][0] = (dp[i - 1][1] + mul(dp[i - 1][0], 4)) % MOD;
        dp[i][1] = (mul(dp[i - 1][1], 2) + dp[i - 1][0]) % MOD;
    }
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
    return 0;
}
