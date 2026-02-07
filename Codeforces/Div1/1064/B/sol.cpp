/**
 *    author:  feev1x
 *    created: 16.11.2025 20:44:05
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        std::vector<int> a(n);

        std::map<int, int> mp;
        for (auto &u: a)
            std::cin >> u, mp[u]++;

        int i = 1;

        std::vector<int> sr;
        for (auto [key, val]: mp)
            sr.emplace_back(val);

        std::sort(sr.begin(), sr.end());
        std::vector<std::vector<int>> dp(sr.size(), std::vector<int>(n + 1));
        dp[0][0] = 1;
        dp[0][sr[0]] = sr[0];
        for (int i = 1; i < sr.size(); ++i) {
            for (int j = 0; j <= n; ++j)
                add_self(dp[i][j], dp[i - 1][j]);

            for (int j = sr[i]; j <= n; ++j)
                add_self(dp[i][j], mul(dp[i - 1][j - sr[i]], sr[i]));
        }

        for (int i = 0; i < sr.size(); ++i)
            for (int j = n - 1; j >= 0; --j)
                add_self(dp[i][j], dp[i][j + 1]);

        int res = (sr.back() <= sr[0] ? sr[0] : 0), sum = 0;
        for (int i = sr.size() - 1; i >= 1; --i) {
            add_self(res, mul(sr[i], dp[i - 1][(sum ? sum - sr[i] : 0)]));

            sum = std::max(sum, sr[i]);
        }

        std::cout << res << '\n';
    }
    return 0;
}
