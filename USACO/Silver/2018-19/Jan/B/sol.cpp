/**
 *    author:  feev1x
 *    created: 10.02.2025 13:57:11
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("perimeter.in", "r", stdin);
    std::freopen("perimeter.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::string> s(n + 2, std::string(n + 2, '.'));
    std::vector<std::vector<bool>> used(n + 2, std::vector<bool>(n + 2));
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = "." + s[i] + ".";
    }

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};
    
    auto Check = [&](int i, int j) {
        return 1 <= i && i <= n && 1 <= j && j <= n;
    };

    int area, per;
    auto Dfs = [&](auto &&self, int i, int j) -> void {
        used[i][j] = true;
        area++;

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];

            if (Check(x, y) && !used[x][y] && s[x][y] == '#') {
                self(self, x, y);
            } else if (!Check(x, y) || s[x][y] == '.') {
                per++;
            }
        }
    };

    int max_area = 0, min_per = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (used[i][j] || s[i][j] == '.') {
                continue;
            }

            area = per = 0;

            Dfs(Dfs, i, j);

            if (area > max_area) {
                max_area = area;
                min_per = per;
            } else if (area == max_area && per < min_per) {
                min_per = per;
            }
        }
    }

    std::cout << max_area << ' ' << min_per << '\n';
    return 0;
}
