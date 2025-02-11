/**
 *    author:  feev1x
 *    created: 03.02.2025 09:45:01
**/
#include <bits/stdc++.h>
#include "ping-pong.h"

constexpr int MOD = 1e9 + 7, N = 105;

int dp[N][N][N][3];
bool used[N][N][N][3];

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int solve(int a, int b, int c) {
    std::queue<std::array<int, 4>> q;

    for (int t = 0; t < 3; ++t) {
        dp[0][0][0][t] = 1;

        q.push({0, 0, 0, t});
    }

    while (!q.empty()) {
        auto [i, j, k, t] = q.front();
        q.pop();

        if (i > a || j > b || k > c) {
            continue;
        }

        if (t == 0) {
            add_self(dp[i][j + 1][k][2], dp[i][j][k][t]);
            add_self(dp[i][j][k + 1][1], dp[i][j][k][t]);

            if (!used[i][j + 1][k][2]) {
                used[i][j + 1][k][2] = true;

                q.push({i, j + 1, k, 2});
            }

            if (!used[i][j][k + 1][1]) {
                used[i][j][k + 1][1] = true;

                q.push({i, j, k + 1, 1});
            }
        } else if (t == 1) {
            add_self(dp[i + 1][j][k][2], dp[i][j][k][t]);
            add_self(dp[i][j][k + 1][0], dp[i][j][k][t]);

            if (!used[i + 1][j][k][2]) {
                used[i + 1][j][k][2] = true;

                q.push({i + 1, j, k, 2});
            }

            if (!used[i][j][k + 1][0]) {
                used[i][j][k + 1][0] = true;

                q.push({i, j, k + 1, 0});
            }
        } else {
            add_self(dp[i + 1][j][k][1], dp[i][j][k][t]);
            add_self(dp[i][j + 1][k][0], dp[i][j][k][t]);

            if (!used[i + 1][j][k][1]) {
                used[i + 1][j][k][1] = true;

                q.push({i + 1, j, k, 1});
            }

            if (!used[i][j + 1][k][0]) {
                used[i][j + 1][k][0] = true;

                q.push({i, j + 1, k, 0});
            }
        }
    }

    int res = 0;
    for (int t = 0; t < 3; ++t) {
        add_self(res, dp[a][b][c][t]);
    }

    return res;
}
