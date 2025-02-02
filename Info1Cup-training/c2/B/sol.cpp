/**
 *    author:  feev1x
 *    created: 29.01.2025 09:56:16
**/
#include <bits/stdc++.h>

constexpr int N = 57600;

using BS = std::bitset<N>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q; std::cin >> n >> m >> q;

    auto Id = [&](int i, int j) {
        return (i - 1) * m + (j - 1);
    };


    BS tr;
    std::vector<std::string> s(n + 1);
    std::vector<BS> dp(n * m);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];

        for (int j = 1; j <= m; ++j) {
            tr.set(Id(i, j));
        }
    }


    std::vector<std::vector<int64_t>> F(n + 1, std::vector<int64_t>(m + 1)), del(n + 1, std::vector<int64_t>(m + 1));
    std::vector<std::vector<std::pair<int, int>>> end(n + 1, std::vector<std::pair<int, int>>(m + 1));

    for (int i = n - 1; i > 1; --i) {
        for (int j = m - 1; j > 1; --j) {
            if (s[i][j] != '#') {
                continue;
            }

            if (s[i][j + 1] == '#') {
                end[i][j] = end[i][j + 1];
            } else if (s[i + 1][j + 1] == '#') {
                end[i][j] = end[i + 1][j + 1];
            } else if (s[i + 1][j] == '#') {
                end[i][j] = end[i + 1][j];
            } else {
                end[i][j] = {i + 1, j + 1};
            }
        }
    }

    int64_t S = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (s[i][j] == '#') {
                continue;
            }

            dp[Id(i, j)].set(Id(i, j));

            if (i != n) {
                dp[Id(i, j)] |= dp[Id(i + 1, j)];
            }
            
            if (j != m) {
                dp[Id(i, j)] |= dp[Id(i, j + 1)];
            }

            if (i == n && j == m) {
                F[i][j] = 1;
            } else if (i == n) {
                F[i][j] = F[i][j + 1] + 1;
            } else if (j == m) {
                F[i][j] = F[i + 1][j] + 1;
            } else {
                if (s[i + 1][j] == '#') {
                    F[i][j] = F[i][j + 1] + 1;
                } else if (s[i][j + 1] == '#') {
                    F[i][j] = F[i + 1][j] + 1;
                } else if (s[i + 1][j + 1] == '$') {
                    F[i][j] = F[i + 1][j] + F[i][j + 1] + 1 - F[i + 1][j + 1];
                } else {
                    auto [x, y] = end[i + 1][j + 1];
                    F[i][j] = F[i + 1][j] + F[i][j + 1] + 1 - F[x][y];
                }
            }
            S += F[i][j];
        }
    }

    std::cout << S << '\n';

    while (q--) {
        char c; std::cin >> c;
        int x, y; std::cin >> x >> y;

        if (c == '!') {
            tr[Id(x, y)] = tr[Id(x, y)] ^ 1;
        } else {
            std::cout << (tr & dp[Id(x, y)]).count() << '\n';
        }
    }
    return 0;
}
