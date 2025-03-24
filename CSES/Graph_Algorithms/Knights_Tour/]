/**
 *    author:  feev1x
 *    created: 04.03.2025 15:15:47
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y; std::cin >> x >> y; std::swap(x, y);

    x--, y--;

    std::array<std::array<int, 8>, 8> grid{};

    grid[x][y] = 1;

    int dx[]{1, 1, -1, -1, 2, 2, -2, -2};
    int dy[]{2, -2, -2, 2, 1, -1, -1, 1};

    auto Check = [&](int i, int j) {
        return 0 <= i && i < 8 && 0 <= j && j < 8 && !grid[i][j];
    };

    auto Deg = [&](int i, int j) {
        int cnt = 0;

        if (!Check(i, j)) {
            return INF;
        }

        for (int k = 0; k < 8; ++k) {
            int u = dx[k] + i, v = dy[k] + j;

            cnt += Check(u, v);
        }

        return cnt;
    };

    for (int move = 2; move <= 64; ++move) {
        int mn = 10, idx = -1;

        for (int k = 0; k < 8; ++k) {
            int i = dx[k] + x, j = dy[k] + y;
            
            int d = Deg(i, j);
            if (d < mn) {
                mn = d;
                idx = k;
            }
        }

        assert(idx != -1);

        x += dx[idx], y += dy[idx];

        grid[x][y] = move;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << grid[i][j] << " \n"[j == 7];
        }
    }

    return 0;
}
