#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n, cnt;

    Dsu(int n) : n(n) {
        sz.assign(n, 1);
        p.resize(n);

        cnt = n;
        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            sz[v] += sz[u];
            p[u] = v;
            cnt--;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};
    std::array<std::array<std::array<bool, 4>, 200>, 200> can;
    std::array<std::array<bool, 200>, 200> used;
    for (auto &u: used) {
        for (auto &v: u) {
            v = false;
        }
    }

    for (auto &u: can) {
        for (auto &v: u) {
            for (auto &w: v) {
                w = true;
            }
        }
    }

    Dsu d(199 * 200 + 200);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            for (int j = std::min(y1, y2); j < std::max(y1, y2); ++j) {
                if (x1) {
                    can[x1 - 1][j][0] = false;
                }

                if (x1 < 200) {
                    can[x1][j][1] = false;
                }
            }
        } else {
            for (int j = std::min(x1, x2); j < std::max(x1, x2); ++j) {
                if (y1) {
                    can[j][y1 - 1][2] = false;
                }

                if (y1 < 200) {
                    can[j][y1][3] = false;
                }
            }
        }
    }

    auto Dfs = [&](auto &&self, int i, int j) -> void {
        used[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + i, y = dy[k] + j;

            if (can[i][j][k] && x >= 0 && x < 200 && y >= 0 && y < 200 && !used[x][y]) {
                d.unite(i * 200 + j, x * 200 + y);
                self(self, x, y);
            }
        }
    };

    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            if (!used[i][j]) {
                Dfs(Dfs, i, j);
            }
        }
    }

    std::cout << d.cnt << '\n';
    return 0;
}
