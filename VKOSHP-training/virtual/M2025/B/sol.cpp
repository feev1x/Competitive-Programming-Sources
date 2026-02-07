/**
 *    author:  feev1x
 *    created: 13.11.2025 11:34:40
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmin(int &a, int b) {
    if (a > b)
        a = b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int N = 0;
        std::vector<int> m(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> m[i];

        for (int i = 1; i <= n; ++i)
            std::cin >> b[i], N += b[i];

        if (N == 0) {
            std::cout << "0\n";
            continue;
        }

        int oN = (N + m[1] - 1) / m[1];
        std::vector<int> dp(oN, INF), p(oN), s(oN);

        for (int j = 0; j < oN; ++j)
            dp[j] = b[1] + m[1] * j;


        for (int i = 2; i <= n; ++i) {
            int nN = (N + m[i] - 1) / m[i];

            std::vector<int> new_dp(nN, INF);

            p.resize(oN);
            s.resize(oN);
            p[0] = dp[0] - b[i - 1];
            for (int j = 1; j < oN; ++j)
                p[j] = std::min(dp[j] - (b[i - 1] + m[i - 1] * j), p[j - 1]);

            s[oN - 1] = dp[oN - 1];
            for (int j = oN - 2; j >= 0; --j)
                s[j] = std::min(s[j + 1], dp[j]);

            for (int j = 0; j < nN; ++j) {
                int ps = ((b[i] + m[i] * j) - b[i - 1] + m[i - 1] - 1) / m[i - 1];

                if (ps < oN)
                    chmin(new_dp[j], s[ps]);

                if (ps)
                    chmin(new_dp[j], b[i] + m[i] * j + p[std::min(ps - 1, oN - 1)]);
            }

            std::swap(dp, new_dp);
            oN = nN;
        }

        std::cout << *std::min_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}
