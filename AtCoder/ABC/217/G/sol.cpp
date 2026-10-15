#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
     a += b;
     if (a >= MOD) a -= MOD;
     if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector dp(n + 1, std::vector<int>(n + 1));
    std::vector p(n + 1, std::vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) add_self(dp[i][k], mul(dp[i - 1][k], k - ((i - 1) / m)));
        for (int k = 1; k <= i; ++k) add_self(dp[i][k], dp[i - 1][k - 1]);
    }
    for (int k = 1; k <= n; ++k) std::cout << dp[n][k] << '\n';
    return 0;
}
