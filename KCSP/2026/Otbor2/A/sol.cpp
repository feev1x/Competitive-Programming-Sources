#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s; std::cin >> s;

    std::array<int, 26> empt;

    for (auto &u: empt) {
        u = 0;
    }

    std::vector<std::array<int, 26>> tr;
    std::vector<bool> good;
    tr.emplace_back(empt);
    good.emplace_back(true);

    int m; std::cin >> m;
    while (m--) {
        std::string t; std::cin >> t;

        int nw = 0;
        for (auto u: t) {
            if (!tr[nw][u - 'a']) {
                tr[nw][u - 'a'] = tr.size();
                tr.emplace_back(empt);
                good.emplace_back(false);
            }

            nw = tr[nw][u - 'a'];
        }

        good[nw] = true;
    }

    int n = s.size();
    m = tr.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m, INF));

    dp[0][0] = 0;
    for (int i = 0; i + 1 <= n; ++i) {
        int nx = s[i] - 'a';

        for (int j = 0; j < m; ++j) {
            if (dp[i][j] != INF) {
                if (tr[j][nx]) {
                    chmin(dp[i + 1][tr[j][nx]], dp[i][j]);
                }

                if (good[j] && tr[0][nx]) {
                    chmin(dp[i + 1][tr[0][nx]], dp[i][j]);
                }

                chmin(dp[i + 1][j], dp[i][j] + 1);
            }
        }
    }

    int res = INF;
    for (int j = 0; j < m; ++j) {
        if (good[j]) {
            chmin(res, dp[n][j]);
        }
    }

    std::cout << res << '\n';
    return 0;
}
