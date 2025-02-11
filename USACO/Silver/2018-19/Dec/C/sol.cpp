/**
 *    author:  feev1x
 *    created: 10.02.2025 12:05:51
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("mooyomooyo.in", "r", stdin);
    std::freopen("mooyomooyo.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(11));
    std::vector<std::vector<bool>> used(n + 1, std::vector<bool>(11));
    for (int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;
        for (int j = 1; j <= 10; ++j) {
            a[i][j] = s[j - 1] - '0';

            if (k == 1) {
                a[i][j] = 0;
            }
        }
    }

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};

    auto Check = [&](int i, int j) {
        return 1 <= i && i <= n && 1 <= j && j <= 10;
    };

    std::vector<std::pair<int, int>> ar;
    auto Dfs = [&](auto &&self, int i, int j) -> void {
        used[i][j] = true;
        ar.emplace_back(i, j);

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];

            if (Check(x, y) && !used[x][y] && a[x][y] == a[i][j]) {
                self(self, x, y);
            }
        }
    };

    while (true) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                used[i][j] = false;
            }
        }

        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (used[i][j] || a[i][j] == 0) {
                    continue;
                }

                Dfs(Dfs, i, j);

                if (ar.size() >= k) {
                    flag = true;

                    for (auto [x, y]: ar) {
                        a[x][y] = 0;
                    }
                }

                ar.clear();
            }
        }

        if (!flag) {
            break;
        }

        std::vector<std::vector<int>> b(n + 1, std::vector<int>(11));

        for (int j = 1; j <= 10; ++j) {
            for (int i = n, k = n; i >= 1; --i) {
                if (a[i][j]) {
                    b[k--][j] = a[i][j];
                }
            }
        }

        a = b;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << a[i][j];
        }

        std::cout << '\n';
    }
    return 0;
}
