/**
 *    author:  feev1x
 *    created: 10.02.2025 09:52:42
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("multimoo.in", "r", stdin);
    std::freopen("multimoo.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<bool>> used(n + 1, std::vector<bool>(n + 1));
    std::vector<std::vector<bool>> used1(n + 1, std::vector<bool>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }

    auto Check = [&](int i, int j) {
        return 1 <= i && i <= n && 1 <= j && j <= n;
    };

    int dx[]{-1, 1, 0, 0};
    int dy[]{0, 0, -1, 1};

    std::map<int, std::map<int, int>> e;

    int _sz = 0;

    std::map<int, std::map<int, std::map<int, std::map<int, bool>>>> mp;

    int A, B;
    std::vector<std::pair<int, int>> ar;
    std::vector<int> st;
    auto Dfs = [&](auto &&self, int i, int j) -> void {
        used[i][j] = true;
        _sz++;

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (Check(x, y) && !used[x][y] && a[x][y] == a[i][j]) {
                self(self, x, y);
            } else if (Check(x, y) && a[x][y] != a[i][j]) {
                st.emplace_back(a[x][y]);
            }
        }
    };

    auto Dfs1 = [&](auto &&self, int i, int j) -> void {
        used1[i][j] = true;
        mp[A][B][i][j] = true;
        ar.emplace_back(i, j);

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (Check(x, y) && !used1[x][y] && (a[x][y] == A || a[x][y] == B)) {
                self(self, x, y);
            }
        }
    };
    
    int res = 0, res1 = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (used[i][j]) {
                continue;
            }

            _sz = 0;

            Dfs(Dfs, i, j);

            res = std::max(res, _sz);

            ar.clear();

            for (auto u: st) {
                A = a[i][j], B = u;

                if (mp[A][B][i][j]) {
                    continue;
                }

                Dfs1(Dfs1, i, j);

                for (auto [x, y]: ar) {
                    used1[x][y] = false;
                }

                res1 = std::max(res1, (int)ar.size());

                ar.clear();
            }

            st.clear();
        }
    }
    
    std::cout << res << '\n' << res1 << '\n';
    return 0;
}
