/**
 *    author:  feev1x
 *    created: 16.05.2025 13:47:24
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }

    auto res = s;
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> d(n + 2, std::vector<int>(m + 2, INF));
    for (int i = 0; i <= n + 1; ++i) {
        d[i][0] = d[i][m + 1] = 0;
    }

    for (int i = 0; i <= m + 1; ++i) {
        d[0][i] = d[n + 1][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 'E') {
                q.emplace(i, j);
                d[i][j] = 0;
            }
        }
    }

    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};

    std::string ss{"^v<>"};

    while (q.size()) {
        auto [i, j] = q.front();

        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];

            if (d[x][y] > d[i][j] + 1 && s[x][y] != '#') {
                d[x][y] = d[i][j] + 1;
                res[x][y] = ss[k];

                q.emplace(x, y);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cout << res[i][j];
        }

        std::cout << '\n';
    }
    return 0;
}
