/**
 *    author:  feev1x
 *    created: 03.03.2025 16:16:32
**/
#include <bits/stdc++.h>

using grid = std::array<std::array<bool, 7>, 7>;

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
    auto Check = [&](int i, int j) {
        return 0 <= i && i < 7 && 0 <= j && j < 7 && !used[i][j];
    };


    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};
    int cnt = 0;
    auto Count = [&](auto &&self, int i, int j, int move) -> int {
        cnt++;

        if (i == 6 && j == 0) {
            if (move == 48) {
                return 1;
            } 

            return 0;
        }

        if (move == 48) {
            return 0;
        }

        if (Check(i + 1, j) && Check(i - 1, j) && !Check(i, j + 1) && !Check(i, j - 1)) {
            return 0;
        }

        if (Check(i, j + 1) && Check(i - 1, j - 1) && !Check(i + 1, j) && !Check(i - 1, j)) {
            return 0;
        }

        int res = 0;
        used[i][j] = true;
        if (s[move] == '?') {
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];

                if (Check(x, y)) {
                    res += self(self, x, y, move + 1);
                }
            }
        } else {
            int x = i + dx[s1[move]], y = j + dy[s1[move]];

            if (Check(x, y)) {
                res += self(self, x, y, move + 1);
            }
        }

        used[i][j] = false;

        return res;
    };

    std::cout << Count(Count, 0, 0, 0) << ' ' << cnt << '\n';
    return 0;
}
