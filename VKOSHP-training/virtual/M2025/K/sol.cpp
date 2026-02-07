/**
 *    author:  feev1x
 *    created: 13.11.2025 10:28:02
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 1e6 + 4;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int dp[N][3][3][3][3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[0][0][0][0][0] = 1;

    for (int p = 1; p < N; ++p) {
        for (int i = 2; i >= 0; --i)
            for (int j = 2; j >= 0; --j)
                for (int k = 2; k >= 0; --k)
                    for (int l = 2; l >= 0; --l)
                        if (std::min({i, j, k, l}) == 0) {
                            if (std::min({i, j - 1, k - 1, l - 1}) >= 0)
                                add_self(dp[p][i][j][k][l], dp[p - 1][i][j - 1][k - 1][l - 1]);
                            if (std::max({i + 1, j, k, l}) < 3)
                                add_self(dp[p][i][j][k][l], dp[p][i + 1][j][k][l]);

                            if (std::min({i - 1, j, k - 1, l - 1}) >= 0)
                                add_self(dp[p][i][j][k][l], dp[p - 1][i - 1][j][k - 1][l - 1]);
                            if (std::max({i, j + 1, k, l}) < 3)
                                add_self(dp[p][i][j][k][l], dp[p][i][j + 1][k][l]);

                            if (std::min({i - 1, j - 1, k, l - 1}) >= 0)
                                add_self(dp[p][i][j][k][l], dp[p - 1][i - 1][j - 1][k][l - 1]);
                            if (std::max({i, j, k + 1, l}) < 3)
                                add_self(dp[p][i][j][k][l], dp[p][i][j][k + 1][l]);

                            if (std::min({i - 1, j - 1, k - 1, l}) >= 0)
                                add_self(dp[p][i][j][k][l], dp[p - 1][i - 1][j - 1][k - 1][l]);
                            if (std::max({i, j, k + 1, l}) < 3)
                                add_self(dp[p][i][j][k][l], dp[p][i][j][k][l + 1]);
                        }
    }
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int res = 0;
//        for (int i = 0; i < 3; ++i)
//            for (int j = 0; j < 3; ++j)
//                for (int k = 0; k < 3; ++k)
//                    for (int l = 0; l < 3; ++l)
//                        if (std::min({i, j, k, l}) == 0)
//                            add_self(res, dp[n][i][j][k][l]);

        std::cout << dp[n][0][0][0][0] << '\n';
    }
    return 0;
}
