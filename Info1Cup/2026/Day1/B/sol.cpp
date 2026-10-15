#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;
    
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }

    if (n == 1) {
        std::vector<int> cnt(m + 1);

        std::vector<int> ecnt(2);

        for (int i = 1; i <= m; ++i) {
            if (cnt[a[1][i]] != 0) {
                ecnt[cnt[a[1][i]] & 1]--;
            }

            cnt[a[1][i]]++;
            ecnt[cnt[a[1][i]] & 1]++;
        }

        std::cout << ecnt[0] << '\n';

        int q; std::cin >> q;
        while (q--) {
            int x, y, t; std::cin >> x >> y >> t;

            ecnt[cnt[a[x][y]] & 1]--;
            cnt[a[x][y]]--;

            if (cnt[a[x][y]]) {
                ecnt[cnt[a[x][y]] & 1]++;
            }

            a[x][y] = t;

            if (cnt[t] != 0) {
                ecnt[cnt[t] & 1]--;
            }

            cnt[t]++;
            ecnt[cnt[t] & 1]++;

            std::cout << ecnt[0] << '\n';
        }
    } else if (n == 2) {
        std::vector dp(2, std::vector(2, std::vector(2, std::vector(5, true))));
        std::vector c(2, std::vector(2, std::vector(2, 0)));
        std::vector used(2, std::vector(2, std::vector(2, std::vector(5, false))));

//        for (int l = 0; l < 5; ++l) {
//            used[0][0][0][l] = true;
//            dp[0][0][0][l] = false;
//        }


//        std::cout << dp[0][0][0][l];
        auto Dfs = [&](auto &&self, int i, int j, int k, int l) -> void {
            if (used[i][j][k][l]) {
                return;
            }

            used[i][j][k][l] = true;
            
            bool flag = false;
            if (l == 0) {
                if (i || j) {
                    self(self, i, !j, k, 0);

                    if (!dp[i][!j][k][0]) {
                        flag = true;
                    }
                }

                if (j) {
                    self(self, !i, !j, k, 2);

                    if (!dp[!i][!j][k][2]) {
                        flag = true;
                    }
                }
            } else if (l == 1) {
                if (i || k) {
                    self(self, i, j, !k, 1);

                    if (!dp[i][j][!k][1]) {
                        flag = true;
                    }
                }

                if (k) {
                    self(self, !i, j, !k, 3);

                    if (!dp[!i][j][!k][3]) {
                        flag = true;
                    }
                }

            } else if (l == 2) {
                if (i || j) {
                    self(self, i, !j, k, 0);

                    if (!dp[i][!j][k][0]) {
                        flag = true;
                    }
                }

                if (j) {
                    self(self, !i, !j, k, 2);

                    if (!dp[!i][!j][k][2]) {
                        flag = true;
                    }
                }

                if (i || k) {
                    self(self, i, j, !k, 1);

                    if (!dp[i][j][!k][1]) {
                        flag = true;
                    }
                }
            } else if (l == 3) {
                if (i || j) {
                    self(self, i, !j, k, 0);

                    if (!dp[i][!j][k][0]) {
                        flag = true;
                    }
                }

                if (i || k) {
                    self(self, i, j, !k, 1);

                    if (!dp[i][j][!k][1]) {
                        flag = true;
                    }
                }

                if (k) {
                    self(self, !i, j, !k, 3);

                    if (!dp[!i][j][!k][3]) {
                        flag = true;
                    }
                }
            } else {
                if (i || j) {
                    self(self, i, !j, k, 0);

                    if (!dp[i][!j][k][0]) {
                        flag = true;
                    }
                }

                if (i || k) {
                    self(self, i, j, !k, 1);

                    if (!dp[i][j][!k][1]) {
                        flag = true;
                    }
                }

                if (k) {
                    self(self, !i, j, !k, 3);

                    if (!dp[!i][j][!k][3]) {
                        flag = true;
                    }
                }

                if (j) {
                    self(self, !i, !j, k, 2);

                    if (!dp[!i][!j][k][2]) {
                        flag = true;
                    }
                }
            }

            dp[i][j][k][l] = flag;
        };

        for (int i = 1; i >= 0; --i) {
            for (int j = 1; j >= 0; --j) {
                for (int k = 1; k >= 0; --k) {
                    for (int l = 4; l >= 0; --l) {
                        if (!used[i][j][k][l]) {
                            Dfs(Dfs, i, j, k, l);
                        }
                    }
                }
            }
        }

        std::vector cnt(3, std::vector<int>(n * m + 1));
        auto Get = [&](int val) {
            return std::tuple<int, int, int>{cnt[0][val] & 1, cnt[1][val] & 1, cnt[2][val] & 1};
        };


        std::vector<int> all(n * m + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                auto [x, y, z] = Get(a[i][j]);

                if (all[a[i][j]] != 0) {
                    c[x][y][z]--;
                }

                all[a[i][j]]++;
                cnt[i][a[i][j]]++;

                if (i == 2 && a[1][j] == a[2][j]) {
                    cnt[0][a[i][j]]++;
                }

                std::tie(x, y, z) = Get(a[i][j]);

                c[x][y][z]++;
            }
        }

        int res = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if (!dp[i][j][k][4]) {
                        res += c[i][j][k];
                    }
                }
            }
        }

        std::cout << res << '\n';

        int q; std::cin >> q;
        while (q--) {
            int i, j, t; std::cin >> i >> j >> t;

            auto [x, y, z] = Get(a[i][j]);

            c[x][y][z]--;
            all[a[i][j]]--;
            cnt[i][a[i][j]]--;

            if (a[1][j] == a[2][j]) {
                cnt[0][a[i][j]]--;
            }

            std::tie(x, y, z) = Get(a[i][j]);

            if (all[a[i][j]]) {
                c[x][y][z]++;
            }

            a[i][j] = t;
            std::tie(x, y, z) = Get(a[i][j]);

            if (all[a[i][j]] != 0) {
                c[x][y][z]--;
            }

            all[a[i][j]]++;
            cnt[i][a[i][j]]++;

            if (a[1][j] == a[2][j]) {
                cnt[0][a[i][j]]++;
            }

            std::tie(x, y, z) = Get(a[i][j]);

            c[x][y][z]++;


            int res = 0;
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    for (int k = 0; k < 2; ++k) {
                        if (!dp[i][j][k][4]) {
                            res += c[i][j][k];
                        }
                    }
                }
            }

            std::cout << res << '\n';
        }
    }
}
