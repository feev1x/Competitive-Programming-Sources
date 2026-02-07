#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector ans(17, std::vector<std::vector<std::pair<int, int>>>(9));
    auto Get = [&](std::vector<std::pair<int, int>> sm, int n) {
        std::vector<bool> row(n + 1), col(n + 1), d1(2 * n + 1), d2(2 * n + 1);

        for (auto [x, y]: sm) {
            row[x] = true;
            col[y] = true;
            d1[x + y] = true;
            d2[x - y + n] = true;
        }

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                res += row[i] || col[j] || d1[i + j] || d2[i - j + n];
            }
        }

        return res;
    };

    std::cout << Get({{3, 3}, {7, 8}, {8, 10}, {9, 7}, {10, 9}}, 15) << '\n';

    ans[9][1] = {{5, 5}};
    ans[9][2] = {{2, 3}, {5, 5}};
    ans[9][3] = {{1, 1}, {4, 6}, {6, 5}};
    ans[9][4] = {{2, 2}, {3, 6}, {6, 7}, {7, 3}};
    ans[9][5] = {{1, 4}, {2, 3}, {3, 2}, {4, 1}, {7, 7}};
    ans[11][6] = {{1, 11}, {2, 1}, {5, 5}, {6, 7}, {7, 4}, {8, 6}};

    for (int n = 10; n <= 12; ++n) {
        for (int k = 1; 2 * k <= n + 1; ++k) {
            if (n == 11 && k == 6) {
                continue;
            }

            int mx = 0;
            for (int mask = 0; mask < 1 << k; ++mask) {
                for (int mask2 = 0; mask2 < 1 << k; ++mask2) {
                    std::vector<std::pair<int, int>> pr;

                    for (int i = 0; i < k; ++i) {
                        pr.emplace_back(ans[n - 1][k][i].first + (mask >> i & 1), ans[n - 1][k][i].second + (mask2 >> i & 1));
                    }

                    int cnt = Get(pr, n);
                    if (cnt > mx) {
                        mx = cnt;
                        std::swap(ans[n][k], pr);
                    }
                }
            }
        }
    }
    
    int n, k; std::cin >> n >> k;

    if (n < 9) {
        int mx = 0;
        std::vector<std::pair<int, int>> res;
        for (int mask = 0; mask < 1 << n; ++mask) {
            if (__builtin_popcount(mask) != k) {
                continue;
            }

            std::vector<int> x;

            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    x.emplace_back(i + 1);
                }
            }

            for (int mask2 = 0; mask2 < 1 << n; ++mask2) {
                if (__builtin_popcount(mask2) != k) {
                    continue;
                }

                std::vector<int> y;
                for (int i = 0; i < n; ++i) {
                    if (mask2 >> i & 1) {
                        y.emplace_back(i + 1);
                    }
                }

                do {
                    std::vector<std::pair<int, int>> pr;

                    for (int i = 0; i < k; ++i) {
                        pr.emplace_back(x[i], y[i]);
                    }

                    int cnt = Get(pr, n);

                    if (cnt > mx) {
                        mx = cnt, res = pr;
                    }
                } while (next_permutation(y.begin(), y.end()));
            }
        }

        std::cout << mx << '\n';
        for (auto [u, v]: res) {
            std::cout << u << ' ' << v << '\n';
        }
    } else {
        std::cout << Get(ans[n][k], n) << '\n';

        for (auto [u, v]: ans[n][k]) {
            std::cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}
