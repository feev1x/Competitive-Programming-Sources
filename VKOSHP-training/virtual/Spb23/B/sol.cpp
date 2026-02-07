/**
 *    author:  feev1x
 *    created: 14.11.2025 10:20:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<std::string, 10> s;

    for (auto &u: s)
        std::cin >> u;

    int n = 10, cnt[5] = {0, 0, 0, 0, 0};

    int dxv[]{0, 0, -1, -1, 1, 1};
    int dyv[]{1, -1, 1, -1, 1, -1};

    int dyh[]{0, 0, -1, -1, 1, 1};
    int dxh[]{1, -1, 1, -1, 1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '.' || j && s[i][j - 1] == '#' || i && s[i - 1][j] == '#')
                continue;

            int sz = 0;
            if (j + 1 < n && s[i][j + 1] == '#') {
                int x = i, y = j;
                
                while (x < n && y < n && s[x][y] == '#') {
                    for (int k = 0; k < 6; ++k) {
                        int X = x + dxh[k], Y = y + dyh[k];

                        if (X >= 0 && X < n && Y >= 0 && Y < n && s[X][Y] == '#') {
                            std::cout << "NO\n";
                            exit(0);
                        }
                    }

                    sz++;
                    y++;
                }


                if (sz > 4) {
                    std::cout << "NO\n";
                    exit(0);
                }

                cnt[sz]++;
            } else if (i + 1 < n && s[i + 1][j] == '#') {
                int x = i, y = j;
                
                while (x < n && y < n && s[x][y] == '#') {
                    for (int k = 0; k < 6; ++k) {
                        int X = x + dxv[k], Y = y + dyv[k];

                        if (X >= 0 && X < n && Y >= 0 && Y < n && s[X][Y] == '#') {
                            std::cout << "NO\n";
                            exit(0);
                        }
                    }

                    sz++;
                    x++;
                }


                if (sz > 4) {
                    std::cout << "NO\n";
                    exit(0);
                }

                cnt[sz]++;
            } else {
                cnt[1]++;
            }
        }
    }

    std::cout << (cnt[1] == 4 && cnt[2] == 3 && cnt[3] == 2 && cnt[4] == 1 ? "YES\n" : "NO\n");
    return 0;
}
