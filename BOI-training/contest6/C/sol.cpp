#include "lawn.h"
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline int64_t min(int64_t a, int64_t b) {
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    if (a > b)
        return b;

    return a;
}

long long mow(int n, int c, int b, std::vector<int> &a, std::vector<int> &v) {
    std::vector<std::map<int, int64_t>> dp(n);

    if (v[0] % c == 0)
        dp[0][c] = (int64_t)a[0] * (v[0] / c) + (int64_t)b * (v[0] / c - 1),
        dp[0][0] = (int64_t)(a[0] + b) * (v[0] / c);
    else
        dp[0][0] = (int64_t)(a[0] + b) * ((v[0] + c - 1) / c),
        dp[0][v[0] % c] = (int64_t)a[0] * ((v[0] + c - 1) / c) + (int64_t)b * ((v[0] + c - 1) / c - 1);

    for (int i = 1; i < n; ++i) {
        for (auto [j, val]: dp[i - 1]) {
            int64_t nw = v[i] + j;

            if (nw % c == 0)
                dp[i][0] = min(dp[i][0], val + (int64_t)a[i] * (nw / c) + (int64_t)b * (nw / c)),
                dp[i][c] = min(dp[i][c], val + (int64_t)a[i] * (nw / c) + (int64_t)b * (nw / c - 1));
            else
                dp[i][0] = min(dp[i][0], val + (int64_t)(a[i] + b) * ((nw + c - 1) / c)),
                dp[i][nw % c] = min(dp[i][nw % c], val + (int64_t)a[i] * ((nw + c - 1) / c) + 
                        (int64_t)b * ((nw + c - 1) / c - 1));
        }
    }

    return dp[n - 1][0];
}
