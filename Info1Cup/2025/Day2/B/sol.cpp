/**
 *    author:  feev1x
 *    created: 09.02.2025 17:25:10
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 1005;

int dp[N][N];
std::vector<int> divv[N];

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

    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divv[j].emplace_back(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            for (auto u: divv[j]) {
                if (i - u >= 0) {
                    add_self(dp[i][j], dp[i - u][u]);
                } else {
                    break;
                }
            }
        }
    }
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        if (n > 1000) {

        }

        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            add_self(sum, dp[n - i][i]);
        }

        std::cout << sum << '\n';
    }
    return 0;
}
