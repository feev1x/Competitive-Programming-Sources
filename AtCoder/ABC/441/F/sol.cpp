#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<int> p(n), v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i] >> v[i];
    }

    std::string s(n, 'a');
    std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(m + 1));

    dp[0][p[0]] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];

        for (int j = p[i]; j <= m; ++j) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - p[i]] + v[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
        }
    }

    std::vector<int64_t> dpp(m + 1);
    for (int i = n - 1; i >= 0; --i) {
        int64_t mxn = 0, mx = 0;

        int64_t ml = 0;
        for (int j = m, ii = 0; j >= 0; --j, ii++) {
            ml = std::max(ml, dpp[ii]);

            mxn = std::max(mxn, ml + (i ? dp[i - 1][j] : (int64_t)0));
        }

        ml = 0;
        for (int j = m - p[i], ii = 0; j >= 0; --j, ++ii) {
            ml = std::max(ml, dpp[ii]);

            mx = std::max(mx, ml + (i ? dp[i - 1][j] : (int64_t)0) + v[i]);
        }

        if (mx == mxn) {
            s[i] = 'B';
        } else if (mx > mxn) {
            s[i] = 'A';
        } else {
            s[i] = 'C';
        }

        auto new_dpp = dpp;
        for (int j = p[i]; j <= m; ++j) {
            new_dpp[j] = std::max(new_dpp[j], dpp[j - p[i]] + v[i]);
        }

        std::swap(new_dpp, dpp);
    }
    
    std::cout << s << '\n';
    return 0;
}
