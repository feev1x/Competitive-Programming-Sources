#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }

    if (n <= 10 && m <= 10) {
        int64_t res = 0;
        for (int x1 = 1; x1 <= n; ++x1)
            for (int y1 = 1; y1 <= m; ++y1) {
                if (s[x1][y1] == '*')
                    continue;

                s[x1][y1] = '*';

                for (int x2 = 1; x2 <= n; ++x2)
                    for (int y2 = 1; y2 <= m; ++y2) {
                        if (s[x2][y2] == '*')
                            continue;

                        s[x2][y2] = '*';
                        std::vector dp(n + 1, std::vector<bool>(m + 1));

                        dp[0][1] = dp[1][0] = true;
                        for (int i = 1; i <= n; ++i) 
                            for (int j = 1; j <= m; ++j) {
                                if (s[i][j] == '*')
                                    continue;

                                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                            }

                        res += !dp[n][m];

                        s[x2][y2] = '.';
                    }

                s[x1][y1] = '.';
            }

        std::cout << res / 2 << '\n';
    }
    return 0;
}
