#include "arithmetic_progression.h"
#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr __int128 INF = 1e34;

inline void chmin(__int128 &a, __int128 b) { if (a > b) a = b; }

__int128 solve(std::vector<long long> a, int k, long long s, int d) {
    int n = a.size();
    if (k > n / 2) {
        k = n - k;
        std::vector<__int128> dp(k + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) dp[j] = std::min(dp[j - 1], dp[j] + (__int128)a[i] * (s + (int64_t)(i - j) * d));
            dp[0] += (__int128)a[i] * (s + (__int128)(i) * d);
        }
        return dp[k];
    } else {
        std::vector<__int128> dp(k + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = k; j >= 1; --j) chmin(dp[j], dp[j - 1] + (__int128)a[i] * (s + (int64_t)(j - 1) * d));
        return dp[k];
    }
}
