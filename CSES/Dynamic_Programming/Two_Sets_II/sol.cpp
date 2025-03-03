/**
 *    author:  feev1x
 *    created: 27.02.2025 14:20:05
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
    
    int n; std::cin >> n;

    if (n * (n + 1) % 4 != 0) {
        std::cout << "0\n";

        exit(0);
    }

    std::vector<int> dp(n * (n + 1) / 4 + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = n * (n + 1) / 4; j >= i; --j) {
            add_self(dp[j], dp[j - i]);
        }
    }

    std::cout << mul(dp.back(), (MOD + 1) / 2) << '\n';
    return 0;
}
