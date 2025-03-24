/**
 *    author:  feev1x
 *    created: 03.03.2025 16:16:32
**/
#include <bits/stdc++.h>

using grid = std::array<std::array<bool, 9>, 9>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;    
    std::array<int, 48> s1;

    for (int i = 0; i < 48; ++i) {
        if (s[i] == 'U') {
            s1[i] = 0;
        } else if (s[i] == 'D') {
            s1[i] = 1;
        } else if (s[i] == 'L') {
            s1[i] = 2;
        } else if (s[i] == 'R') {
            s1[i] = 3;
        } else {
            s1[i] = 4;
        }
    }

    grid used{};
    for (int i = 0; i < 9; ++i) {
        used[0][i] = used[8][i] = used[i][0] = used[i][8] = true;
    }

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};

    auto Count = [&](auto &&self, int i, int j, int move) -> int {
        if (i == 7 && j == 1) {
            if (move == 48) {
                return 1;
            } 

            return 0;
        }

        if (move == 48) {
            return 0;
        }

        if (!used[i + 1][j] && !used[i - 1][j] && used[i][j + 1] && used[i][j - 1]) {
            return 0;
        }

        if (used[i + 1][j] && used[i - 1][j] && !used[i][j + 1] && !used[i][j - 1]) {
            return 0;
        }

        int res = 0;
        used[i][j] = true;
        if (s[move] == '?') {
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (!used[x][y]) {
                    res += self(self, x, y, move + 1);
                }
            }
        } else {
            int x = dx[s1[move]] + i, y = dy[s1[move]] + j;

            if (!used[x][y]) {
                res += self(self, x, y, move + 1);
            }
        }

        used[i][j] = false;

        return res;
    };

    std::cout << Count(Count, 1, 1, 0) << '\n';
    return 0;
}
