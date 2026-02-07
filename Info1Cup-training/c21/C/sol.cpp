#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k; std::cin >> k;

    if (k <= 19) {

        int mx = 0;
        for (int i = 60; i >= 0; --i) {
            if (k >> i & 1) {
                mx = i;
                break;
            }
        }

        std::vector<std::string> s(5, std::string(5, '.'));
        
        for (int i = 0; i < 5; ++i) {
            s.back()[i] = 'r';
            s[i].back() = 'd';
        }

        s.back().back() = '.';

        for (int mask = 0; mask < 1 << 16; ++mask) {
            auto t = s;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (mask >> (i * 4 + j) & 1) {
                        t[i][j] = 'X';
                    }
                }
            }

            if (t[0][0] == '.') {
                continue;
            }

            std::vector<std::vector<std::vector<int>>> dp(5, std::vector<std::vector<int>>(5, std::vector<int>(2)));

            dp[0][0][0] = 1;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (i == 4 && j == 4) {
                        break;
                    }

                    if (t[i][j] == 'd' || t[i][j] == 'X') {
                        dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
                    } 

                    if (t[i][j] == 'r' || t[i][j] == 'X') {
                        dp[i][j + 1][1] += dp[i][j][0] + dp[i][j][1];
                    }

                    if (t[i][j] == '.') {
                        dp[i][j + 1][1] += dp[i][j][1];
                        dp[i + 1][j][0] += dp[i][j][0];
                    }
                }
            }

            if (dp[4][4][0] + dp[4][4][1] == k) {
                s = t;
                break;
            }
        }

        std::cout << 5 << ' ' << 5 << '\n';
        for (int i = 0; i < 5; ++i) {
            std::cout << s[i] << '\n';
        }
    } else if (k < 33554432) {
        int mx = 0;
        for (int i = 60; i >= 0; --i) {
            if (k >> i & 1) {
                mx = i;
                break;
            }
        }

        std::vector<std::string> s(6, std::string(6, '.'));
        
        for (int i = 0; i < 6; ++i) {
            s.back()[i] = 'r';
            s[i].back() = 'd';
        }

        s.back().back() = '.';

        for (int mask = 0; mask < 1 << 25; ++mask) {
            auto t = s;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (mask >> (i * 5 + j) & 1) {
                        t[i][j] = 'X';
                    }
                }
            }

            if (t[0][0] == '.') {
                continue;
            }

            std::vector<std::vector<std::vector<int>>> dp(6, std::vector<std::vector<int>>(6, std::vector<int>(2)));

            dp[0][0][0] = 1;
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (i == 5 && j == 5) {
                        break;
                    }

                    if (t[i][j] == 'd' || t[i][j] == 'X') {
                        dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
                    } 

                    if (t[i][j] == 'r' || t[i][j] == 'X') {
                        dp[i][j + 1][1] += dp[i][j][0] + dp[i][j][1];
                    }

                    if (t[i][j] == '.') {
                        dp[i][j + 1][1] += dp[i][j][1];
                        dp[i + 1][j][0] += dp[i][j][0];
                    }
                }
            }

            if (dp[5][5][0] + dp[5][5][1] == k) {
                s = t;
                break;
            }
        }

        std::cout << 6 << ' ' << 6 << '\n';
        for (int i = 0; i < 6; ++i) {
            std::cout << s[i] << '\n';
        }
    } else {
        k--;
        int mx = 0;
        for (int i = 60; i >= 0; --i) {
            if (k >> i & 1) {
                mx = i;
                break;
            }
        }

        std::vector<std::string> s(mx + 2, std::string(mx + 2, '.'));
        
        for (int i = 0; i < mx + 2; ++i) {
            s.back()[i] = 'r';
            s[i].back() = 'd';
        }

        s.back().back() = '.';

        for (int i = 0; i < mx + 2; ++i) {
            for (int j = 1; j < mx + 1 - i; ++j) {
                s[i][j] = 'X';
            }
        }

        for (int i = 0, bt = mx; i < mx + 1; ++i, --bt) {
            if (k >> bt & 1) {
                s[i][0] = 'X';
            }
        }

        std::cout << mx + 2 << ' ' << mx + 2 << '\n';
        for (int i = 0; i < mx + 2; ++i) {
            std::cout << s[i] << '\n';
        }
    }

    return 0;
}
