#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::string s; std::cin >> s;

    int n = s.size();

    std::vector dp(n, std::vector<int>(n));
    std::vector dp2(n, std::vector<int>(n));
    for (int l = n - 2; l >= 0; --l)
        for (int r = l + 1; r < n; ++r) {
            add_self(dp[l][r], dp[l][r - 1]);
            add_self(dp[l][r], dp[l + 1][r]);
            add_self(dp[l][r], -dp[l + 1][r - 1]);

            if (s[l] == '+' && s[r] == '-') {
                add_self(dp[l][r], dp[l + 1][r - 1]);
                add_self(dp[l][r], 1);
                add_self(dp[l][r], dp2[l + 1][r - 1]);
            } else if (s[l] == '-' && s[r] == '+') {
                add_self(dp2[l][r], dp[l + 1][r - 1]);
                add_self(dp2[l][r], 1);
            }
        }

    std::cout << dp[0][n - 1] << '\n';
    return 0;
}
