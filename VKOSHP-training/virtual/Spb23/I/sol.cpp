/**
 *    author:  feev1x
 *    created: 14.11.2025 10:41:35
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void chmin(int64_t &a, int64_t b) {
    if (a > b)
        a = b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1), c(n + 1), next(n + 1, n + 1), prev(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];

    {
        std::stack<int> stk;

        for (int i = 1; i <= n; ++i) {
            while (stk.size() && a[stk.top()] < a[i])
                stk.pop();

            if (stk.size())
                prev[i] = stk.top();

            stk.emplace(i);
        }
    }

    {
        std::stack<int> stk;

        for (int i = n; i >= 1; --i) {
            while (stk.size() && a[stk.top()] < a[i])
                stk.pop();

            if (stk.size())
                next[i] = stk.top();

            stk.emplace(i);
        }
    }

    std::vector<int64_t> dp(n + 1, INF);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        chmin(dp[i], dp[prev[i]] + c[i]);
        chmin(dp[next[i] - 1], dp[i - ] + c[i]);
    }

    std::cout << dp[n] << '\n';
    return 0;
}
