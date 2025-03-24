/**
 *    author:  feev1x
 *    created: 06.03.2025 16:55:25
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }

    std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1, -1));

    std::queue<std::pair<int, int>> q;

    for (int i = 1; i <= n; ++i) {
        ans[i][i] = 0;

        q.emplace(i, i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && s[i][j] != '-') {
                ans[i][j] = 1;

                q.emplace(i, j);
            }
        }
    }

    while (q.size()) {
        auto [x, y] = q.front();

        q.pop();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i][x] == s[y][j] && s[i][x] != '-' && (ans[i][j] > ans[x][y] + 2 || ans[i][j] == -1)) {
                    ans[i][j] = ans[x][y] + 2;

                    q.emplace(i, j);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << ans[i][j] << " \n"[j == n];
        }
    }
    return 0;
}
